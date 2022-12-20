#include "general_functions.h"

uint16_t general_read_uint16_from_address_space(uint32_t address)
/*
    Reads next 16bit from designated address.
    address: designated address
    return: read data
*/
{
    // TODO: DEFINE READABLE SPACE
    uint16_t *read_data = (uint16_t *)address;
    return *read_data;
}

uint32_t general_read_uint32_from_address_space(uint32_t address)
/*
    Reads next 32bit from designated address.
    address: designated address
    return: read data
*/
{
    // TODO: DEFINE READABLE SPACE
    uint32_t *read_data = (uint32_t *)address;
    return *read_data;
}

void general_write_uint32_to_address_space(uint32_t address, uint32_t value)
/*
    Writes 32bit to designated address.
    address: designated address
    value: value to write to address
*/
{
    // TODO: DEFINE READABLE SPACE
    uint32_t *pointer_to_data = (uint32_t *)address;
    *pointer_to_data = value;
}