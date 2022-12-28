#include "main.h"
/* Main program. */
// TODO: ASSERTS FÜR FUNKTIONEN FÜR EXC HANDLING
// Umbau: Pin Status direkt per Speicherzugriff umändern. Da nur 32 bit Zugriff: Erst lesen, dann bit ändern,
// Dann schreiben, dann prüfen

static GPIO_Port_Config gpio_port_c = {0};
static RCC_Config rcc_cfg = {0};

int main(void)
{
    rcc_write_gpio_status_to_config(&rcc_cfg, RCC_GPIO_PORT_C, RCC_Enable);
    bool rcc_written = rcc_write_gpio_config_to_registers(&rcc_cfg);
    gpio_port_c = gpio_read_port_config_to_struct(GPIO_PORT_C);
    bool cfg_written = gpio_write_pin_config_to_register(GPIO_PIN_13, GPIO_PORT_C, IO_OUT_PUSH_PULL);
    cfg_written = gpio_write_pin_status_to_config(GPIO_PIN_13, GPIO_PIN_SET, &gpio_port_c);
    gpio_port_c = gpio_read_port_config_to_struct(GPIO_PORT_C);

    int val = 0;
    while (1)
    {
        val += 1;
    }
}