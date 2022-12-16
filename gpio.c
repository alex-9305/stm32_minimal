#include "gpio.h"

bool write_gpio_pin_config_to_port_config(GPIO_Pins pin, GPIO_Pin_IO_Mode pin_cfg, GPIO_Port_Config *config)
{
    uint8_t pin_cfg_bit_position = (pin << 2); // Multiply by 4 to get to correct position
    uint8_t shift_width = 0;
    // only allow correct values
    if ((pin_cfg_bit_position == 0) || ((pin_cfg_bit_position % GPIO_CRL_PIN_CFG_SIZE) == 0))
    {
        // write cfg to CRL without changing other pin configs
        if (pin_cfg_bit_position <= (GPIO_CRL_REGISTER_SIZE - GPIO_CRL_PIN_CFG_SIZE))
        {
            shift_width = pin * GPIO_CRL_PIN_CFG_SIZE;
            config->port_config_crl = (config->port_config_crl | (pin_cfg << shift_width));
        }
        // write cfg to CRH without changing other pin configs
        else
        {
            shift_width = (pin * GPIO_CRL_PIN_CFG_SIZE) - (GPIO_CRL_REGISTER_SIZE / GPIO_CRL_PIN_CFG_SIZE * GPIO_CRL_PIN_CFG_SIZE);
            config->port_config_crh = (config->port_config_crh | (pin_cfg << shift_width)); // substract nb. of pins in register size
        }
    }
    else
    {
        return false;
    }
}