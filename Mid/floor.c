#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "adc.h"
#include "relay.h"
#include "delay.h"
#include "floor.h"

extern uint16_t topLimitFloor;
extern uint16_t botLimitFloor;
uint16_t adc_retval[12];

#define STEP ((topLimitFloor - botLimitFloor) / 12)
#define DELTA  (6)

static void get_adc_levels()
{
    int i;
    for ( i = 0; i < 12; i++)
    {
        adc_retval[i] = botLimitFloor + i * STEP;
    }
}

int FLOOR_UpOrDown(uint16_t desireIncl)
{
    int i;
    uint16_t resutlAdc;
    directionFloor_t dir = F_DEFAULT;
    uint16_t incline_level[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    /* Check input*/
    if(desireIncl < 1 | desireIncl > 12)
    {
        return -1;
    }
    /* Get adc value levels base on top limit and bottom limit*/
    get_adc_levels();

    /* Convert incline from desire Level to adc value*/
    for (i = 0; i < 12; i++)
    {
        if (desireIncl == incline_level[i])
        {
            desireIncl = adc_retval[i];
            break;
        }
    }
    /* Get current value of adc*/
    resutlAdc = readResultConvert();
    /*  Check Incline will increase or decrease*/
    if ( resutlAdc <  desireIncl - DELTA)
    {
        dir = F_UP;
    }
    else if( resutlAdc >= ( desireIncl - DELTA ) && resutlAdc <= ( desireIncl + DELTA ))
    {
        return 0;
    }
    else
    {
        dir = F_DOWN;
    }

    switch (dir)
    {
    case F_UP:
        RELAY_DownReset();
        delay_ms(100);
        RELAY_Up();
        do
        {
            resutlAdc = readResultConvert();
        } while (resutlAdc < (desireIncl - DELTA) || resutlAdc > (desireIncl + DELTA));

        /* Reach desireIncl*/
        RELAY_UpReset();
        delay_ms(100);
        break;
    case F_DOWN:
        RELAY_UpReset();
        delay_ms(100);
        RELAY_Down();
        do
        {
            resutlAdc = readResultConvert();
        } while (resutlAdc < (desireIncl - DELTA) || resutlAdc > (desireIncl + DELTA));

        /* Reach desireIncl*/
        RELAY_DownReset();
        delay_ms(100);
        break;
    default:
        return 0;
        break;
    }
    /* Start run*/
    return 0;
}

int floor_Down(uint16_t desireIncl)
{
    
}