/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "timer.h"
#include "soft_uart.h"

#define SET_LOW() (clr_P02)
#define SET_HIGH() (set_P02)


static volatile uint32_t tickCount;

static void SOFT_UART_PinInit()
{
    P02_PushPull_Mode;
    P0SR |= (1 << 2);
    SET_HIGH();
}

void TICK_Count(void)
{
    tickCount++;
   /*  WARNING
    Timer 2 should be used to avoid resetting registers TH0 and TL0 in the handler function */
    TCON  &= ~(1 << 4);             // turn off timer
    TL0 =  0xEA;                    //resetting
    TH0 =  0xCB;    
    TCON  |= (1 << 4);              //turn on timer
}

static uint32_t Handle_Tick(void)
{
    return tickCount;
}

void SOFT_UART_Init(uint16_t baudRate)
{
    CKSWT |= (1 << 5);
    CKSWT &= ~(1 << 3);
    CKSWT &= ~(3 << 1);
    CKEN |= (1 << 5);
    
    TIMER_Init(TIMER0,baudRate);
    set_ET0;
    SOFT_UART_PinInit();
    TIMER_CallBackInit(TICK_Count);
    TIMER_Enable(TIMER0);
}

void SOFT_UART_SendByte(uint8_t dataByte)
{
    int i;
    uint8_t buff[8];
    SET_HIGH();
    //SET_LOW();
    for(i = 0; i < 8; i++)
    {
        buff[i]=(dataByte >> i)&(1U);
    }
    tickCount = 0;
    while(Handle_Tick() != 1);
    SET_LOW();
    //SET_HIGH();
    
    for(i = 0; i < 8; i++)
    {
        while (Handle_Tick() == i+1);
        if(buff[i] == 1)
        {
            SET_HIGH();
            //SET_LOW();
        }else
        {
            SET_LOW();
           // SET_HIGH();
        }
    }
    while (Handle_Tick() == 9);
    SET_HIGH();
    //SET_LOW();
}
