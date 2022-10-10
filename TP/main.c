#include "led.h"

int fibo(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return (fibo(n-1) + fibo(n-2));
}

int n1 = 777;
int n2;
int n3;

int main()
{
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

	return fibo(8);
}