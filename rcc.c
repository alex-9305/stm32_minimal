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

bool rcc_write_gpio_config_to_registers(RCC_Config *config)
{
    uint32_t write_data = config->rcc_apb2enr;
    uint32_t *write_pointer = (uint32_t *)(OFFSET_RCC + OFFSET_RCC_APB2ENR);
    *write_pointer = write_data;

    // //RESET. REMOVE AFTER TEST
    // uint32_t write_reset = 4u;
    // uint32_t *write_reset_pointer = (uint32_t *)(OFFSET_RCC + OFFSET_RCC_APB2RSTR);
    // *write_reset_pointer = write_reset;

    if (*write_pointer == config->rcc_apb2enr)
    {
        return true;
    }
    else
    {
        return false;
    }
}