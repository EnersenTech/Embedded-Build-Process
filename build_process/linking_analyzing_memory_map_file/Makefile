# PROJECT: name of the output file
PROJECT = main

#DEV : your TM4C123GH6PM when connected to your system,usually will be /dev/ttyACM0
DEV = /dev/ttyACM0

# MCH: variable for compiler options
MCH = cortex-m4

#UTILITY VARIABLES
CC = arm-none-eabi-gcc #compile
FLASHER = lm4flash #flashing utility

#GCC GLAGS
CFLAGS = -c -mcpu=$(MCH) -mthumb -Wall -std=gnu11 -O0 

#LINKER FLAGS
LDFLAGS = -nostdlib -T tm4c_ls.ld -Wl,-Map=final.map 


# Rules to build bin
all: main.o gpio.o tm4c_startup.o final.elf 

#Target:Depndency
#		Recipe
main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^ 

gpio.o:gpio.c
	$(CC) $(CFLAGS) -o $@ $^ 

tm4c_startup.o:tm4c_startup.c 
	$(CC) $(CFLAGS) -o $@ $^ 

final.elf:main.o gpio.o tm4c_startup.o 
	$(CC) $(LDFLAGS) -o $@ $^ 

#Flashes bin to TM4C
load:
	openocd -f board/ti_ek-tm4c123gxl.cfg
clean:
	rm -rf *.o *.elf 

