#include "gpio.h"

bool write_gpio_pin_config_to_port_config(GPIO_Pins pin, GPIO_Pin_IO_Mode pin_cfg, GPIO_Port_Config *config)
/*
    Write pin-configuration to port configuration.
    Needs to be done before port configuration is written into adress space.
    pin: pin x of port cfg (see GPIO_Pins)
    pin_cfg: configuration of pin x (see GPIO_Pin_IO_Mode)
    *config: struct of config to write to
    return: true of valid values have been provided. Else: false
*/
{
    uint8_t pin_cfg_bit_position = (pin << 2); // Multiply by 4 to get to correct position
    uint8_t shift_width = 0;
    uint32_t bit_mask = 0;
    // only allow correct values
    if ((pin_cfg_bit_position == 0) || ((pin_cfg_bit_position % GPIO_CRL_PIN_CFG_SIZE) == 0))
    {
        // write cfg to CRL without changing other pin configs
        if (pin_cfg_bit_position <= (GPIO_CRL_REGISTER_SIZE - GPIO_CRL_PIN_CFG_SIZE))
        {
            shift_width = pin * GPIO_CRL_PIN_CFG_SIZE;
            bit_mask = (0b1111 << shift_width);
            config->port_config_crl = (config->port_config_crl & (~bit_mask)) | (pin_cfg << shift_width);
        }
        // write cfg to CRH without changing other pin configs
        else
        {
            shift_width = (pin * GPIO_CRL_PIN_CFG_SIZE) - (GPIO_CRL_REGISTER_SIZE / GPIO_CRL_PIN_CFG_SIZE * GPIO_CRL_PIN_CFG_SIZE);
            bit_mask = (0b1111 << shift_width);
            config->port_config_crh = (config->port_config_crh & (~bit_mask)) | (pin_cfg << shift_width);
        }
    }
    else
    {
        return false;
    }
}

uint32_t map_gpio_port_to_address(GPIO_Port_Names port)
/*
    Calculate address of given port and return it.
    port: Given port (see GPIO_Port_Names)
    return: Address
*/
{
    uint32_t port_address = 0;
    switch (port)
    {
        case GPIO_PORT_A:
        {
            return OFFSET_PERIPHERALS + OFFSET_GPIO_PORT_A;
            break;
        }

        case GPIO_PORT_B:
        {
            return OFFSET_PERIPHERALS + OFFSET_GPIO_PORT_B;
            break;
        }

        case GPIO_PORT_C:
        {
            return OFFSET_PERIPHERALS + OFFSET_GPIO_PORT_C;
            break;
        }

        case GPIO_PORT_D:
        {
            return OFFSET_PERIPHERALS + OFFSET_GPIO_PORT_D;
            break;
        }

        default:
        {
            return 0xFFFFFFFF;
            break;
        }
    }
}

GPIO_Port_Config read_gpio_port_config_to_struct(GPIO_Port_Names port)
/*
    Read port config from address space.
    port: Given port (see GPIO_Port_Names)
    return: Read port config
*/
{
    GPIO_Port_Config port_config = {0};
    uint32_t read_address_start = map_gpio_port_to_address(port);
    port_config.port_config_crl = read_uint32_from_address_space(read_address_start);
    port_config.port_config_crh = read_uint32_from_address_space(read_address_start + OFFSET_GPIO_CRH);
    port_config.port_data_idr = read_uint32_from_address_space(read_address_start + OFFSET_GPIO_IDR);
    port_config.port_data_odr = read_uint32_from_address_space(read_address_start + OFFSET_GPIO_ODR);
    port_config.port_set_reset_bsrr = read_uint32_from_address_space(read_address_start + OFFSET_GPIO_BSRR);
    port_config.port_reset_brr = read_uint32_from_address_space(read_address_start + OFFSET_GPIO_BRR);
    port_config.port_lock_lckr = read_uint32_from_address_space(read_address_start + OFFSET_GPIO_LOCK);

    return port_config;
}