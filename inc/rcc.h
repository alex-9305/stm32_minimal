#ifndef RCC_H
#define RCC_H

#include "general_functions.h"

#define OFFSET_RCC (OFFSET_PERIPHERALS + 0x21000)

#define OFFSET_RCC_CR 0x00
#define OFFSET_RCC_CFGR 0x04
#define OFFSET_RCC_CIR 0x08
#define OFFSET_RCC_APB2RSTR 0x0C
#define OFFSET_RCC_APB1RSTR 0x10
#define OFFSET_RCC_AHBENR 0x14
#define OFFSET_RCC_APB2ENR 0x18
#define OFFSET_RCC_APB1ENR 0x1C
#define OFFSET_RCC_BDCR 0x20
#define OFFSET_RCC_CSR 0x24

typedef enum
{
    RCC_Disable = 0u,
    RCC_Enable
} RCC_Enable_Disable;

typedef enum
{
    RCC_GPIO_PORT_A = 0u,
    RCC_GPIO_PORT_B,
    RCC_GPIO_PORT_C,
    RCC_GPIO_PORT_D
} RCC_GPIO_Peripherals;

typedef struct
{
    uint32_t rcc_cr; // clock control
    uint32_t rcc_cfgr; // clock config register
    uint32_t rcc_cir; // clock interrupt register
    uint32_t rcc_apb2rstr; // apb2 periph reset register
    uint32_t rcc_apb1rstr; // apb1 periph reset register
    uint32_t rcc_ahbenr; // ahb periph clock enable register
    uint32_t rcc_apb2enr; // apb2 periph clock enable register
    uint32_t rcc_apb1enr; // apb1 periph clock enable register
    uint32_t rcc_bdcr; // backup domain control register
    uint32_t rcc_csr; // control/status register
} RCC_Config;

void rcc_write_gpio_status_to_config(RCC_Config *config, RCC_GPIO_Peripherals peripheral, RCC_Enable_Disable status);
uint8_t rcc_get_gpio_bit_enable_position(RCC_GPIO_Peripherals peripheral);


#endif // RCC_H