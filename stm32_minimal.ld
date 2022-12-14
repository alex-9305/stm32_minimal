/*****************************************
 * stm32 minimal example stm32_minimal.ld
 *****************************************/
/* memory layout for an STM32F103C6T6 */
_estack = ORIGIN(SRAM) + LENGTH(SRAM);

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 32K
    SRAM (rxw)  : ORIGIN = 0x20000000, LENGTH = 10K
}