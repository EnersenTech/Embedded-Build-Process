# Build Procedure and linker script for bare metal embedded systems (ARM Cortex Mx)

## Prerequisite (WindowsOS)
```
1. Install ARM GNU Toolchains 
```
As we need to create an executable file for running on ARM Cortex Mx devices, we need to use a target specific cross compiler.<br>
There are various options ARM provided, but we will use open source ARM GCC. <br>
Please download from link down below <br>
[Download link](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
(Check variable add to path option while installation)
<br>
```
2. Install Make
```
The make utility requires a file, Makefile, which defines set of tasks to be executed.  <br>
Make command is not default on WindowsOS. <br>
You should download and then add /bin path to your PC env variable.  <br>
[Download link](https://gnuwin32.sourceforge.net/packages/make.htm)

## Compile with options

You may have seen compile command in C programming language like this 
```
$ gcc main.c -o main
```
However, you will encouter an error message with files on the repository (`main.c`, `main.h`, `led.c`, `led.h`)<br>
This is because assembler couldn't find an ARM architecture from pre-processor steps. <br>
There are many architectures on ARM devices. (ARM Cortex-M0, ARM Cortex-M1, ARM Cortex-M2, ARM Cortex-M3, ARM Cortex-M4, etc.) <br>
We should provide an extra information when you build with cross compiler. 
```
// We use arm-none-eabi-gcc instead of gcc
$ arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb main.c -o main.o
```
`-mcpu=(name)` option specifies the name of the target ARM processor. 
`-mthumb` option needed if you want to run on Cortex-Mx devices. Becuase Cortex-Mx uses thumb mode only not ARM mode. The thumb mode is 16 bits word adequate. 

## Re-locatable object files analysis 
By the end of compilation, you will get `main.o` file and `led.o` file. <br>
With binary application from ARM GNU toolchain installed, you can analyze object files. <br>
This is an important step before creating startup file.  <br>



