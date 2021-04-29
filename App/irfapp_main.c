/*
 *      irfapp_main.c
 *
 *      Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "irfapp_main.h"
#include "irf.h"
/*******************************************************************************
 * Varialbe
 ******************************************************************************/
/* Flag */
volatile uint8_t startRunFlag = 0;
volatile uint8_t stopRunFlag = 0;
volatile uint8_t setSpeedMotorUpFlag = 0;
volatile uint8_t setSpeedMotorDownFlag = 0;


/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
static void APP_StartRun(u8 type,u8 *buff, u8 length);

static void APP_StopRun(u8 type, u8 *buff, u8 length);

static void APP_SetSpeedMotor(u8 type, u8 *buff, u8 length);

static void APP_GetAllState(u8 type, u8 *buff, u8 length);

static void APP_ResetDevice(u8 type, u8 *buff, u8 length);

/*!
 * @brief 
 * @param 
 * @param 
 */
void APP_Proc(void)
{
    irf_Command_t irf_CommandBuff;
    if(IRF_GetCommand(&irf_CommandBuff))
    {
        APP_CheckCommandExistAndExecutes(irf_CommandBuff.command,
                                         irf_CommandBuff.type,
                                         irf_CommandBuff.buff,
                                         irf_CommandBuff.length);
    }
}
/**
 * @func   APP_CheckCommandExistAndExecutes
 * @brief  None
 * @param  
 * @retval None
 */
void APP_CheckCommandExistAndTurnFlag(u8 command, u8 type, u8* buff, u8 length)
{
    switch (command)
    {
    case START_RUN:
        APP_StartRun(type, buff, length);
        break;
    case STOP_RUN:
        APP_StopRun(type, buff, length);
        break;
    case SET_SPEED_MOTOR_UP:
        APP_SetSpeedMotorUP(type, buff, length);
        break;
    case SET_SPEED_MOTOR_DOWN:
        APP_SetSpeedMotorDown(type, buff, length);
        break;
    default:
        break;
    }
}

/* Executes func*/

static void APP_StartRun(u8 type,u8 *buff, u8 length)
{
    startRunFlag = 1;
}

/**
 * @func   APP_StopRun
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_StopRun(u8 type, u8 *buff, u8 length)
{
    stopRunFlag = 1;
}

/**
 * @func   APP_SetSpeedMotorUp
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_SetSpeedMotorUp(u8 type, u8 *buff, u8 length)
{
    setSpeedMotorUpFlag = 1;
}

/**
 * @func   APP_SetSpeedMotorUp
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_SetSpeedMotorDown(u8 type, u8 *buff, u8 length)
{
    setSpeedMotorDownFlag = 1;
}
/*******************************************************************************
 * EOF
 ******************************************************************************/
