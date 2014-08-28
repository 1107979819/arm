#include "cpu_io.h"
#include "uart.h"
#include "gpio.h"

void uart_init(void)
{
	/*串口初始化，配置串口参数*/
	
	struct s5pv210_gpio *gpio_base =(struct s5pv210_gpio *)S5PV210_GPIO_BASE;
	struct s5pv2xx_uart *uart_base =(struct s5pv2xx_uart *)S5PV210_UART_BASE;
	unsigned int var; 
	/*配置功能引脚*/
	var = readl(&gpio_base->a0.con);
	var &= ~(0xff<<0);
	var |= (0x22<<0);
	writel(var,&gpio_base->a0.con);

	/*配置串口控制器*/
	__REG(&uart_base->ulcon) = 0x3;	//配置ulcon实现 8位字长 1个停止位 无奇偶校验位 正常模式（非红外模式）
	__REG(&uart_base->ucon) = 0x5; 	//使能发送、接收
	
	/*配置波特率*/
	/*
		计算方法：假设SCLK_UART为66.5MHZ,设定的波特率为115200
		DIV_VAL	=(SCLK_UART/(Baud_Rate*16))-1
				=((66.5*1000000)/(115200*16))-1000000
				=35.07855903
				
		UBRDIVn 的值为整数位的值，
		UDIVSLOTn的值： 16*小数位 的结果的第一位的值说在表格中对应的值（表格看数据手册880页）
						约为 16*0.07=1.12 第一位为1,1在表格对应为0x0080
		
		UBRDIVn = 35
		UDIVSLOTn = 0x0080		
	*/
	__REG(&uart_base->ubrdiv) = 35;	
	__REG(&uart_base->udivslot) = 0x80;
}

void myputc(char c)
{
	/* 发送一个字符 */
	
	struct s5pv2xx_uart *uart_base =(struct s5pv2xx_uart *)S5PV210_UART_BASE;

	/* 判断发送缓冲区是否为空 */
	while(!(__REG(&uart_base->utrstat)&(0x01<<2)));
	
	/*再在发送数据 */
	__REG(&uart_base->utxh) = c;	//设置要发送的值给串口缓冲区
}

void myputs(const char *str)
{
	/* 发送字符串 */
	while(*str)
	{
		myputc(*str);
		str++;
	}
}