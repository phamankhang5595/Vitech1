#include "N76E003.h" 
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "adc.h"

void init_ADC()
{
    P17_Input_Mode;
    set_ADCEN;
    clr_ADCF;
    ADCCON0 &= 0xF0;
    AINDIDS |= (1<<0);
}

void enable_ADC()
{
    ADCCON0 |= (1 << 6);
}

uint16_t resultConvert()
{
    uint16_t lowByte = 0;
    uint16_t highByte = 0;
    uint16_t resutl = 0;

    lowByte = ADCRL & 0x0F;
    highByte = ADCRH;

    resutl = (highByte << 4) | lowByte;
    return resutl;
}