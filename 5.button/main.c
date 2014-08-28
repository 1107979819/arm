#define GPH2CON (*(volatile unsigned long *)0xE0200C40) 
#define GPH2DAT (*(volatile unsigned long *)0xE0200C44)
#define GPJCON (*(volatile unsigned long *)0xE0200280)
#define GPJDAT (*(volatile unsigned long *)0xE0200284)
int main()
{
	init();
	while(1)
	{
		if(GPH2DAT & (1<<0))
		{
			led_off();			
		}
		else
		{
			led_on();

		}	
	}
	return 0;
}

void init(void)
{
	//设置按键的控制口为输入
	GPH2CON &= 0<<0;
	//设置led的控制口为输出
	GPJCON = 0x00001111;
	//初始化led闪三下
	led_on();
	delay(0xFFFFF);
	led_off();
	delay(0xFFFFF);
	led_on();
	delay(0xFFFFF);
	led_off();
	delay(0xFFFFF);
	led_on();
	delay(0xFFFFF);
	led_off();
	delay(0xFFFFF);
	led_on();
	delay(0xFFFFF);
	led_off();
	delay(0xFFFFF);	
}
void led_on(void)
{
	GPJDAT = 0x00;
}
void led_off(void)
{
	GPJDAT = 0x0F;
}
void delay(unsigned long count)
{
	volatile unsigned long i = count;
	while(i--);
}

