#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "irfapp_main.h"
#include "main_func.h"
#include "irf.h"
#include "motor.h"
#include "relay.h"
/*******************************************************************************
 * Variable
 ******************************************************************************/
/* flag */
extern volatile uint8_t startRunFlag = 0;
extern volatile uint8_t stopRunFlag = 0;
extern volatile uint8_t setSpeedMotorUpFlag = 0;
extern volatile uint8_t setSpeedMotorDownFlag = 0;

uint16_t currentDuty;

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

/**
 * @func   funcHandle_AllFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_AllFlag(void)
{
    if(startRunFlag==1||stopRunFlag==1||setSpeedMotorUpFlag==1||setSpeedMotorDownFlag==1)
    {
        if(startRunFlag == 1)
        {   
            funcHandle_StartRunFlag();

        }else if(stopRunFlag == 1)
        {
            funcHandle_StopRunFlag();

        }else if(setSpeedMotorUpFlag == 1)
        {
            funcHandle_SetSpeedMotorUpFlag();
        }
    }
}

/**
 * @func   funcHandle_StartRunFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_StartRunFlag(void)
{
    /* clear flag */
    startRunFlag = 0;
    /* respon to master */
    //IRF_Send(startRun, sizeof(startRun));
    /* turn on relay */
    //RELAY_AC(ON);
    /* start motor at default speed ?*/
    MOTOR_SetSpeed(DEFAULTDUTY, DEFAULTSPEEP);
    /* get current duty */
    currentDuty = DEFAULTSPEEP;
}
/**
 * @func   funcHandle_StopRunFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_StopRunFlag(void)
{
    /* clear flag */
    stopRunFlag = 0;
    MOTOR_SetSpeed(currentDuty, DEFAULTDUTY);    /* set defalut speed */
}

/**
 * @func   funcHandle_SetSpeedMotorUpFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_SetSpeedMotorUpFlag(void)
{
    uint8_t desireDuty = currentDuty - 500;
    /* turn off flag */
    setSpeedMotorUpFlag = 0;
    if(currentDuty>8000)
    {
        MOTOR_SetSpeed(currentDuty, desireDuty);
        currentDuty = desireDuty;
    }
}

/**
 * @func   funcHandle_SetSpeedMotorDownFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_SetSpeedMotorDownFlag(void)
{
    uint8_t desireDuty = currentDuty + 500;
    /* turn off flag */
    setSpeedMotorUpFlag = 0;
    if(currentDuty<15000)
    {
        MOTOR_SetSpeed(currentDuty, desireDuty);
        currentDuty = desireDuty;
    }
}
/*******************************************************************************
 * EOF
 ******************************************************************************/
