#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "adc.h"
#include "gpio.h"
#include "relay.h"
#include "delay.h"
#include "timer.h"
#include "flash.h"
#include "floor.h"

uint16_t topLimitFloor;
uint16_t botLimitFloor;
uint16_t adc_retval[12];
uint16_t resutlAdc;

#define DELTA (topLimitFloor - botLimitFloor)

static void get_adc_levels()
{
    int i;
    for ( i = 0; i < 12; i++)
    {
        adc_retval[i] = botLimitFloor + i * (DELTA / 12);
    }
}

void FLOOR_GetTopAndBotLimitValue(void)
{

    uint16_t newValue = 0;
    uint16_t tempValue = 0;
    RELAY_Up();
    delay_ms(50);
    newValue = ADC_ReadResultConvert();
    while (tempValue != newValue)
    {
        tempValue = newValue;
        delay_ms(100);
        newValue = ADC_ReadResultConvert();
    }
    
    RELAY_UpReset();
    FLASH_write(FLASH_ADDS_TOP_LIM_VAL, newValue);
    delay_ms(1000);

    tempValue = 0;
    RELAY_Down();
    //newValue = ADC_ReadResultConvert();
    while (tempValue != newValue)
    {
        tempValue = newValue;
        delay_ms(100);
        newValue = ADC_ReadResultConvert();
    }
    RELAY_DownReset();
    FLASH_write(FLASH_ADDS_BOT_LIM_VAL, newValue);
    
    /**/
}

void FLOOR_Init(void)
{
    ADC_Init();
    topLimitFloor = FLASH_read(FLASH_ADDS_TOP_LIM_VAL);
    botLimitFloor = FLASH_read(FLASH_ADDS_BOT_LIM_VAL);
    if (topLimitFloor != 0xFFFF && botLimitFloor != 0xFFFF)
    {
        get_adc_levels();
    }
}

int FLOOR_UpOrDown(uint16_t desireIncl)
{
    int i;
    directionFloor_t dir = F_DEFAULT;
    uint16_t incline_level[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    /* Check input*/
    if(desireIncl < 1 | desireIncl > 12)
    {
        return -1;
    }

    for (i = 0; i < 12; i++)
    {
        if (desireIncl == incline_level[i])
        {
            desireIncl = adc_retval[i];
            break;
        }
    }
    /* Get current value of adc*/
    resutlAdc = ADC_ReadResultConvert();
    /*  Check Incline will increase or decrease*/
    if ( resutlAdc <  desireIncl) {
        dir = F_UP;
    }
    else if( resutlAdc >= desireIncl && resutlAdc <= desireIncl ) {
        return 0;
    }
    else {
        dir = F_DOWN;
    }

    switch (dir) {
    case F_UP:
        RELAY_DownReset();
        delay_ms(10);
        RELAY_Up();
        do {
            resutlAdc = ADC_ReadResultConvert();
        } while (resutlAdc < desireIncl);

        /* Reach desireIncl*/
        RELAY_UpReset();
        break;
    case F_DOWN:
        RELAY_UpReset();
        delay_ms(10);
        RELAY_Down();
        do {
            resutlAdc = ADC_ReadResultConvert();
        } while (resutlAdc > desireIncl);

        /* Reach desireIncl*/
        RELAY_DownReset();
        break;
    default:
        return 0;
        break;
    }
    /* Start run*/
    return 0;
}
