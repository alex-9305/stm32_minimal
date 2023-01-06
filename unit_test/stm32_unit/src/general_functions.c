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

uint32_t general_apply_bitmask_to_uint32_t(uint32_t overwrite_data, uint32_t input_data, uint32_t bit_mask, uint8_t shift_width)
/*
    Overwrites data in overwrite_data with input_data without changing other bits by bit operations
    overwrite_data: Data to apply bit operations to
    input_data: data to write into overwrite_data
    bitmask: bitmask for overwriting
    shift_width: shift-width for input-data and bitmask
*/
{
    uint32_t output_data = 0;
    uint32_t use_bit_mask = (bit_mask << shift_width);
    output_data = (overwrite_data & (~use_bit_mask)) | (input_data << shift_width);

    return output_data;
}