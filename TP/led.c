#include <stdint.h>
#include "led.h"

#define RCC_AHB2ENR *((volatile uint32_t*) 0x4002104C)
#define GPIOB_MODER *((volatile uint32_t*) 0x48000400)
#define GPIOC_MODER *((volatile uint32_t*) 0x48000800)
#define GPIOB_BSRR *((volatile uint32_t*) 0x48000418)
#define GPIOC_BSRR *((volatile uint32_t*) 0x48000818)


void led_init()
{
    /* active l'horloge du port B et du port C */
    RCC_AHB2ENR = RCC_AHB2ENR | 0b110;

    /* PB14 en mode sortie */
    GPIOB_MODER = (GPIOB_MODER & ~(0b11 << 28)) | (0b01 << 28);
}

void led_g_on()
{
    GPIOB_BSRR = 1 << 14;
}

void led_g_off()
{
    GPIOB_BSRR = 1 << 30;
}

void led(state s)
{
    if (s == LED_OFF)
    {
        /* PC9 en mode entree */
        GPIOC_MODER = GPIOC_MODER & ~(0b11 << 18);
    }
    else
    {
        /* PC9 en mode sortie */
        GPIOC_MODER = (GPIOC_MODER & ~(0b11 << 18)) | (0b01 << 18);

        if (s == LED_YELLOW)
        {
            GPIOC_BSRR = 1 << 9;
        }
        else
        {
            GPIOC_BSRR = 1 << 25;
        }
    }
}