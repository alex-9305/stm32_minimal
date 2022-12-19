#include "main.h"
/* Main program. */
// TODO: ASSERTS FÜR FUNKTIONEN FÜR EXC HANDLING

// TODO: ZUNÄCHST AKTUELLE WERTE ABFRAGEN IN STRUCTS, BEVOR GESCHRIEBEN WIRD!
static GPIO_Port_Config gpio_port_a = {0};
static GPIO_Port_Config gpio_port_b = {0};
static GPIO_Port_Config gpio_port_c = {0};
static GPIO_Port_Config gpio_port_d = {0};
static RCC_Config rcc_cfg = {0};

int main(void)
{
    rcc_write_gpio_status_to_config(&rcc_cfg, RCC_GPIO_PORT_A, RCC_Enable);
    bool rcc_written = rcc_write_gpio_config_to_registers(&rcc_cfg);
    gpio_port_a = gpio_read_port_config_to_struct(GPIO_PORT_A);
    gpio_port_b = gpio_read_port_config_to_struct(GPIO_PORT_B);
    gpio_port_c = gpio_read_port_config_to_struct(GPIO_PORT_C);
    gpio_port_d = gpio_read_port_config_to_struct(GPIO_PORT_D);

    int val = 0;
    while (1)
    {
        val += 1;
    }
}