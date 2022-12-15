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

    /*
    * Setup weak aliases for each exception handler to the
    * default one. These can be updated later, or just
    * overridden since they're weak refs.
    * The reset_handler is set up separately.
    */
    .weak nmi_handler
    .thumb_set nmi_handler,default_interrupt_handler

    .weak hard_fault_handler
    .thumb_set hard_fault_handler,default_interrupt_handler

    .weak mem_manage_handler
    .thumb_set mem_manage_handler,default_interrupt_handler

    .weak bus_fault_handler
    .thumb_set bus_fault_handler,default_interrupt_handler

    .weak usage_fault_handler
    .thumb_set usage_fault_handler,default_interrupt_handler

    .weak svc_handler
    .thumb_set svc_handler,default_interrupt_handler

    .weak debug_monitor_handler
    .thumb_set debug_monitor_handler,default_interrupt_handler

    .weak pending_sv_handler
    .thumb_set pending_sv_handler,default_interrupt_handler

    .weak systick_handler
    .thumb_set systick_handler,default_interrupt_handler

    .weak window_watchdog_irq_handler
    .thumb_set window_watchdog_irq_handler,default_interrupt_handler

    .weak pvd_irq_handler
    .thumb_set pvd_irq_handler,default_interrupt_handler

    .weak tamper_irq_handler
    .thumb_set tamper_irq_handler,default_interrupt_handler

    .weak rtc_irq_handler
    .thumb_set rtc_irq_handler,default_interrupt_handler

    .weak flash_irq_handler
    .thumb_set flash_irq_handler,default_interrupt_handler

    .weak rcc_irq_handler
    .thumb_set rcc_irq_handler,default_interrupt_handler

    .weak exti0_irq_handler
    .thumb_set exti0_irq_handler,default_interrupt_handler

    .weak exti1_irq_handler
    .thumb_set exti1_irq_handler,default_interrupt_handler

    .weak exti2_irq_handler
    .thumb_set exti2_irq_handler,default_interrupt_handler

    .weak exti3_irq_handler
    .thumb_set exti3_irq_handler,default_interrupt_handler

    .weak exti4_irq_handler
    .thumb_set exti4_irq_handler,default_interrupt_handler

    .weak dma1_chan1_irq_handler
    .thumb_set dma1_chan1_irq_handler,default_interrupt_handler

    .weak dma1_chan2_irq_handler
    .thumb_set dma1_chan2_irq_handler,default_interrupt_handler

    .weak dma1_chan3_irq_handler
    .thumb_set dma1_chan3_irq_handler,default_interrupt_handler

    .weak dma1_chan4_irq_handler
    .thumb_set dma1_chan4_irq_handler,default_interrupt_handler

    .weak dma1_chan5_irq_handler
    .thumb_set dma1_chan5_irq_handler,default_interrupt_handler

    .weak dma1_chan6_irq_handler
    .thumb_set dma1_chan6_irq_handler,default_interrupt_handler

    .weak dma1_chan7_irq_handler
    .thumb_set dma1_chan7_irq_handler,default_interrupt_handler

    .weak adc1_2_irq_handler
    .thumb_set adc1_2_irq_handler,default_interrupt_handler

    .weak usb_hp_can_tx_irq_handler
    .thumb_set usb_hp_can_tx_irq_handler,default_interrupt_handler

    .weak usb_lp_can_rx0_irq_handler
    .thumb_set usb_lp_can_rx0_irq_handler,default_interrupt_handler

    .weak can_rx1_irq_handler
    .thumb_set can_rx1_irq_handler,default_interrupt_handler

    .weak can_sce_irq_handler
    .thumb_set can_sce_irq_handler,default_interrupt_handler

    .weak exti9_5_irq_handler
    .thumb_set exti9_5_irq_handler,default_interrupt_handler

    .weak tim1_brk_irq_handler
    .thumb_set tim1_brk_irq_handler,default_interrupt_handler

    .weak tim1_up_irq_handler
    .thumb_set tim1_up_irq_handler,default_interrupt_handler

    .weak tim1_trg_com_irq_handler
    .thumb_set tim1_trg_com_irq_handler,default_interrupt_handler

    .weak tim1_cc_irq_handler
    .thumb_set tim1_cc_irq_handler,default_interrupt_handler

    .weak tim2_irq_handler
    .thumb_set tim2_irq_handler,default_interrupt_handler

    .weak tim3_irq_handler
    .thumb_set tim3_irq_handler,default_interrupt_handler

    .weak tim4_irq_handler
    .thumb_set tim4_irq_handler,default_interrupt_handler

    .weak i2c1_ev_irq_handler
    .thumb_set i2c1_ev_irq_handler,default_interrupt_handler

    .weak i2c1_er_irq_handler
    .thumb_set i2c1_er_irq_handler,default_interrupt_handler

    .weak i2c2_ev_irq_handler
    .thumb_set i2c2_ev_irq_handler,default_interrupt_handler

    .weak i2c2_er_irq_handler
    .thumb_set i2c2_er_irq_handler,default_interrupt_handler

    .weak spi1_irq_handler
    .thumb_set spi1_irq_handler,default_interrupt_handler

    .weak spi2_irq_handler
    .thumb_set spi2_irq_handler,default_interrupt_handler

    .weak usart1_irq_handler
    .thumb_set usart1_irq_handler,default_interrupt_handler

    .weak usart2_irq_handler
    .thumb_set usart2_irq_handler,default_interrupt_handler

    .weak usart3_irq_handler
    .thumb_set usart3_irq_handler,default_interrupt_handler

    .weak exti15_10_irq_handler
    .thumb_set exti15_10_irq_handler,default_interrupt_handler

    .weak rtc_alarm_irq_handler
    .thumb_set rtc_alarm_irq_handler,default_interrupt_handler

    .weak usb_wakeup_irq_handler
    .thumb_set usb_wakeup_irq_handler,default_interrupt_handler

    .weak tim8_brk_irq_handler
    .thumb_set tim8_brk_irq_handler,default_interrupt_handler

    .weak tim8_up_irq_handler
    .thumb_set tim8_up_irq_handler,default_interrupt_handler

    .weak tim8_trg_com_irq_handler
    .thumb_set tim8_trg_com_irq_handler,default_interrupt_handler

    .weak tim8_cc_irq_handler
    .thumb_set tim8_cc_irq_handler,default_interrupt_handler

    .weak adc3_irq_handler
    .thumb_set adc3_irq_handler,default_interrupt_handler

    .weak fsmc_irq_handler
    .thumb_set fsmc_irq_handler,default_interrupt_handler

    .weak sdio_irq_handler
    .thumb_set sdio_irq_handler,default_interrupt_handler

    .weak tim5_irq_handler
    .thumb_set tim5_irq_handler,default_interrupt_handler

    .weak spi3_irq_handler
    .thumb_set spi3_irq_handler,default_interrupt_handler

    .weak uart4_irq_handler
    .thumb_set uart4_irq_handler,default_interrupt_handler

    .weak uart5_irq_handler
    .thumb_set uart5_irq_handler,default_interrupt_handler

    .weak tim6_irq_handler
    .thumb_set tim6_irq_handler,default_interrupt_handler

    .weak tim7_irq_handler
    .thumb_set tim7_irq_handler,default_interrupt_handler

    .weak dma2_chan1_irq_handler
    .thumb_set dma2_chan1_irq_handler,default_interrupt_handler

    .weak dma2_chan2_irq_handler
    .thumb_set dma2_chan2_irq_handler,default_interrupt_handler

    .weak dma2_chan3_irq_handler
    .thumb_set dma2_chan3_irq_handler,default_interrupt_handler

    .weak dma2_chan4_5_irq_handler
    .thumb_set dma2_chan4_5_irq_handler,default_interrupt_handler
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