PREFIX      = arm-none-eabi-
LD          = $(PREFIX)ld
GDB         = $(PREFIX)gdb
CC          = $(PREFIX)gcc
AS          = $(PREFIX)as
CFLAGS      = -c -g -O1
LDFLAGS     = -T ld_ram.lds -nostdlib
TARGET_ARCH = -mcpu=cortex-m4 -mthumb
# TARGET_ARCH += -mfloat-abi=hard -mfpu=fpv4-sp-d16

OBJS = main.o crt0.o init.o
EXE  = prog.elf

all : $(EXE)

# Regle deja presente
# %.o : %.c
#   $(CC) $(FLAGS) $(TARGET_ARCH) $< -o $@

$(EXE) : $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

connect :
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

debug : $(EXE)
	$(GDB) -x  se203.gdb $<
