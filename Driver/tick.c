#include "Function_Define.h"
#include "N76E003.h"
#include "SFR_Macro.h"
#include "timer.h"
#include "tick.h"

#define MAX_TICK (2000000000)
static volatile uint32_t tickCount;

void TICK_Init(void)
{
    TIMER_Init(TIMER0);
    TIMER_CallBackInit(TICK_Count);
    TIMER_Enable();
}

void TICK_Count(void)
{
    tickCount++;
    if (tickCount > MAX_TICK)
    {
        tickCount = 0;
    }
    
   /*  WARNING
    Timer 2 should be used to avoid resetting registers TH0 and TL0 in the handler function */
    TCON  &= ~(1 << 4);             // turn off timer
    TL0 =  0xEA;                    //resetting
    TH0 =  0xCB;    
    TCON  |= (1 << 4);              //turn on timer
}

uint32_t Handle_Tick(void)
{
    return tickCount;
}

void TICK_Delay_ms(uint32_t time_ms)
{
    static uint32_t t0, t1;
    t0 = Handle_Tick();
    t1 = Handle_Tick();
    if(t0 < (MAX_TICK - time_ms))
    {
        while(t1 - t0 < time_ms)
        {
            t1 = Handle_Tick();
        }
    }
    else
    {
        if(t1 > time_ms)
        {
            while(t1 > time_ms)
            {
                t1 = Handle_Tick();
            }
            while(MAX_TICK - t0 + t1 < time_ms)
            {
                t1 = Handle_Tick();
            }
        }
        else
        {
            while(MAX_TICK - t0 + t1 < time_ms)
            {
                t1 = Handle_Tick();
            }
        }
    }
    return;
}