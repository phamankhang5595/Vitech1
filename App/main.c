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
#include "delay.h"
#include "irf.h"
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
