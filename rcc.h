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
#define RCC_CLK_SET_REGISTER_SIZE 32u
#define RCC_AHB_PERIPH_OFFSET 0u
#define RCC_APB2_PERIPH_OFFSET 32u
#define RCC_APB1_PERIPH_OFFSET 64u

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

typedef enum
{
    RCC_Enable_DMA_1 = 0u,
    RCC_Enable_DMA_2,
    RCC_Enable_SRAM,
    RCC_Enable_FLITF = 4u,
    RCC_Enable_CRC = 6u,
    RCC_Enable_FSMC = 8u,
    RCC_Enable_SDIO = 10u,
    RCC_Enable_AFIO = 32u,
    RCC_Enable_IOPA = 34u,
    RCC_Enable_IOPB,
    RCC_Enable_IOPC,
    RCC_Enable_IOPD,
    RCC_Enable_IOPE,
    RCC_Enable_IOPF,
    RCC_Enable_IOPG,
    RCC_Enable_ADC_1,
    RCC_Enable_ADC_2,
    RCC_Enable_TIM_1,
    RCC_Enable_SPI_1,
    RCC_Enable_TIM_8,
    RCC_Enable_USART_1,
    RCC_Enable_ADC_3,
    RCC_Enable_TIM_9 = 51u,
    RCC_Enable_TIM_10,
    RCC_Enable_TIM_11,
    RCC_Enable_TIM_2 = 64u,
    RCC_Enable_TIM_3,
    RCC_Enable_TIM_4,
    RCC_Enable_TIM_5,
    RCC_Enable_TIM_6,
    RCC_Enable_TIM_7,
    RCC_Enable_TIM_12,
    RCC_Enable_TIM_13,
    RCC_Enable_TIM_14,
    RCC_Enable_WWD_GEN = 75u,
    RCC_Enable_SPI_2 = 78u,
    RCC_Enable_SPI_3,
    RCC_Enable_USART_2 = 81u,
    RCC_Enable_USART_3,
    RCC_Enable_USART_4,
    RCC_Enable_USART_5,
    RCC_Enable_I2C_1,
    RCC_Enable_I2C_2,
    RCC_Enable_USB,
    RCC_Enable_CAN = 89u,
    RCC_Enable_BKP = 91u,
    RCC_Enable_PWR,
    RCC_Enable_DAC
} RCC_Enable_Registers;

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

uint32_t rcc_map_ahb_clk_status_to_address(RCC_Enable_Registers periph);
uint32_t rcc_map_apb2_clk_status_to_address(RCC_Enable_Registers periph);
uint32_t rcc_map_apb1_clk_status_to_address(RCC_Enable_Registers periph);
RCC_Config rcc_read_config_to_struct(void);
uint32_t rcc_map_clk_status_to_address(RCC_Enable_Registers periph);
bool rcc_write_clk_settings_to_register(RCC_Config *config, RCC_Enable_Registers periph, RCC_Enable_Disable status, uint32_t rcc_periph_address);
bool rcc_set_clk_for_periph(RCC_Enable_Registers periph, RCC_Enable_Disable status);

#endif // RCC_H