#ifdef TEST

#include "unity.h"

#include "gpio.h"

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
    TEST_ASSERT_EQUAL_UINT32(OFFSET_GPIO_PORT_A, result);
    result = gpio_map_port_to_address(GPIO_PORT_B);
    TEST_ASSERT_EQUAL_UINT32(OFFSET_GPIO_PORT_B, result);
    result = gpio_map_port_to_address(GPIO_PORT_C);
    TEST_ASSERT_EQUAL_UINT32(OFFSET_GPIO_PORT_C, result);
    result = gpio_map_port_to_address(GPIO_PORT_D);
    TEST_ASSERT_EQUAL_UINT32(OFFSET_GPIO_PORT_D, result);
    // result = gpio_map_port_to_address(4);
    // TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF, result);
    // result = gpio_map_port_to_address(37);
    // TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF, result);
    // result = gpio_map_port_to_address(-2);
    // TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF, result);
}

#endif // TEST
