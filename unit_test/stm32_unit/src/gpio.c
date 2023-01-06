#include "gpio.h"

uint32_t gpio_map_port_to_address(GPIO_Port_Names port)
/*
    Calculate address of given port and return it.
    port: Given port (see GPIO_Port_Names)
    return: Address
*/
{
    switch (port)
    {
        case GPIO_PORT_A:
        {
            return OFFSET_GPIO_PORT_A;
            break;
        }

        case GPIO_PORT_B:
        {
            return OFFSET_GPIO_PORT_B;
            break;
        }

        case GPIO_PORT_C:
        {
            return OFFSET_GPIO_PORT_C;
            break;
        }

        case GPIO_PORT_D:
        {
            return OFFSET_GPIO_PORT_D;
            break;
        }

        default:
        {
            return 0xFFFFFFFF;
            break;
        }
    }
}

GPIO_Port_Config gpio_read_port_config_to_struct(GPIO_Port_Names port)
/*
    Read port config from address space.
    port: Given port (see GPIO_Port_Names)
    return: Read port config
*/
{
    GPIO_Port_Config port_config = {0};
    uint32_t read_address_start = gpio_map_port_to_address(port);
    port_config.port_config_crl = general_read_uint32_from_address_space(read_address_start);
    port_config.port_config_crh = general_read_uint32_from_address_space(read_address_start + OFFSET_GPIO_CRH);
    port_config.port_data_idr = general_read_uint32_from_address_space(read_address_start + OFFSET_GPIO_IDR);
    port_config.port_data_odr = general_read_uint32_from_address_space(read_address_start + OFFSET_GPIO_ODR);
    port_config.port_set_reset_bsrr = general_read_uint32_from_address_space(read_address_start + OFFSET_GPIO_BSRR);
    port_config.port_reset_brr = general_read_uint32_from_address_space(read_address_start + OFFSET_GPIO_BRR);
    port_config.port_lock_lckr = general_read_uint32_from_address_space(read_address_start + OFFSET_GPIO_LOCK);

    return port_config;
}

bool gpio_write_pin_status_to_config(GPIO_Pins pin, GPIO_Pin_State state, GPIO_Port_Config *config)
/*
    Set or reset pin.
    pin: pin x of port cfg (see GPIO_Pins)
    port: Given port (see GPIO_Port_Names)
    state: state of pin x (see GPIO_Pin_State)
    return: Read port config
*/
{
    uint8_t shift_width = 0;
    uint32_t bit_mask = 0;
    // set registers: 0 - 15 = pin 0 - 15
    if (state == GPIO_PIN_SET)
    {
        shift_width = pin;
        bit_mask = (0b1 << shift_width);
        config->port_set_reset_bsrr = (config->port_set_reset_bsrr & (~bit_mask)) | (pin << shift_width);
    }
    // reset registers: 16 - 31 = pin 0 - 15
    else if (state == GPIO_PIN_RESET)
    {
        shift_width = pin + 16;
        bit_mask = (0b1 << shift_width);
        config->port_set_reset_bsrr = (config->port_set_reset_bsrr & (~bit_mask)) | (pin << shift_width);
    }
    else
    {
        return false;
    }
    return true;
}

bool gpio_write_port_config_to_register(GPIO_Port_Names port, GPIO_Port_Config *config)
/*
    !!Read port first before using this function.
    Otherwise it might lead to undesired configurations!!
    Writes port config from struct to registers.
    Validates write process by reading after writing.
    port: Given port (see GPIO_Port_Names)
    *config: struct of config to write to
    return: true, if writing successful
*/
{
    uint32_t write_address_start = gpio_map_port_to_address(port);

    general_write_uint32_to_address_space(write_address_start, config->port_config_crl);
    general_write_uint32_to_address_space(write_address_start + OFFSET_GPIO_CRH, config->port_config_crh);
    general_write_uint32_to_address_space(write_address_start + OFFSET_GPIO_IDR, config->port_data_idr);
    general_write_uint32_to_address_space(write_address_start + OFFSET_GPIO_ODR, config->port_data_odr);
    general_write_uint32_to_address_space(write_address_start + OFFSET_GPIO_BSRR, config->port_set_reset_bsrr);
    general_write_uint32_to_address_space(write_address_start + OFFSET_GPIO_BRR, config->port_reset_brr);
    general_write_uint32_to_address_space(write_address_start + OFFSET_GPIO_LOCK, config->port_lock_lckr);
    return gpio_compare_write_cfg_with_read_cfg(config, port);
}

