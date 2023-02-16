
ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx):ORIGIN =0x00000000,LENGTH =256K /* FLASH size 256KB */
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =32K /* RAM size 32KB */
}

__max_heap_size = 0x400; /* A symbol declaration. Not a variable */
__max_stack_size = 0x200; /* A symbol declaration. Not a variable */

SECTIONS
{
	.text :
	{
		_text = .;
		*(.isr_vector)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		 _etext = .; /* Store the updated location counter value in to a symbol end_of_text */
	}> FLASH

	.data :
	{
		_data = .;
		*(.data)
		. = ALIGN(4);
		_edata = .; 
	}> SRAM AT> FLASH

	.bss : 
	{
		_bss  = .;
		*(.bss)
		. = ALIGN(4);
		_ebss  = .;
	}> SRAM

}

