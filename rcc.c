#include "rcc.h"

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
    return (OFFSET_RCC + OFFSET_RCC_APB2ENR + (periph - RCC_APB2_PERIPH_OFFSET));
}

uint32_t rcc_map_apb1_clk_status_to_address(RCC_Enable_Registers periph)
/*
    Calculate address of given peripheral and return it.
    periph: Periph to map to (see RCC_Enable_Registers)
    return: RCC apb1 address
*/
{
    return (OFFSET_RCC + OFFSET_RCC_APB1ENR + (periph - RCC_APB1_PERIPH_OFFSET));
}

uint32_t rcc_map_clk_status_to_address(RCC_Enable_Registers periph)
/*
    Calculate address of given peripheral and return it.
    periph: Periph to map to (see RCC_Enable_Registers)
    return: RCC address
*/
{
    uint32_t address = 0;
    if (periph < (RCC_APB2_PERIPH_OFFSET))
    {
        address = rcc_map_ahb_clk_status_to_address(periph);
    }
    else if ((periph >= RCC_APB2_PERIPH_OFFSET) && (periph < RCC_APB1_PERIPH_OFFSET))
    {
        address = rcc_map_apb2_clk_status_to_address(periph);
    }
    else if ((periph >= RCC_APB1_PERIPH_OFFSET) && (periph < (RCC_APB1_PERIPH_OFFSET + RCC_CLK_SET_REGISTER_SIZE)))
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

bool rcc_write_clk_settings_to_register(RCC_Config *config, RCC_Enable_Registers periph, RCC_Enable_Disable status, uint32_t rcc_periph_address)
/*
    Check valid write address and write enable status intro struct
    *config: Config struct to write
    periph: RCC peripheral to activate/deactivate
    status: Enable or disable
    rcc_periph_address: address of the peripheral rcc enable/disable
    return: true, if successful
*/
{
    uint8_t bit_mask = 0b1;
    bool rcc_clk_set = false;
    uint32_t write_address = 0;
    uint32_t write_data = 0;
    uint32_t read_back_data = 0;

    // Check for valid address
    if ((rcc_periph_address >= (OFFSET_RCC + OFFSET_RCC_AHBENR)) && (rcc_periph_address < (OFFSET_RCC + OFFSET_RCC_APB2ENR)))
    {
        write_address = (OFFSET_RCC + OFFSET_RCC_AHBENR);
        config->rcc_ahbenr = general_apply_bitmask_to_uint32_t(config->rcc_ahbenr, status, bit_mask, periph);
        write_data = config->rcc_ahbenr;
    }
    else if ((rcc_periph_address >= (OFFSET_RCC + OFFSET_RCC_APB2ENR)) && (rcc_periph_address < (OFFSET_RCC + OFFSET_RCC_APB1ENR)))
    {
        write_address = (OFFSET_RCC + OFFSET_RCC_APB2ENR);
        config->rcc_apb2enr = general_apply_bitmask_to_uint32_t(config->rcc_apb2enr, status, bit_mask, (periph - RCC_APB2_PERIPH_OFFSET));
        write_data = config->rcc_apb2enr;
    }
    else if ((rcc_periph_address >= (OFFSET_RCC + OFFSET_RCC_APB1ENR)) && (rcc_periph_address < (OFFSET_RCC + OFFSET_RCC_BDCR)))
    {
        write_address = (OFFSET_RCC + OFFSET_RCC_APB1ENR);
        config->rcc_apb1enr = general_apply_bitmask_to_uint32_t(config->rcc_apb1enr, status, bit_mask, (periph - RCC_APB1_PERIPH_OFFSET));
        write_data = config->rcc_apb1enr;
    }
    else
    {
        return false;
    }
    // Write data and check if write successful
    general_write_uint32_to_address_space(write_address, write_data);
    read_back_data = general_read_uint32_from_address_space(write_address);
    if (write_data == read_back_data)
    {
        rcc_clk_set = true;
    }
    else
    {
        rcc_clk_set = false;
    }
    return rcc_clk_set;
}

bool rcc_set_clk_for_periph(RCC_Enable_Registers periph, RCC_Enable_Disable status)
/*
    Set status of periph register
    periph: Peripheral (see RCC_Enable_Registers)
    status: Enable or disable (see RCC_Enable_Disable)
    return: true, if successful
*/
{
    bool rcc_clk_set = false;
    uint32_t rcc_periph_address = rcc_map_clk_status_to_address(periph);
    RCC_Config config = rcc_read_config_to_struct();
    rcc_clk_set = rcc_write_clk_settings_to_register(&config, periph, status, rcc_periph_address);

    return rcc_clk_set;
}