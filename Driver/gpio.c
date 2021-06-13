#include "Function_Define.h"
#include "N76E003.h"
#include "SFR_Macro.h"
#include "adc.h"
#include "gpio.h"

void GPIO_P10_Config()
{
    P17_Input_Mode;
    Enable_INT_Port1;
    Enable_BIT7_FallEdge_Trig;
    //PICON |= (1 << 7);
    set_EPI;
    set_EA;
    P17 = 1;
}

void GPIO_P01_Config()
{
    P15_PushPull_Mode;
    P15 = 0;
}

void PinInterrupt_ISR (void) interrupt 7
{
    clr_PIF7;
    P15 ^= 1;
}