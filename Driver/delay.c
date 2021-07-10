/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "tick.h"
#include "delay.h"

void delay_ms (uint16_t value)
{
    while(value)
    {
        delay_us(1000);
        value--;
    };
}

/**
 * @func   delay_us
 * @brief  None
 * @param  
 * @retval None
 */
void delay_us (uint16_t value)
{
	register uint16_t loops =  (uint16_t)(dly_const * value) ;
    
    while(loops)
    {
        _nop_();
        loops--;
    };
}
