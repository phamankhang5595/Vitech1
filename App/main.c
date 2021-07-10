/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "gpio.h"
#include "motor.h"
#include "main_func.h"
#include "main_init.h"
#include "irfapp_main.h"
#include "uart.h"
#include "floor.h"
#include "tick.h"
#include "delay.h"
#include "adc.h"
#include "irf.h"
#include "flash.h"
#include <stdio.h>
/*******************************************************************************
 * Definition
 ******************************************************************************/
void getFloorLimitValue(void)
{
    int timeout = 10000;
    while ((timeout--) && P17 == 0);
    if (timeout < 2)
    {
        FLOOR_GetTopAndBotLimitValue();
    }
}

void main(void)
{
    MAIN_Init();

    while(1)
    {
        if (!P17)
        {
            getFloorLimitValue();
        }
        IRF_Proc();
        funcHandle_AllFlag();
    }
}
