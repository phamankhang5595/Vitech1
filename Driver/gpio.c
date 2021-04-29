#include "Function_Define.h"
#include "N76E003.h"
#include "SFR_Macro.h"
#include "gpio.h"

void GPIO_SOFT_UART_Init()
{
	// P17_PushPull_Mode;
    // PICON = (PICON & (~ 0x03)) | (0x01);
    // PICON |= (1<<7);
    // PINEN |= (1<<7);
    // PIF &= ~(1<<7);
	// IE |= (1<<7);
    P01_PushPull_Mode;
    P0SR |= (1 << 1);
    clr_P01;
    
    P02_PushPull_Mode;
    P0SR |= (1 << 2);
    clr_P02;
}
