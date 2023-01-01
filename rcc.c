#include "rcc.h"

void rcc_write_gpio_status_to_config(RCC_Config *config, RCC_GPIO_Peripherals peripheral, RCC_Enable_Disable status)
/*
    Write clock config of gpio to struct.
    Needs to be done before clock configuration is written into adress space.
    *config: struct of config to write to
    peripheral: GPIO peripheral (see RCC_GPIO_Peripherals)
    status: enable clock or disable
    return: true of valid values have been provided. Else: false
*/
{
    uint8_t bit_position = rcc_get_gpio_bit_enable_position(peripheral);
    uint32_t bit_mask = (1 << bit_position);
    config->rcc_apb2enr = ((config->rcc_apb2enr & (~bit_mask)) | (status << bit_position));
}


uint8_t rcc_get_gpio_bit_enable_position(RCC_GPIO_Peripherals peripheral)
/*
    Get position of gpio peripheral enable bit in apb2 enable register
    peripheral: GPIO peripheral (see RCC_GPIO_Peripherals)
    return: bit position (0-31)
*/
{
    switch (peripheral)
    {
        case (RCC_GPIO_PORT_A):
        {
            return 2u;
            break;
        }
        case (RCC_GPIO_PORT_B):
        {
            return 3u;
            break;
        }
        case (RCC_GPIO_PORT_C):
        {
            return 4u;
            break;
        }
        case (RCC_GPIO_PORT_D):
        {
            return 5u;
            break;
        }
        default:
        {
            return 0xFF;
            break;
        }
    }
}

uint32_t rcc_map_ahb_clk_status_to_address(RCC_Enable_Registers periph)
/*
    Calculate address of given peripheral and return it.
    periph: Periph to map to (see RCC_Enable_Registers)
    return: RCC ahb address
*/
{
    return (OFFSET_RCC + OFFSET_RCC_AHBENR + periph);
}

uint32_t rcc_map_apb2_clk_status_to_address(RCC_Enable_Registers periph)
/*
    Calculate address of given peripheral and return it.
    periph: Periph to map to (see RCC_Enable_Registers)
    return: RCC apb2 address
*/
{
    return (OFFSET_RCC + OFFSET_RCC_APB2ENR + (periph - RCC_AHB_PERIPH_AMOUNT));
}

uint32_t rcc_map_apb1_clk_status_to_address(RCC_Enable_Registers periph)
/*
    Calculate address of given peripheral and return it.
    periph: Periph to map to (see RCC_Enable_Registers)
    return: RCC apb1 address
*/
{
    return (OFFSET_RCC + OFFSET_RCC_APB1ENR + (periph - RCC_AHB_PERIPH_AMOUNT - RCC_APB2_PERIPH_AMOUNT));
}

uint32_t rcc_map_clk_status_to_address(RCC_Enable_Registers periph)
/*
    Calculate address of given peripheral and return it.
    periph: Periph to map to (see RCC_Enable_Registers)
    return: RCC address
*/
{
    uint32_t address = 0;
    if (periph < (RCC_AHB_PERIPH_AMOUNT))
    {
        address = rcc_map_ahb_clk_status_to_address(periph);
    }
    else if ((periph >= (RCC_AHB_PERIPH_AMOUNT)) && (periph < (RCC_AHB_PERIPH_AMOUNT + RCC_APB2_PERIPH_AMOUNT)))
    {
        address = rcc_map_apb2_clk_status_to_address(periph);
    }
    else if ((periph >= (RCC_AHB_PERIPH_AMOUNT + RCC_APB2_PERIPH_AMOUNT)) && (periph < (RCC_AHB_PERIPH_AMOUNT + RCC_APB2_PERIPH_AMOUNT + RCC_APB1_PERIPH_AMOUNT)))
    {
        address = rcc_map_apb1_clk_status_to_address(periph);
    }
    else
    {
        address = 0xFFFFFFFF;
    }
    return address;
}

RCC_Config rcc_read_config_to_struct(void)
/*
    Read current rcc config from mcu and return as struct
    return: struct
*/
{
    RCC_Config config = {0};
    uint32_t read_address_start = OFFSET_RCC;
    config.rcc_cr = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_CR);
    config.rcc_cfgr = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_CFGR);
    config.rcc_cir = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_CIR);
    config.rcc_apb2rstr = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_APB2RSTR);
    config.rcc_apb1rstr = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_APB1RSTR);
    config.rcc_ahbenr = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_AHBENR);
    config.rcc_apb2enr = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_APB2ENR);
    config.rcc_apb1enr = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_APB1ENR);
    config.rcc_bdcr = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_BDCR);
    config.rcc_csr = general_read_uint32_from_address_space(read_address_start + OFFSET_RCC_CSR);

    return config;
}

bool rcc_set_clk_for_periph(RCC_Enable_Registers periph, RCC_Enable_Disable status)
/*
    Set status of periph register
    periph: Peripheral (see RCC_Enable_Registers)
    status: Enable or disable (see RCC_Enable_Disable)
    return: true, if successful
*/
{

    uint32_t rcc_periph_address = rcc_map_clk_status_to_address(periph);
    RCC_Config config = rcc_read_config_to_struct();
    // TODO: bit in cfg schreiben, bit in addressraum schreiben, beide vergleichen


}

bool rcc_write_gpio_config_to_registers(RCC_Config *config)
{
    uint32_t write_data = config->rcc_apb2enr;
    uint32_t *write_pointer = (uint32_t *)(OFFSET_RCC + OFFSET_RCC_APB2ENR);
    *write_pointer = write_data;

    if (*write_pointer == config->rcc_apb2enr)
    {
        return true;
    }
    else
    {
        return false;
    }
}