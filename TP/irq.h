// ARM internal exceptions
void NMI_Handler();        /* NMI handler */
void HardFault_Handler();  /* Hard Fault handler */
void MemManage_Handler();
void BusFault_Handler();
void UsageFault_Handler();
void SVC_Handler();        /* SVC handler */
void PendSV_Handler();     /* Pending SVC handler */
void SysTick_Handler();    /* SysTick hanlder */

// STM32L475 External interrupts
void WWDG_IRQHandler();         /* Watchdog IRQ */
void PVD_PVM_IRQHandler();      /* ... */
void TAMP_STAMP_IRQHandler();   /* ... */
void RTC_WKUP_IRQHandler();
void FLASH_IRQHandler();
void RCC_IRQHandler();
void EXTI0_IRQHandler();
void EXTI1_IRQHandler();
void EXTI2_IRQHandler();
void EXTI3_IRQHandler();
void EXTI4_IRQHandler();
void DMA1_CH1_IRQHandler();
void DMA1_CH2_IRQHandler();
void DMA1_CH3_IRQHandler();
void DMA1_CH4_IRQHandler();
void DMA1_CH5_IRQHandler();
void DMA1_CH6_IRQHandler();
void DMA1_CH7_IRQHandler();
void ADC1_2_IRQHandler();
void CAN1_TX_IRQHandler();
void CAN1_RX0_IRQHandler();
void CAN1_RX1_IRQHandler();
void CAN1_SCE_IRQHandler();
void EXTI9_5_IRQHandler();
void TIM1_BRK_IRQHandler();
void TIM1_UP_IRQHandler();
void TIM1_TRG_COM_IRQHandler();
void TIM1_CC_IRQHandler();
void TIM2_IRQHandler();
void TIM3_IRQHandler();
void TIM4_IRQHandler();
void I2C1_EV_IRQHandler();
void I2C1_ER_IRQHandler();
void I2C2_EV_IRQHandler();
void I2C2_ER_IRQHandler();
void SPI1_IRQHandler();
void SPI2_IRQHandler();
void USART1_IRQHandler();
void USART2_IRQHandler();
void USART3_IRQHandler();
void EXTI15_10_IRQHandler();
void RTC_ALARM_IRQHandler();
void DFSDM1_FLT3_IRQHandler();
void TIM8_BRK_IRQHandler();
void TIM8_UP_IRQHandler();
void TIM8_TRG_COM_IRQHandler();
void TIM8_CC_IRQHandler();
void ADC3_IRQHandler();
void FMC_IRQHandler();
void SDMMC1_IRQHandler();
void TIM5_IRQHandler();
void SPI3_IRQHandler();
void UART4_IRQHandler();
void UART5_IRQHandler();
void TIM6_DACUNDER_IRQHandler();
void TIM7_IRQHandler();
void DMA2_CH1_IRQHandler();
void DMA2_CH2_IRQHandler();
void DMA2_CH3_IRQHandler();
void DMA2_CH4_IRQHandler();
void DMA2_CH5_IRQHandler();
void DFSDM1_FLT0_IRQHandler();
void DFSDM1_FLT1_IRQHandler();
void DFSDM1_FLT2_IRQHandler();
void COMP_IRQHandler();
void LPTIM1_IRQHandler();
void LPTIM2_IRQHandler();
void OTG_FS_IRQHandler();
void DMA2_CH6_IRQHandler();
void DMA2_CH7_IRQHandler();
void LPUART1_IRQHandler();
void QUADSPI_IRQHandler();
void I2C3_EV_IRQHandler();
void I2C3_ER_IRQHandler();
void SAI1_IRQHandler();
void SAI2_IRQHandler();
void SWPMI1_IRQHandler();
void TSC_IRQHandler();
void LCD_IRQHandler();
void AES_IRQHandler();
void RNG_IRQHandler();
void FPU_IRQHandler();


void irq_init(void);