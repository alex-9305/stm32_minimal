#include "main.h"
/* Main program. */
// TODO: ASSERTS FÜR FUNKTIONEN FÜR EXC HANDLING

// TODO: ZUNÄCHST AKTUELLE WERTE ABFRAGEN IN STRUCTS, BEVOR GESCHRIEBEN WIRD!
static GPIO_Port_Config gpio_port_c = {0};
static RCC_Config rcc_cfg = {0};

int main(void)
{
    rcc_write_gpio_status_to_config(&rcc_cfg, RCC_GPIO_PORT_C, RCC_Enable);
    bool rcc_written = rcc_write_gpio_config_to_registers(&rcc_cfg);
    gpio_port_c = gpio_read_port_config_to_struct(GPIO_PORT_C);
    bool cfg_written = gpio_write_pin_config_to_port_config(GPIO_PIN_13, IO_OUT_PUSH_PULL, &gpio_port_c);
    cfg_written = gpio_write_pin_status_to_config(GPIO_PIN_13, GPIO_PIN_SET, &gpio_port_c);
    gpio_write_port_config_to_register(GPIO_PORT_C, &gpio_port_c);

    int val = 0;
    while (1)
    {
        val += 1;
    }
}