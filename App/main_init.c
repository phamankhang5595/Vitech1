#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "uart.h"
#include "delay.h"
#include "relay.h"
#include "motor.h"
#include "pwm.h"
#include "timer.h"
#include "queue.h"
#include "irf.h"
#include "main_init.h"
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief 
 *
 * @param 
 * @param 
 */
void Main_Init()
{
    MOTOR_Config();
    RELAY_Config();
    RELAY_AC(ON);
    MOTOR_Init(DEFAULTDUTY);
    IRF_Init();
	MOTOR_SetSpeed(15000, 13500);
    MOTOR_SetSpeed(13500, 15000);
}