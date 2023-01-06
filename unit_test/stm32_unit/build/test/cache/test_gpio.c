#include "src/gpio.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








void setUp(void)

{

}



void tearDown(void)

{

}



void test_gpio_map_port_to_address(void)

{

    uint32_t result;

    result = gpio_map_port_to_address(GPIO_PORT_A);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT32)(((0x40000000 + 0x10800))), (UNITY_INT)(UNITY_UINT32)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_UINT32);

    result = gpio_map_port_to_address(GPIO_PORT_B);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT32)(((0x40000000 + 0x10C00))), (UNITY_INT)(UNITY_UINT32)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_UINT32);

    result = gpio_map_port_to_address(GPIO_PORT_C);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT32)(((0x40000000 + 0x11000))), (UNITY_INT)(UNITY_UINT32)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_UINT32);

    result = gpio_map_port_to_address(GPIO_PORT_D);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT32)(((0x40000000 + 0x11400))), (UNITY_INT)(UNITY_UINT32)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_UINT32);













}
