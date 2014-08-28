#include "cpu_io.h"
#include "uart.h"
int main()
{
	uart_init();
	myputs("helloworld!\n");
	myputs("==");
	
	return 0;
}