bool gpio_compare_write_cfg_with_read_cfg(GPIO_Port_Config *write_cfg, GPIO_Port_Names port)
/*
    Compares struct with values in register.
    *write_cfg: struct of config to compare
    port: Given port (see GPIO_Port_Names)
*/
{
    bool ret_val = false;
    GPIO_Port_Config read_config = gpio_read_port_config_to_struct(port);
    if (read_config.port_config_crl != write_cfg->port_config_crl)
    {
        ret_val = false;
    }
    else if (read_config.port_config_crh != write_cfg->port_config_crh)
    {
        ret_val = false;
    }
    else if (read_config.port_data_idr != write_cfg->port_data_idr)
    {
        ret_val = false;
    }
    else if (read_config.port_data_odr != write_cfg->port_data_odr)
    {
        ret_val = false;
    }
    else if (read_config.port_set_reset_bsrr != write_cfg->port_set_reset_bsrr)
    {
        ret_val = false;
    }
    else if (read_config.port_reset_brr != write_cfg->port_reset_brr)
    {
        ret_val = false;
    }
    else if (read_config.port_lock_lckr != write_cfg->port_lock_lckr)
    {
        ret_val = false;
    }
    else
    {
        ret_val = true;
    }

    return ret_val;
}

bool gpio_write_pin_config_to_register(GPIO_Pins pin, GPIO_Port_Names port, GPIO_Pin_IO_Mode pin_cfg)
/*
    Write pin-configuration to current config and rewrite config to address space
    pin: pin x of port cfg (see GPIO_Pins)
    pin_cfg: configuration of pin x (see GPIO_Pin_IO_Mode)
    return: true of valid values have been provided. Else: false
*/
{
    uint8_t pin_cfg_bit_position = (pin << 2); // Multiply by 4 to get to correct position
    uint8_t shift_width = 0;
    uint32_t bit_mask = 0b1111;
    GPIO_Port_Config config = {0};
    // only allow correct values
    if ((pin_cfg_bit_position == 0) || ((pin_cfg_bit_position % GPIO_CRL_PIN_CFG_SIZE) == 0))
    {
        config = gpio_read_port_config_to_struct(port);
        // write cfg to CRL without changing other pin configs
        if (pin_cfg_bit_position <= (GPIO_CRL_REGISTER_SIZE - GPIO_CRL_PIN_CFG_SIZE))
        {
            shift_width = pin * GPIO_CRL_PIN_CFG_SIZE;
            // bit_mask = (0b1111 << shift_width);
            // config.port_config_crl = (config.port_config_crl & (~bit_mask)) | (pin_cfg << shift_width);
            config.port_config_crl = general_apply_bitmask_to_uint32_t(config.port_config_crl, pin_cfg, bit_mask, shift_width);
        }
        // write cfg to CRH without changing other pin configs
        else
        {
            shift_width = (pin * GPIO_CRL_PIN_CFG_SIZE) - GPIO_CRL_REGISTER_SIZE;
            // bit_mask = (0b1111 << shift_width);
            // config.port_config_crh = (config.port_config_crh & (~bit_mask)) | (pin_cfg << shift_width);
            config.port_config_crh = general_apply_bitmask_to_uint32_t(config.port_config_crh, pin_cfg, bit_mask, shift_width);
        }
        return gpio_write_port_config_to_register(port, &config);
    }
    else
    {
        return false;
    }
}