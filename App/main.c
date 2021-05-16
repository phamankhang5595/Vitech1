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
#include "uart.h"
#include "delay.h"
#include "relay.h"
#include "motor.h"
#include "pwm.h"
#include "queue.h"
#include "floor.h"
#include "adc.h"
#include "timer.h"
#include "irf.h"
#include "gpio.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/

void main(void)
{
    MAIN_Init();
    while(1)
    {
        IRF_Proc();
        funcHandle_AllFlag();
    }
}
