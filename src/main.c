#include "main.h"
/* Main program. */
// TODO: ASSERTS FÜR FUNKTIONEN FÜR EXC HANDLING

// TODO: ZUNÄCHST AKTUELLE WERTE ABFRAGEN IN STRUCTS, BEVOR GESCHRIEBEN WIRD!
static GPIO_Port_Config gpio_port_a = {0};
int main(void)
{
    gpio_port_a = gpio_read_port_config_to_struct(GPIO_PORT_A);
    gpio_port_a = gpio_read_port_config_to_struct(GPIO_PORT_B);
    gpio_port_a = gpio_read_port_config_to_struct(GPIO_PORT_C);
    gpio_port_a = gpio_read_port_config_to_struct(GPIO_PORT_D);
    int val = 0;
    while (1)
    {
        val += 1;
    }
}