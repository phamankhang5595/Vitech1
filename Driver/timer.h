/*
 *  time.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef _TIMER_H_
#define _TIMER_H_
/******************************************************************************/
/*                              DEFILE                                      */
/******************************************************************************/

typedef void (*type_TimerCallBackFnc)(void);

typedef enum timerChanel
{
    TIMER0 =0,
    TIMER1,
    TIMER2,
    TIMER3
}TimerChanel;

typedef enum timerStatus
{
    TIME_DISABLE,
    TIME_ENABLE
}TimerStatus;


/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
void TIMER_Init(TimerChanel channel);
void TIMER_CallBackInit(type_TimerCallBackFnc pHandle);
void TIMER_Enable(void);
void TIMER_Disable(void);

#endif /*_TIMER_H_*/
