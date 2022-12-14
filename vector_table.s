.syntax unified
.cpu cortex-m3
.fpu softvfp
.thumb
.global vtable
.global default_interrupt_handler
/*
    * The vector table.
    */
.type vtable, %object
.section .vector_table,"a",%progbits
vtable: /* ref man vector table for other stm32f1xxx. .word 0 = reserverd */
    // 0x0000_0000 - 0x0000_003C
    .word 0
    .word reset_handler
    .word nmi_handler
    .word hard_fault_handler
    .word mem_manage_handler
    .word bus_fault_handler
    .word usage_fault_handler
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word svc_handler
    .word debug_monitor_handler
    .word 0
    .word pending_sv_handler
    .word systick_handler
    // 0x0000_0040 - 0x0000_012C
    .word window_watchdog_irq_handler
    .word pvd_irq_handler
    .word tamper_irq_handler
    .word rtc_irq_handler
    .word flash_irq_handler
    .word rcc_irq_handler
    .word exti0_irq_handler
    .word exti1_irq_handler
    .word exti2_irq_handler
    .word exti3_irq_handler
    .word exti4_irq_handler
    .word dma1_chan1_irq_handler
    .word dma1_chan2_irq_handler
    .word dma1_chan3_irq_handler
    .word dma1_chan4_irq_handler
    .word dma1_chan5_irq_handler
    .word dma1_chan6_irq_handler
    .word dma1_chan7_irq_handler
    .word adc1_2_irq_handler
    .word usb_hp_can_tx_irq_handler
    .word usb_lp_can_rx0_irq_handler
    .word can_rx1_irq_handler
    .word can_sce_irq_handler
    .word exti9_5_irq_handler
    .word tim1_brk_irq_handler
    .word tim1_up_irq_handler
    .word tim1_trg_com_irq_handler
    .word tim1_cc_irq_handler
    .word tim2_irq_handler
    .word tim3_irq_handler
    .word tim4_irq_handler
    .word i2c1_ev_irq_handler
    .word i2c1_er_irq_handler
    .word i2c2_ev_irq_handler
    .word i2c2_er_irq_handler
    .word spi1_irq_handler
    .word spi2_irq_handler
    .word usart1_irq_handler
    .word usart2_irq_handler
    .word usart3_irq_handler
    .word exti15_10_irq_handler
    .word rtc_alarm_irq_handler
    .word usb_wakeup_irq_handler
    .word tim8_brk_irq_handler
    .word tim8_up_irq_handler
    .word tim8_trg_com_irq_handler
    .word tim8_cc_irq_handler
    .word adc3_irq_handler
    .word fsmc_irq_handler
    .word sdio_irq_handler
    .word tim5_irq_handler
    .word spi3_irq_handler
    .word uart4_irq_handler
    .word uart5_irq_handler
    .word tim6_irq_handler
    .word tim7_irq_handler
    .word dma2_chan1_irq_handler
    .word dma2_chan2_irq_handler
    .word dma2_chan3_irq_handler
    .word dma2_chan4_5_irq_handler
    /*-------------------------------------------------------------------*/
    // 48
    // (Location to boot from for RAM startup)
    #define boot_ram_base  0xF108F85F
    .word boot_ram_base
    /*
    * Setup weak aliases for each exception handler to the
    * default one. These can be updated later, or just
    * overridden since they're weak refs.
    * The reset_handler is set up separately.
    */
    .weak NMI_handler
    .thumb_set NMI_handler,default_interrupt_handler
    .weak hard_fault_handler
    .thumb_set hard_fault_handler,default_interrupt_handler
    .weak SVC_handler
    .thumb_set SVC_handler,default_interrupt_handler
    .weak pending_SV_handler
    .thumb_set pending_SV_handler,default_interrupt_handler
    .weak SysTick_handler
    .thumb_set SysTick_handler,default_interrupt_handler
    .weak window_watchdog_irq_handler
    .thumb_set window_watchdog_irq_handler,default_interrupt_handler
    .weak PVD_irq_handler
    .thumb_set PVD_irq_handler,default_interrupt_handler
    .weak RTC_irq_handler
    .thumb_set RTC_irq_handler,default_interrupt_handler
    .weak flash_irq_handler
    .thumb_set flash_irq_handler,default_interrupt_handler
    .weak RCC_irq_handler
    .thumb_set RCC_irq_handler,default_interrupt_handler
    .weak EXTI0_1_irq_handler
    .thumb_set EXTI0_1_irq_handler,default_interrupt_handler
    .weak EXTI2_3_irq_handler
    .thumb_set EXTI2_3_irq_handler,default_interrupt_handler
    .weak EXTI4_15_irq_handler
    .thumb_set EXTI4_15_irq_handler,default_interrupt_handler
    .weak DMA1_chan1_irq_handler
    .thumb_set DMA1_chan1_irq_handler,default_interrupt_handler
    .weak DMA1_chan2_3_irq_handler
    .thumb_set DMA1_chan2_3_irq_handler,default_interrupt_handler
    .weak DMA1_chan4_5_irq_handler
    .thumb_set DMA1_chan4_5_irq_handler,default_interrupt_handler
    .weak ADC1_irq_handler
    .thumb_set ADC1_irq_handler,default_interrupt_handler
    .weak TIM1_break_irq_handler
    .thumb_set TIM1_break_irq_handler,default_interrupt_handler
    .weak TIM1_CC_irq_handler
    .thumb_set TIM1_CC_irq_handler,default_interrupt_handler
    .weak TIM2_irq_handler
    .thumb_set TIM2_irq_handler,default_interrupt_handler
    .weak TIM3_irq_handler
    .thumb_set TIM3_irq_handler,default_interrupt_handler
    .weak TIM14_irq_handler
    .thumb_set TIM14_irq_handler,default_interrupt_handler
    .weak TIM16_irq_handler
    .thumb_set TIM16_irq_handler,default_interrupt_handler
    .weak TIM17_irq_handler
    .thumb_set TIM17_irq_handler,default_interrupt_handler
    .weak I2C1_irq_handler
    .thumb_set I2C1_irq_handler,default_interrupt_handler
    .weak SPI1_irq_handler
    .thumb_set SPI1_irq_handler,default_interrupt_handler
    .weak USART1_irq_handler
    .thumb_set USART1_irq_handler,default_interrupt_handler
.size vtable, .-vtable
/*
    * A 'Default' interrupt handler. This is where interrupts
    * which are not otherwise configured will go.
    * It is an infinite loop, because...well, we weren't
    * expecting the interrupt, so what can we do?
    */
.section .text.default_interrupt_handler,"ax",%progbits
default_interrupt_handler:
    default_interrupt_loop:
    B default_interrupt_loop
.size default_interrupt_handler, .-default_interrupt_handler