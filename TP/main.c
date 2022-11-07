#include "led.h"
#include "clocks.h"
#include "uart.h"


void display(uint32_t n)
{
	uint8_t bit;
	for (int i = 0; i < 32; i++)
	{	
		bit = (n & (0x1 << (31-i))) >> (31-i);
		if (bit == 0x1)
		{
			uart_putchar('1');
		}
		else
			uart_putchar('0');
		if (i == 3 || i == 7 || i == 11 || i == 15 || i == 19 || i == 23 || i == 27)
			uart_putchar('_');
	}
	uart_putchar('\r');
	uart_putchar('\n');
}

int main()
{
	clocks_init();

	led_init();
	for (int i = 0; i < 3; i++)
	{
		led_g_on();
		for (int i=0; i < 3000000; i++)
		{
  			asm volatile("nop");
		}
		led_g_off();
		led(LED_YELLOW);
		for (int i=0; i < 3000000; i++)
		{
  			asm volatile("nop");
		}
		led(LED_BLUE);
		for (int i=0; i < 3000000; i++)
		{
  			asm volatile("nop");
		}
		led(LED_OFF);
	}

	uart_init();
	uint8_t c = 'a';
	uart_putchar(c);
	uart_putchar('\r');
	uart_putchar('\n');
	const char* s = "Hello World!";
	uart_puts(s);
	/*
	while(1)
		uart_putchar(uart_getchar());
	*/
	uint32_t somme = uart_sum();
	display(somme);

	return 0;
}