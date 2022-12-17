#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H
#include <stdint.h>
#include <stdbool.h>

#define OFFSET_PERIPHERALS 0x40000000

uint32_t read_uint32_from_address_space(uint32_t address);
uint16_t read_uint16_from_address_space(uint32_t address);

#endif // GENERAL_FUNCTIONS_H