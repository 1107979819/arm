led_on.bin:led_on.o
	arm-linux-ld -Ttext 0x20000000 -g $^ -o led_on.elf 
	arm-linux-objcopy -O binary -S led_on.elf led_on.bin
%.o:%.S
	arm-linux-gcc -c -o $@ $<
clean:
	rm -f *.o *.elf
