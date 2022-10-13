#include "led.h"
#include "clocks.h"

int main()
{
	clocks_init();

	led_init();
	for (int i = 0; i < 30; i++)
	{
		led_g_on();
		for (int i=0; i < 200000; i++)
		{
  			asm volatile("nop");
		}
		led_g_off();
		led(LED_YELLOW);
		for (int i=0; i < 200000; i++)
		{
  			asm volatile("nop");
		}
		led(LED_BLUE);
		for (int i=0; i < 200000; i++)
		{
  			asm volatile("nop");
		}
		led(LED_OFF);
	}

	return 0;
}