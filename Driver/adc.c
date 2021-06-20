#include "N76E003.h" 
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "adc.h"

void ADC_Init()
{
    P05_Input_Mode;
    set_ADCEN;
    clr_ADCF;
    ADCCON0 &= 0xFF;
    ADCCON0 |= 0x05;
    AINDIDS |= (1<<4);
}

void ADC_Enable()
{
    clr_ADCF;
    ADCCON0 |= (1 << 6);
    while (ADCF != 1);
}

uint16_t ADC_ReadResultConvert()
{
    uint16_t lowByte = 0;
    uint16_t highByte = 0;
    uint16_t resutl = 0;
    
    ADC_Enable();
    
    lowByte = ADCRL & 0x0F;
    highByte = ADCRH;

    resutl = (highByte << 4) | lowByte;

    return resutl;
}
