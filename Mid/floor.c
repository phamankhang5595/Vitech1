#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "adc.h"
#include "relay.h"
#include "delay.h"
#include "floor.h"

#define STEP ((topLimitFloor - botLimitFloor) / 12)

extern uint16_t topLimitFloor;
extern uint16_t botLimitFloor;
uint16_t adc_retval[12];

static void read_adc()
{
    int i;
    for ( i = 0; i < 12; i++)
    {
        adc_retval[i] = botLimitFloor + i * STEP;
    } 
}

int floor_Up(uint16_t desireLevel)
{
		int i;
    uint16_t incline_level[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    /* Check input*/
    if(desireLevel < 1 | desireLevel > 12)
    {
        return -1;
    }

    read_adc();

    /* Convert incline from desire Level to adc value*/
    for (i = 0; i < 12; i++)
    {
        if (desireLevel = incline_level[i])
        {
            desireLevel = adc_retval[i];
            break;
        }
    } 
    /* Start run*/  
    RELAY_DownReset();
    delay_ms(100);
    RELAY_Up();
    
    clr_ADCF;
    enable_ADC();
    while (ADCF != 1);    

    while (resultConvert() != desireLevel)
    {
        clr_ADCF;
        enable_ADC();
        while (ADCF != 1);
    }
    /* Reach desireLevel*/
    RELAY_UpReset();
    delay_ms(100);   
    return 0;
}

int floor_Down(uint16_t desireLevel)
{
    if(desireLevel < 0 | desireLevel > 12)
    {
        return -1;
    }
    RELAY_UpReset();
    delay_ms(100);
    return 0;
}