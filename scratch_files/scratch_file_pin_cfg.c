#include "general_functions.h"
#include "gpio.h"
#include <stdio.h>

static bool _write_gpio_pin_config_to_port_config(GPIO_Pins pin, GPIO_Pin_IO_Mode pin_cfg, GPIO_Port_Config *config)
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

int main(void)
{   GPIO_Port_Config gpio_test_cfg = {0};
    bool test_return = false;
    test_return = _write_gpio_pin_config_to_port_config(GPIO_PIN_0, IO_IN_PULL_UP_DOWN, &gpio_test_cfg);
    printf("Test 1: Return = %s, struct_crl = %d, struct_crh = %d\n", test_return?"true":"false", gpio_test_cfg.port_config_crl, gpio_test_cfg.port_config_crh);
    test_return = _write_gpio_pin_config_to_port_config(GPIO_PIN_7, IO_OUT_PUSH_PULL, &gpio_test_cfg);
    printf("Test 2: Return = %s, struct_crl = %d, struct_crh = %d\n", test_return?"true":"false", gpio_test_cfg.port_config_crl, gpio_test_cfg.port_config_crh);
    test_return = _write_gpio_pin_config_to_port_config(GPIO_PIN_14, IO_AF_OPEN_DRAIN, &gpio_test_cfg);
    printf("Test 3: Return = %s, struct_crl = %d, struct_crh = %d\n", test_return?"true":"false", gpio_test_cfg.port_config_crl, gpio_test_cfg.port_config_crh);
    test_return = _write_gpio_pin_config_to_port_config(GPIO_PIN_1, IO_IN_PULL_UP_DOWN, &gpio_test_cfg);
    printf("Test 4: Return = %s, struct_crl = %d, struct_crh = %d\n", test_return?"true":"false", gpio_test_cfg.port_config_crl, gpio_test_cfg.port_config_crh);
    test_return = _write_gpio_pin_config_to_port_config(GPIO_PIN_10, IO_AF_OPEN_DRAIN, &gpio_test_cfg);
    printf("Test 5: Return = %s, struct_crl = %d, struct_crh = %d\n", test_return?"true":"false", gpio_test_cfg.port_config_crl, gpio_test_cfg.port_config_crh);
    test_return = _write_gpio_pin_config_to_port_config(GPIO_PIN_0, IO_OUT_OPEN_DRAIN, &gpio_test_cfg);
    printf("Test 6: Return = %s, struct_crl = %d, struct_crh = %d\n", test_return?"true":"false", gpio_test_cfg.port_config_crl, gpio_test_cfg.port_config_crh);
    test_return = _write_gpio_pin_config_to_port_config(GPIO_PIN_14, IO_IN_PULL_UP_DOWN, &gpio_test_cfg);
    printf("Test 7: Return = %s, struct_crl = %d, struct_crh = %d\n", test_return?"true":"false", gpio_test_cfg.port_config_crl, gpio_test_cfg.port_config_crh);
    return 0;
}