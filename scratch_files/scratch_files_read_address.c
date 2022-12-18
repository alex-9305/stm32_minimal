#include "general_functions.h"
#include "gpio.h"
#include <stdio.h>

uint32_t read_uint32_from_address_space(uint32_t address)
/*
    Reads next 32bit from designated address.
    address: designated address
    return: read data
*/
{
    // TODO: DEFINE READABLE SPACE
    const uint32_t *read_data = (const uint32_t *)address;
    return *read_data;
}

int main(void)
{
    uint32_t test_address = 0;
    test_address = read_uint32_from_address_space(0x0150);
    printf("Test 1: Return = %d\n", test_address);
    return 0;
}