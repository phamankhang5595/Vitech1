/*
 * Copyright (c) 2021
 * Vitech Solutions
 * All Rights Reserved
 *
 *
 * Description:
 *
 * Author: Truongvv
 *
 * Last Changed By:  $Author: Truongvv $
 * Revision:         $Revision: 1.0 $
 * Last Changed:     $Date: x/x/xxxx $
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
    uint16_t val;
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
//    while(1)
//        {
//            val = ADC_ReadResultConvert();
//            UART_SendByte((val >> 4)& 0xff);
//            UART_SendByte(val & 0x0f);
//            delay_ms(1000);
//        }
}
