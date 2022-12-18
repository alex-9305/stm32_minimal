#include "general_functions.h"

uint16_t general_read_uint16_from_address_space(uint32_t address)
/*
    Reads next 16bit from designated address.
    address: designated address
    return: read data
*/
{
    // TODO: DEFINE READABLE SPACE
    uint16_t *read_data = address;
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
    uint32_t *read_data = address;
    return *read_data;
}