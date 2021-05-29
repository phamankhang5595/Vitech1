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


volatile uint8_t deviceAnnounceFlag = 0;
volatile uint8_t checkConnectFlag = 0;
volatile uint8_t startRunFlag = 0;
volatile uint8_t stopRunFlag = 0;
volatile uint8_t updownFloorFlag = 0;
volatile uint8_t getStateMotorFlag = 0;
volatile uint8_t getStateFloorFlag = 0;
volatile uint8_t setSpeedMotorFlag = 0;
volatile uint8_t getAllStateFlag = 0;
volatile uint8_t resetDeviceFlag = 0;
volatile uint8_t speedValue = 0;
volatile uint8_t floorValue = 1;

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
static void APP_DeviceAnnounce();

static void APP_CheckConnect();

static void APP_StartRun();

static void APP_StopRun();

static void APP_UpDownFloor(u8 *buff);

static void APP_GetStateMotor();

static void APP_GetStateFloor();

static void APP_SetSpeedMotor(u8 *buff);

static void APP_GetAllState();

static void APP_ResetDevice();

/**
 * @func   APP_CheckCommandExistAndExecutes
 * @brief  None
 * @param  
 * @retval None
 */
void APP_CheckCommandExistAndExecutes(u8 command, u8 type, u8* buff, u8 length)
{
    u8 type1=type;
    u8 length1=length;
    switch (command)
    {
    case DEVICE_ANNOUNCE:
        APP_DeviceAnnounce();
        break;
    case CHECK_CONNECT:
        APP_CheckConnect();
        break;
    case START_RUN:
        APP_StartRun();
        break;
    case STOP_RUN:
        APP_StopRun();
        break;
    case UP_DOW_FLOOR:
        APP_UpDownFloor(buff);
        break;
    case GET_STATE_MOTOR:
        APP_GetStateMotor();
        break;
    case GET_STATE_FLOOR:
        APP_GetStateFloor();
        break;
    case SET_SPEED_MOTOR:
        APP_SetSpeedMotor(buff);
        break;
    case GET_ALL_STATE:
        APP_GetAllState();
        break;
    case RESET_DEVICE:
        APP_ResetDevice();
        break;
    default:
        break;
    }
}


/**
 * @func   APP_DeviceAnnounce
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_DeviceAnnounce()
{
    deviceAnnounceFlag = 1;
}

/**
 * @func   APP_CheckConnect
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_CheckConnect()
{
	checkConnectFlag = 1;
}

/**
 * @func   APP_StartRun
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_StartRun()
{
    startRunFlag = 1;
}

/**
 * @func   APP_StopRun
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_StopRun()
{
    stopRunFlag = 1;
}

/**
 * @func   APP_UpDownFloor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_UpDownFloor(u8 *buff)
{
    updownFloorFlag = 1;
    floorValue = buff[0];
}

/**
 * @func   APP_GetStateMotor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_GetStateMotor()
{
    getStateMotorFlag = 1;

}

/**
 * @func   APP_GetStateFloor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_GetStateFloor()
{
    getStateFloorFlag = 1;
}

/**
 * @func   APP_SetSpeedMotor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_SetSpeedMotor(u8 *buff)
{
    setSpeedMotorFlag = 1;
    speedValue = buff[0];
}

/**
 * @func   APP_GetAllState
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_GetAllState()
{
    getAllStateFlag = 1;
}   

/**
 * @func   APP_ResetDevice
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_ResetDevice()
{
    resetDeviceFlag = 1;
}