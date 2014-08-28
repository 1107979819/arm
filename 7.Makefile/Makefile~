#Design by WYL for s5pv210
#define var
TARGET	:= led.bin
BUILD	:= led

ENV	?= SD
SDTOOLS	:= ./mk210

COBJS	+= start.o
COBJS	+= main.o

CROSS_COMPILE	:= arm-linux-

CC	:= $(CROSS_COMPILE)gcc
LD	:= $(CROSS_COMPILE)ld
OBJCOPY	:= $(CROSS_COMPILE)objcopy

CFLAGS	+= -Wall
CFLAGS	+= -I./inc

ifeq ($(ENV),RAM)
LDFLAGS	+= -Ttext=0x0
else
LDFLAGS	+= -Ttext=0x20000000
endif

#Way
all:$(TARGET)
ifeq ($(ENV),RAM)
$(TARGET):$(BUILD)
	$(OBJCOPY) -O binary $^ $@
else
$(TARGET):$(BUILD)
	$(OBJCOPY) -O binary $^ $@.TMP
	$(SDTOOLS) $@.TMP $@
endif

$(BUILD):$(COBJS)
	$(LD) $(LDFLAGS) -o $@ $^
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^
%.o:%.S
	$(CC) $(CFLAGS) -c -o $@ $^
clean:
	rm -f *.bin *.o *.TMP
