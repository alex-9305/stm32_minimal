/* stm32 minimal example stm32_minimal.ld */
/* for an STM32F103C6T6 */
ENTRY(reset_handler)

/* End of RAM / Start of stack */
/* (4KB SRAM) */
_estack = ORIGIN(SRAM) + LENGTH(SRAM);;

/* Set minimum size for stack and dynamic memory. */
/* (The linker will generate an error if there is
    * less than this much RAM leftover.) */
/* (1KB) */
_Min_Leftover_RAM = 0x400;

/* memory layout  */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 32K
    SRAM (rxw)  : ORIGIN = 0x20000000, LENGTH = 10K
}

SECTIONS
{
    /* The vector table goes at the start of flash. */
    .vector_table :
    {
        . = ALIGN(4);   /* . = current address, align(4) = code is aligned to 32bit */
        KEEP (*(.vector_table))
        . = ALIGN(4);
    } >FLASH
    /* The 'text' section contains the main program code. */
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
    } >FLASH
    /* The 'rodata' section contains read-only data,
    * constants, strings, information that won't change. */
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } >FLASH
    /* The 'data' section is space set aside in RAM for
    * things like variables, which can change. */
    _sidata = .;
    .data : AT(_sidata)
    {
        . = ALIGN(4);
        /* Mark start/end locations for the 'data' section. */
        _sdata = .; /* start of "data" */
        *(.data)
        *(.data*)
        _edata = .; /* end of "data" */
        . = ALIGN(4);
    } >SRAM
    /* The 'bss' section is similar to the 'data' section,
    * but its space is initialized to all 0s at the
    * start of the program. */
    .bss :
    {
        . = ALIGN(4);
        /* Also mark the start/end of the BSS section. */
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } >SRAM
    /* Space set aside for the application's heap/stack. */
        .dynamic_allocations :
        {
        . = ALIGN(4);
        _ssystem_ram = .;
        . = . + _Min_Leftover_RAM;
        . = ALIGN(4);
        _esystem_ram = .;
    } >SRAM
}