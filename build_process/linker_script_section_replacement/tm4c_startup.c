#include<stdint.h>
#include "tm4c_startup.h"

#define SRAM_START 0x20000000U
#define SRAM_SIZE (128U * 1024) // 128KB					
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

extern uint32_t _etext;
extern uint32_t _edata; 
extern uint32_t _ebss; 
extern uint32_t _sdata;
extern uint32_t _sbss;

// prototpye of main
int main(void);

uint32_t vectors[] __attribute__((section(".isr_vector")))= {
	STACK_START,
    Reset_Handler,              // 1    Reset handler is called when the <RESET> button is pressed
    NMI_Handler,                // 2    Non-Maskable Interrupt handler
    HardFault_Handler,          // 3    Hard Fault Handler
    MemManageFault_Handler,     // 4    Memory management fault Handler
    BusFault_Handler,           // 5    Bus Fault Handler
    UsageFault_Handler,         // 6    Usage Fault Handler
    0,                          // 7    Reserved
    0,                          // 8    Reserved
    0,                          // 9    Reserved
    0,                          // 10   Reserved
    SVC_Handler,                // 11   SuperVisor Call Handler
    DebugMonitor_Handler,       // 12   Debug Monitor Handler
    0,                          // 13   Reserved
    PendSV_Handler,             // 14   Pendeable interrupt driven request
    SysTick_Handler,            // 15   SysTick Timer handler
    GPIOPortA_ISR,              // 16   GPIO Port A Interrupt Service Routine
    GPIOPortB_ISR,              // 17   GPIO Port B Interrupt Service Routine
    GPIOPortC_ISR,              // 18   GPIO Port C Interrupt Service Routine
    GPIOPortD_ISR,              // 19   GPIO Port D Interrupt Service Routine
    GPIOPortE_ISR,              // 20   GPIO Port C Interrupt Service Routine
    UART0_ISR,                  // 21   UART 0
    UART1_ISR,                  // 22   UART 1
    SPI0_ISR,                   // 23   SPI 0
    I2C0_ISR,
    PWM0Fault_ISR,
    PWM0Generator0_ISR,
    PWM0Generator1_ISR,
    PWM0Generator2_ISR,
    QEI0_ISR,
    ADC0Sequence0_ISR,
    ADC0Sequence1_ISR,
    ADC0Sequence2_ISR,
    ADC0Sequence3_ISR,
    WatchDogTimer_ISR,
    Timer0A_ISR,
    Timer0B_ISR,
    Timer1A_ISR,
    Timer1B_ISR,
    Timer2A_ISR,
    Timer2B_ISR,
    AnalogComparator0_ISR,
    AnalogComparator1_ISR,
    0,
    SystemCtrl_ISR,
    FlashCtrl_ISR,
    GPIOPortF_ISR,
    0,
    0,
    UART2_ISR,
    SPI1_ISR,
    Timer3A_ISR,
    Timer3B_ISR,
    I2C1_ISR,
    QEI1_ISR,
    CAN0_ISR,
    CAN1_ISR,
    0,
    0,
    Hibernation_ISR,
    USB0_ISR,
    PWM0Generator3_ISR,
    UDMASoftware_ISR,
    UDMAError_ISR,
    ADC1Sequence0_ISR,
    ADC1Sequence1_ISR,
    ADC1Sequence2_ISR,
    ADC1Sequence3_ISR,
    0,
    0,
    0,
    0,
    0,
    SPI2_ISR,
    SPI3_ISR,
    UART3_ISR,
    UART4_ISR,
    UART5_ISR,
    UART6_ISR,
    UART7_ISR,
    0,
    0,
    0,
    0,
    I2C2_ISR,
    I2C3_ISR,
    Timer4A_ISR,
    Timer4B_ISR,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0, // 95 Reserved
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    Timer5A_ISR,
    Timer5B_ISR,
    WideTimer0A_ISR,
    WideTimer0B_ISR,
    WideTimer1A_ISR,
    WideTimer1B_ISR,
    WideTimer2A_ISR,
    WideTimer2B_ISR,
    WideTimer3A_ISR,
    WideTimer3B_ISR,
    WideTimer4A_ISR,
    WideTimer4B_ISR,
    WideTimer5A_ISR,
    WideTimer5B_ISR,
    SystemException_ISR,
    0, //123 Reserved
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    PWM1Generator0_ISR,
    PWM1Generator1_ISR,
    PWM1Generator2_ISR,
    PWM1Generator3_ISR,
    PWM1Fault_ISR,
};

void Reset_Handler(void)
{
	
	main();
}

void Default_Handler(void)
{
	while(1);
}
