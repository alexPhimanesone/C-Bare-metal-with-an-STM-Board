PREFIX      = arm-none-eabi-
CC          = $(PREFIX)gcc
CFLAGS      = -Wall -Werror -c -g -Og
LDFLAGS     = -L/opt/mylibs
LDLIBS      = -lm
TARGET_ARCH = -mthumb

OBJS = main.o t1.o t2.o stubs.o
EXE = hello

all : $(EXE)

stubs.o : libs/stubs.c
	$(CC) -g -O2 -c $(TARGET_ARCH) -o $@ $<

$(EXE) : $(OBJS)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

clean :
	rm -f $(OBJS)
	rm -f $(EXE)
.PHONY : clean
