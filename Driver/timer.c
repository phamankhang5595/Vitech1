/*
 *  time.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "soft_uart.h"
#include "gpio.h"
#include "timer.h"

/******************************************************************************/
/*                              DECLARE AND DEFINE                                      */
/******************************************************************************/

type_TimerCallBackFnc p_timerCallBack;
/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
void TIMER_Init(TimerChanel channel)
{
    switch (channel)
    {
    case TIMER0:
        CKCON |= (1 << 3); // clock source of Timer 0 is direct the system clock
        TMOD |= (1 << 0); // timer0 16bit
        //WARNING
        // Timer 2 should be used to avoid resetting registers TH0 and TL0 in the 
        TL0 =  0xEA;  // = 65535 - 16000000/1200 = 52202
        TH0 =  0xCB;  // 65535 - 16000000/1200
        break;
    case TIMER1:
        break;
    case TIMER2:
        break;
    case TIMER3:
        break;
    default:
        break;
    }
    TIMER_Disable();
}

/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
void TIMER_CallBackInit(type_TimerCallBackFnc pHandle)
{
    p_timerCallBack = pHandle;
}

/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
static void TIMER_Enable_Select(TimerChanel channel)
{
    switch (channel)
    {
    case TIMER0:
        TCON  |= (1 << 4); // enable timer0
        break;
    case TIMER1:
        TCON  |= (1 << 6); // enable timer1
    case TIMER2:
        T2CON |= (1 << 2); // enable time2
    case TIMER3:
        T3CON |= (1 << 3); // enable time3
    default:
        break;
    }
}

void TIMER_Enable(void)
{
    TIMER_Enable_Select(TIMER0);
}
/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
static void TIMER_Disable_Select(TimerChanel channel)
{
    switch (channel)
    {
    case TIMER0:
        TCON  &= ~(1 << 4); // enable timer0
        break;
    case TIMER1:
        TCON  &= ~(1 << 6); // enable timer1
    case TIMER2:
        T2CON &= ~(1 << 2); // enable time2
    case TIMER3:
        T3CON &= ~(1 << 3); // enable time3
    default:
        break;
    }
}

void TIMER_Disable(void)
{
    TIMER_Disable_Select(TIMER0);
}
/**
 * @func   Timer0Overflow_ISR
 * @brief  None
 * @param  
 * @retval None
 */
void Timer0Overflow_ISR(void) interrupt 1
{
    if(p_timerCallBack != NULL)
    {
        p_timerCallBack();
    }
}