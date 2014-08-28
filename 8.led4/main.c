#include "led.h"
#include "cpu_io.h"

static void delay()
{
	volatile unsigned int i = 0xfffff;
	while(i--);
}
void led_test()
{
	led_init();
	while(1)
	{
		led_blink(1);
		delay();
		led_blink(0);
		delay();
	}
}
int main()
{
	led_test();
	return 0;
}
