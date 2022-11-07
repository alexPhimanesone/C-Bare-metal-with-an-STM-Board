#include <stdint.h>
#include <stddef.h>
#include "uart.h"
#include "stm32l475xx.h"


void uart_init()
{
    /* activer horloge port B */
    RCC->AHB2ENR = (RCC->AHB2ENR & ~RCC_AHB2ENR_GPIOBEN_Msk) | RCC_AHB2ENR_GPIOBEN;

    /* desactiver USART1 */
    USART1->CR1 &= (0x1 << USART_CR1_UE_Pos);

    /* RX et TX en mode Alternate Function */
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE6_Msk) | GPIO_MODER_MODE6_1;
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE7_Msk) | GPIO_MODER_MODE7_1;
    
    /* indiquer le numero de fonction */
    GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL6_Msk) | (0x7 << GPIO_AFRL_AFSEL6_Pos);
    GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL7_Msk) | (0x7 << GPIO_AFRL_AFSEL7_Pos);

    /* activer horloge USART1 */
    RCC->APB2ENR = (RCC->APB2ENR & ~RCC_APB2ENR_USART1EN_Msk) | RCC_APB2ENR_USART1EN;

    /* horloge de base: PCLK */
    RCC->CCIPR &= ~RCC_CCIPR_USART1SEL;

    /* reset le port serie */
    RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;

    /* oversampling: apres reset,  oversampling à 16 */
    /* word length: apres reset, 8-bit word */
    /* controle de parite: apres reset, pas de controle de parite */
    /* stop bit: apres reset, 1 stop bit */
    
    /* configuration vitesse */
    USART1->BRR = 80000000 / 115200;

    /* activer USART1, RX et TX */
    USART1->CR1 = (USART1->CR1 & ~ USART_CR1_UE_Msk) | USART_CR1_UE;
    USART1->CR1 = (USART1->CR1 & ~ USART_CR1_RE_Msk) | USART_CR1_RE;
    USART1->CR1 = (USART1->CR1 & ~ USART_CR1_TE_Msk) | USART_CR1_TE;
}


void uart_putchar(uint8_t c)
{
    while(!(USART1->ISR & USART_ISR_TXE)) {}
    USART1->TDR = c;
}

uint8_t uart_getchar()
{
    while(!(USART1->ISR & USART_ISR_RXNE)) {}

    /* si erreur de framing ou d'overrun, declencher boucle infini */
    if (USART1->ISR & (USART_ISR_ORE | USART_ISR_FE))
        while(1) {}
    
    return (uint8_t) USART1->RDR;
}

void uart_puts(const char* s)
{
    int i = 0;
    while(s[i])
    {
        uart_putchar(s[i]);
        i++;
    }
    uart_putchar('\r');
    uart_putchar('\n');
}

void uart_gets(char* s, size_t size)
{
    uint8_t c;
    /* nombre de caracteres maximal: size - 1 */
    while(--size)
    {
        c = uart_getchar();
        *s = c;
        s++;
        if (c == '\n')
            break;
    }
    *s = '\0';
}

uint32_t uart_sum()
{
    uint32_t res = 0;
    for(int i = 0; i < 1000; i++)
    {
        res += uart_getchar();
    }
    return res;
}
