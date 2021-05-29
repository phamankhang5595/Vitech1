#include "Function_Define.h"
#include "N76E003.h"
#include "SFR_Macro.h"
#include "adc.h"
#include "gpio.h"

void GPIO_P10_Config()
{
    P10_Input_Mode;
    Enable_INT_Port1;
    Enable_BIT0_RasingEdge_Trig;
    PICON |= (1 << 2);
    set_EPI;
    set_EA;
}

void GPIO_P01_Config()
{
    P01_PushPull_Mode;
}

void PinInterrupt_ISR (void) interrupt 7
{
    clr_PIF0;
    P01 ^= 1;
}