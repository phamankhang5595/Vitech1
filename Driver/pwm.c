/*
 * Copyright (c) 2021
 * Team, JSC.
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
#include "pwm.h"
#include "delay.h"
/**
 * @func   PWM_Init
 * @brief  Inti PWM2 : Pin1.0, Fpwm=1Mhz, PWM Freq = 1KHz
 *         Imdependnt mode, edge type
 * @param  None
 * @retval None
 */
void PWM_Init (void)
{

    P12_Quasi_Mode;
    PWM0_P12_OUTPUT_ENABLE;
    PWM_IMDEPENDENT_MODE;
    PWM_EDGE_TYPE;
    set_CLRPWM;                 /* Clear PWM 16 bit counter */
    PWM_CLOCK_FSYS;             /* 16MHz */
    PWM_CLOCK_DIV_8;            /* Fpwm = 1MHz */
    PWM_OUTPUT_ALL_NORMAL;
    /* Set frequency */
    PWMPH = 0x00;               /* PWM freq = Fpwm/((PWMPH,PWMPL)+1) = 1MHz/1000 =1kHz*/
    PWMPL = 0x85;
    
}
/**
 * @func   PWM_SetPercentDuty
 * @brief  None
 * @param  
 * @retval None
 */
void PWM_SetDuty (uint16_t pwmDuty)
{
    /* stop pwm */
    clr_PWMRUN;
    PWM0H = (uint8_t)((pwmDuty & 0xFF00) >> 8);
    PWM0L = (uint8_t)(pwmDuty & 0x00FF);
    set_LOAD;
    set_PWMRUN;
}

/**
 * @func   PWM_Stop
 * @brief  None 
 * @param  
 * @retval None
 */
//void PWM_Stop(uint16_t pwmDuty)
//{
//    uint8_t i;
//    for(i = pwmDuty; i < PWM_MaxDuty; i=i+10)
//    {
//        PWM_SetDuty(i);
//        delay_ms(20);
//    }
//}

/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
//void PWM_Start(uint16_t pwmDuty)
//{
//    uint16_t i;
//    for(i = 500; i > pwmDuty; i=i-10)
//    {
//        PWM_SetDuty(i);
//        delay_ms(20);
//    }
//}
