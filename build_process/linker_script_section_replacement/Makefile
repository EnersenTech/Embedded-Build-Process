# cross compiler name
CC=arm-none-eabi-gcc

# var for compiler options
MACHINE=cortex-m4

# compiler options
CFLAGS= -c -mcpu=$(MACHINE) -mthumb -Wall -std=gnu11 -O0
LDFLAGS= -mcpu=$(MACHINE) -mthumb -T tm4c_ls.ld -Wl,-Map=final.map

all:main.o led.o tm4c_startup.o final.elf

# Target:Dependency 
#        Recipe 
main.o:main.c 
	$(CC) $(CFLAGS) -o $@ $^ 

led.o:led.c
	$(CC) $(CFLAGS) -o $@ $^

tm4c_startup.o:tm4c_startup.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf:main.o led.o tm4c_startup.o 
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf
