/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/


#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "motor.h"
#include "pwm.h"
#include "delay.h"

volatile int checkStopCmd = 0;
/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

/**
 * @func    MOTOR_Config
 * @brief   None
 * @param   None
 */
void MOTOR_Config(void)
{
    PWM_PinInit();
    delay_ms(500);
}
/**
 * @func    MOTOR_Init
 * @brief   None
 * @param   None
 */
void MOTOR_Init(uint16_t defaultDuty)
{
    PWM_Init();
    PWM_SetDuty(defaultDuty);
}
/**
 * @func    MOTOR_GetCurrentSpeed
 * @brief   None
 * @param   None
 */
uint16_t MOTOR_GetCurrentSpeed(void)
{
    return ((PWM0H << 8) | (PWM0L));
}
/**
 * @func    MOTOR_SetSpeed
 * @brief   None
 * @param   None
 */
void MOTOR_SetSpeed(uint16_t currentDuty, uint16_t desireDuty)
{
    uint16_t i = 0;
    if(currentDuty > desireDuty)
    {
        for(i = currentDuty; i > desireDuty && checkStopCmd != 1; i--)
        {
            PWM_SetDuty(i);
            delay_ms(10);
        }
    }else
    {
        for(i = currentDuty; i < desireDuty && checkStopCmd != 1; i++)
        {
            PWM_SetDuty(i);
            delay_ms(10);
        }
    }
    checkStopCmd = 0;
}
void MOTOR_SetStop(uint16_t currentDuty)
{
    uint16_t i = 0;
    for(i = currentDuty; i > DEFAULTDUTY ; i--)
    {
        PWM_SetDuty(i);
        delay_ms(20);
    }
}