#include "led.h"
#include "clocks.h"
#include "uart.h"
#include "matrix.h"
#include "irq.h"


int main()
{
	clocks_init();

	led_init();
	for (int i = 0; i < 2; i++)
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
	uart_puts("Hello World!");
	
	matrix_init();
	image_statique();

	irq_init();

	return 0;
}