buzzer.bin:start.o main.o
	arm-linux-ld -Ttext 0x20000000 -o buzzer.elf $^
	arm-linux-objcopy -O binary buzzer.elf buzzer.bin

%.o:%.S
	arm-linux-gcc -c -o $@ $<
%.o:%.c
	arm-linux-gcc -c -o $@ $<
clean:
	rm -f *.o *.elf
