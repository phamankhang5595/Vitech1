/*
 *      main_init.c
 *
 *      Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
//#include "tick.h"
#include "irf.h"
#include "motor.h"
#include "relay.h"
#include "floor.h"
#include "adc.h"
#include "main_init.h"
#include "gpio.h"

/******************************************************************************/
/*                              DECLARE                                      */
/******************************************************************************/

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
/**
 * @func    main_Init
 * @brief   None
 * @param   None
 */
void MAIN_Init(void)
{
    MOTOR_Config();
    RELAY_Config();
    MOTOR_Init(DEFAULTSPEED);
    FLOOR_Init();
    //TICK_Init();
    IRF_Init();
    GPIO_P10_Config();
    ENABLE_AllInterrupt();
}

/**
 * @func    MAIN_Proc
 * @brief   None
 * @param   None
 */
//void MAIN_Proc(void)
//{
//    IRF_Proc(); 
//}