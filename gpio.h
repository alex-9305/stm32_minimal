#ifndef GPIO_H
#define GPIO_H

#include "general_includes.h"

/* Defines */
#define OFFSET_GPIO_PORT_A 0x40010800
#define OFFSET_GPIO_PORT_B 0x40010C00
#define OFFSET_GPIO_PORT_C 0x40011000
#define OFFSET_GPIO_PORT_D 0x40011400

#define OFFSET_GPIO_CRL 0x00
#define OFFSET_GPIO_CRH 0x04
#define OFFSET_GPIO_IDR 0x08
#define OFFSET_GPIO_ODR 0x0C
#define OFFSET_GPIO_BSRR 0x10
#define OFFSET_GPIO_BRR 0x14
#define OFFSET_GPIO_LOCK 0x18

typedef enum
{
    GPIO_PIN_RESET = 0u,
    GPIO_PIN_SET
} GPIO_Pin_State;

typedef enum
{
    // CNFX1, CNFX0, MODEX1, MODEX0, where x is pin of port
    IO_IN_FLOATING = 0b0100,
    IO_IN_PULL_UP_DOWN = 0b1000,
    IO_IN_ANALOG = 0b0000,
    IO_OUT_PUSH_PULL = 0b0010,  // standard: 2MHz output
    IO_OUT_OPEN_DRAIN = 0b0110, // standard: 2MHz output
    IO_AF_PUSH_PULL = 0b1010,   // standard: 2MHz output
    IO_AF_OPEN_DRAIN = 0b1110     // standard: 2MHz output
} GPIO_IO_Mode;

typedef enum
{
    GPIO_PORT_A = 0u,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,
    GPIO_PORT_G
} GPIO_Port_Names;

typedef enum
{
    GPIO_PIN_0 = 0u,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
} GPIO_Pins;

typedef struct
{
    uint32_t port_config_crl;    // lower config register
    uint32_t port_config_crh;    // higher config register
    uint32_t port_data_idr;    // lower data register
    uint32_t port_data_odr;    // higher data register
    uint32_t port_set_reset_bsrr;    // set/reset register
    uint16_t port_reset_brr;    // reset register
    uint32_t port_lock_lckr;    // locking register
} GPIO_Port_Config;

/* Functions */

bool write_gpio_port_configuration(GPIO_Port_Names port, GPIO_Port_Config config); //Check after written: True or False
bool write_gpio_pin_configuration(GPIO_Port_Names port, GPIO_Pins pin, GPIO_Port_Config config); //Check after written: True or False
uint32_t read_gpio_port_configuration(GPIO_Port_Names port);
uint32_t map_gpio_port_to_address_offset(GPIO_Port_Names port);



#endif //GPIO_H