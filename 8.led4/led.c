#include "gpio.h"
#include "led.h"
#include "cpu_io.h"
void led_init(void)
{
	struct s5pv210_gpio *gpio_base =(struct s5pv210_gpio *)S5V210_GPIO_BASE;
	unsigned int var;
	
	var =__REG(&gpio_base->j2.con);
	var &=~(0xffff<<0);//先将需要修改的对应位清0为下面的赋值做准备
	var |= (0x1111<<0);
	writel(var,&gpio_base->j2.con);
}
void led_blink(int status)
{
	struct s5pv210_gpio *gpio_base =(struct s5pv210_gpio *)S5V210_GPIO_BASE;
	unsigned int var;
	if(status)
	{
		var = __REG(&gpio_base->j2.dat);
		var &= ~0xf;
		writel(var,&gpio_base->j2.dat);
	}
	else{
		var = __REG(&gpio_base->j2.dat);
		var |= 0xf;
		writel(var,&gpio_base->j2.dat);
	}
}