# cross compiler name
CC=arm-none-eabi-gcc

# var for compiler options
MACHINE=cortex-m4

# compiler options
CFLAGS= -c -mcpu=$(MACHINE) -mthumb -Wall -std=gnu11 -O0

all:main.o led.o tm4c_startup.o

# Target:Dependency 
#        Recipe 
main.o:main.c 
	$(CC) $(CFLAGS) -o $@ $^ 

led.o:led.c
	$(CC) $(CFLAGS) -o $@ $^

tm4c_startup.o:tm4c_startup.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf
