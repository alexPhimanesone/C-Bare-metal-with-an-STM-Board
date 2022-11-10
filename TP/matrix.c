#include <stdint.h>
#include "matrix.h"
#include "stm32l475xx.h"



void matrix_init()
{
    /* active horloge port A, B, C */
    RCC->AHB2ENR = (RCC->AHB2ENR & ~RCC_AHB2ENR_GPIOAEN_Msk) | RCC_AHB2ENR_GPIOAEN;
    RCC->AHB2ENR = (RCC->AHB2ENR & ~RCC_AHB2ENR_GPIOBEN_Msk) | RCC_AHB2ENR_GPIOBEN;
    RCC->AHB2ENR = (RCC->AHB2ENR & ~RCC_AHB2ENR_GPIOCEN_Msk) | RCC_AHB2ENR_GPIOCEN;

    /* configure broches driver mode GPIO Output */
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE5_Msk) | GPIO_MODER_MODE5_0;
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE4_Msk) | GPIO_MODER_MODE4_0;
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODE3_Msk) | GPIO_MODER_MODE3_0;
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE1_Msk) | GPIO_MODER_MODE1_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE4_Msk) | GPIO_MODER_MODE4_0;
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE2_Msk) | GPIO_MODER_MODE2_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE15_Msk) | GPIO_MODER_MODE15_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE2_Msk) | GPIO_MODER_MODE2_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE7_Msk) | GPIO_MODER_MODE7_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE6_Msk) | GPIO_MODER_MODE6_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE5_Msk) | GPIO_MODER_MODE5_0;
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE0_Msk) | GPIO_MODER_MODE0_0;
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODE3_Msk) | GPIO_MODER_MODE3_0;
    
    /* broches driver vitesse maximale */
    GPIOC->OSPEEDR = (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED5_Msk) | GPIO_OSPEEDR_OSPEED5;
    GPIOC->OSPEEDR = (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED4_Msk) | GPIO_OSPEEDR_OSPEED4;
    GPIOC->OSPEEDR = (GPIOC->OSPEEDR & ~GPIO_OSPEEDR_OSPEED3_Msk) | GPIO_OSPEEDR_OSPEED3;
    GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED1_Msk) | GPIO_OSPEEDR_OSPEED1;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED4_Msk) | GPIO_OSPEEDR_OSPEED4;
    GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED2_Msk) | GPIO_OSPEEDR_OSPEED2;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED15_Msk) | GPIO_OSPEEDR_OSPEED15;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED2_Msk) | GPIO_OSPEEDR_OSPEED2;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED7_Msk) | GPIO_OSPEEDR_OSPEED7;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED6_Msk) | GPIO_OSPEEDR_OSPEED6;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED5_Msk) | GPIO_OSPEEDR_OSPEED5;
    GPIOB->OSPEEDR = (GPIOB->OSPEEDR & ~GPIO_OSPEEDR_OSPEED0_Msk) | GPIO_OSPEEDR_OSPEED0;
    GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~GPIO_OSPEEDR_OSPEED3_Msk) | GPIO_OSPEEDR_OSPEED3;

    /* initialiser les sorties */
    RST_0;
    LAT_1;
    SB_1;
    SCK_0;
    SDA_0;
    deactivate_rows();

    /* attendre 100ms */
    for (int i=0; i < 1500000; i++)
	{
  	    asm volatile("nop");
	}

    /* passer RST etat haut */
    RST_1;

    /* initialiser BANK0 */
    init_bank0();
}

void pulse_SCK()
{
    SCK_0;
    /* attendre >= 25ns */
    for (int i = 0; i < 5; i++)
    {
        asm volatile("nop");
    }
    SCK_1;
    for (int i = 0; i < 5; i++)
    {
        asm volatile("nop");
    }
    SCK_0;
    for (int i = 0; i < 5; i++)
    {
        asm volatile("nop");
    }
}

void pulse_LAT()
{
    LAT_1;
    for (int i = 0; i < 5; i++)
    {
        asm volatile("nop");
    }
    LAT_0;
    for (int i = 0; i < 5; i++)
    {
        asm volatile("nop");
    }
    LAT_1;
    for (int i = 0; i < 5; i++)
    {
        asm volatile("nop");
    }
}

void deactivate_rows()
{
    ROW0_0;
    ROW1_0;
    ROW2_0;
    ROW3_0;
    ROW4_0;
    ROW5_0;
    ROW6_0;
    ROW7_0;
}

void activate_row(int row)
{
    switch(row)
    {
        case 0:
            ROW0_1;
            break;
        case 1:
            ROW1_1;
            break;
        case 2:
            ROW2_1;
            break;
        case 3:
            ROW3_1;
            break;
        case 4:
            ROW4_1;
            break;
        case 5:
            ROW5_1;
            break;
        case 6:
            ROW6_1;
            break;
        case 7:
            ROW7_1;
            break;
    }
}

void send_byte(uint8_t val, int bank)
{
    switch(bank)
    {
        case 0:
            SB_0;
            break;
        case 1:
            SB_1;
            break;
    }
    for (int i = 0; i < 8; i++)
    {
        uint8_t bit = (val & (0x1 << (7-i))) >> (7-i);
        switch(bit)
        {
            case 0:
                SDA_0;
                break;
            case 1:
                SDA_1;
                break;
        }
        pulse_SCK();
    }
    pulse_LAT();
}

void mat_set_row(int row, const rgb_color* val)
{
    for (int i = 0; i < 8; i++)
    {
        send_byte(val[7-i].b, 1);
        send_byte(val[7-i].g, 1);
        send_byte(val[7-i].r, 1);
    }
    activate_row(row);
    pulse_LAT();
}

void init_bank0()
{
    send_byte(0xFF, 0);
    pulse_LAT();
}

void test_pixels()
{
    /* definition des tableaux de couleurs */
    rgb_color blue[8][8];
    for (uint8_t i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            blue[i][j].r = 0;
            blue[i][j].g = 32*i;
            blue[i][j].b = 255;
        }
    }
    rgb_color green[8][8];
    for (uint8_t i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            green[i][j].r = 32*i;
            green[i][j].g = 255;
            green[i][j].b = 0;
        }
    }
    rgb_color red[8][8];
    for (uint8_t i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            red[i][j].r = 255;
            red[i][j].g = 0;
            red[i][j].b = 32*i;
        }
    }

    /* affichage */
    for (int i = 0; i < 8; i++)
    {
        mat_set_row(i, blue[i]);
        for (int p = 0; p < 5000000; p++)
        {
            asm volatile("nop");
        }
        deactivate_rows();
    }
    for (int i = 0; i < 8; i++)
    {
        mat_set_row(i, green[i]);
        for (int p = 0; p < 5000000; p++)
        {
            asm volatile("nop");
        }
        deactivate_rows();
    }
    for (int i = 0; i < 8; i++)
    {
        mat_set_row(i, red[i]);
        for (int p = 0; p < 5000000; p++)
        {
            asm volatile("nop");
        }
        deactivate_rows();
    }
}
