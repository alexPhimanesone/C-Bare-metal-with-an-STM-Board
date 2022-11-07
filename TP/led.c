#include <stdint.h>
#include "led.h"
#include "stm32l475xx.h"


void led_init()
{
    /* active l'horloge du port B et du port C */
    RCC->AHB2ENR = (RCC->AHB2ENR & ~ RCC_AHB2ENR_GPIOBEN_Msk) | RCC_AHB2ENR_GPIOBEN;
    RCC->AHB2ENR = (RCC->AHB2ENR & ~ RCC_AHB2ENR_GPIOCEN_Msk) | RCC_AHB2ENR_GPIOCEN;
    
    /* PB14 en mode sortie */
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE14_Msk) | GPIO_MODER_MODE14_0;
}

void led_g_on()
{
    GPIOB->BSRR = GPIO_BSRR_BS14;
}

void led_g_off()
{
    GPIOB->BSRR = GPIO_BSRR_BR14;
}

void led(state s)
{
    if (s == LED_OFF)
    {
        /* PC9 en mode entree */
        GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | GPIO_MODER_MODE9_1;
    }
    else
    {
        /* PC9 en mode sortie */
        GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE9_Msk) | GPIO_MODER_MODE9_0;

        if (s == LED_YELLOW)
        {
            GPIOC->BSRR = GPIO_BSRR_BS9;
        }
        else
        {
            GPIOC->BSRR = GPIO_BSRR_BR9;
        }
    }
}