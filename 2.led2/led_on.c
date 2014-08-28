#define GPJCON (*(volatile unsigned long *)0xE0200280)
#define GPJDAT (*(volatile unsigned long *)0xE0200284)
int main()
{
	GPJCON = 0x00001111;
	GPJDAT = 0x00000000;
return 0;
}
