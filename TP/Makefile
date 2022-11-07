PREFIX      = arm-none-eabi-
LD          = $(PREFIX)ld
GDB         = $(PREFIX)gdb
CC          = $(PREFIX)gcc
AS          = $(PREFIX)as
CFLAGS      = -c -g -O1 -ffreestanding -Wall -Wextra -Werror
LDFLAGS     = -T ld_ram.lds -nostdlib
CPPFLAGS    = -ICMSIS/Device/ST/STM32L4xx/Include -ICMSIS/Include
TARGET_ARCH = -mcpu=cortex-m4 -mthumb
TARGET_ARCH += -mfloat-abi=hard -mfpu=fpv4-sp-d16

OBJS = main.o crt0.o init.o memfuncs.o led.o uart.o
EXE  = prog.elf


all : $(EXE)

# Regle deja presente
# %.o : %.c
#   $(CC) $(CPPFLAGS) $(CFLAGS) $(TARGET_ARCH) $< -o $@

$(EXE) : $(OBJS)
	$(CC) $(LDFLAGS) $^ clocks.o -o $@

connect :
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

tio :
	tio /dev/ttyACM0

debug : $(EXE)
	$(GDB) -x  se203.gdb $<

hello_test : hello
	$(GDB) -x  se203.gdb $<


clean :
	rm -f $(OBJS)
	rm -f $(EXE)
.PHONY : clean
