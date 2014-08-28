#include "cpu_io.h"
#include "uart.h"
int main()
{
	uart_init();
	myputc('H');
	myputc('e');
	myputc('l');
	myputc('l');
	myputc('o');
	myputs(" world!\n");
	return 0;
}
