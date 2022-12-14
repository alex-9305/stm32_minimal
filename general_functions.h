#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H
#include <stdint.h>
#include <stdbool.h>

#define OFFSET_PERIPHERALS 0x40000000

uint32_t general_read_uint32_from_address_space(uint32_t address);
uint16_t general_read_uint16_from_address_space(uint32_t address);
void general_write_uint32_to_address_space(uint32_t address, uint32_t value);
uint32_t general_apply_bitmask_to_uint32_t(uint32_t overwrite_data, uint32_t input_data, uint32_t bit_mask, uint8_t shift_width);

#endif // GENERAL_FUNCTIONS_H