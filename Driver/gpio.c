/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/

#include "Function_Define.h"
#include "N76E003.h"
#include "SFR_Macro.h"
#include "relay.h"
#include "adc.h"
#include "delay.h"
#include "tick.h"
#include "timer.h"
#include "gpio.h"

extern uint16_t topLimitFloor;
extern uint16_t botLimitFloor;

void GPIO_getValueMode()
{
    P17_Input_Mode;
    // Enable_INT_Port1;
    // Enable_BIT7_FallEdge_Trig;
    // //PICON |= (1 << 7);
    // set_EPI;
    // set_EA;
}

//void GPIO_P01_Config()
//{
//    P15_PushPull_Mode;
//    P15 = 0;
//}
