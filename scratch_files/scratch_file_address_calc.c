#include "general_functions.h"
#include "gpio.h"
#include <stdio.h>

static uint32_t _map_gpio_port_to_address(GPIO_Port_Names port)
/*
    Calculate address of given port and return it.
    port: Given port (see GPIO_Port_Namencls)
    return: Address
*/
{
    uint32_t port_address = 0;
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

int main(void)
{
    uint32_t test_address = 0;
    test_address = _map_gpio_port_to_address(GPIO_PORT_A);
    printf("Test 1: Return = %d\n", test_address);
    return 0;
}