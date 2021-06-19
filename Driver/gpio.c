#include "Function_Define.h"
#include "N76E003.h"
#include "SFR_Macro.h"
#include "relay.h"
#include "adc.h"
#include "delay.h"
#include "gpio.h"

extern uint16_t topLimitFloor;
extern uint16_t botLimitFloor;
extern uint8_t programRun;

type_GpioCallBackFnc    p_gpioCallBack = NULL;

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

void GPIO_CallBackInit(type_GpioCallBackFnc gpioCallBackFnc)
{
    p_gpioCallBack = gpioCallBackFnc;
}

void PinInterrupt_ISR (void) interrupt 7
{
    clr_PIF7;
    if (!programRun)
    {
        if(p_gpioCallBack != NULL)
        {
            p_gpioCallBack();
        }       
    }      
}