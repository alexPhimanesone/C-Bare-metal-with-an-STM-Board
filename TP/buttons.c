

void  button_init(void)
{   
    /* active horloge port C */
    RCC->AHB2ENR = (RCC->AHB2ENR & ~RCC_AHB2ENR_GPIOCEN_Msk) | RCC_AHB2ENR_GPIOCEN;

    /* PC13 en mode entree */
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE13_Msk) | GPIO_MODER_MODE13_0;

    /* PC13 comme source d'IRQ pour EXTI13 */
    SYSCFG->EXTICR4 = SYSCFG_EXTICR4_EXTI13_PC;

    /* configuration de l'EXTI */
    EXTI->IMR1 |= EXTI_IMR1_IM13;
    EXTI->RTSR1 &= ~EXTI_RTSR1_RT13;
    EXTI->FTSR1 |= EXTI_FTSR1_FT13;
    // pas fini
} 
