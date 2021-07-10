/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/


#ifndef MAINFUNCLIST_H
#define MAINFUNCLIST_H
/******************************************************************************/
/*                              INCLUDE                                      */
/******************************************************************************/

/******************************************************************************/
/*                              DEFINE                                      */
/******************************************************************************/

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
void funcHandle_AllFlag(void);
void funcHandle_DeviceAnnounceFlag(void);
void funcHandle_CheckConnectFlag(void);
void funcHandle_StartRunFlag(void);
void funcHandle_StopRunFlag(void);
void funcHandle_UpdownFloorFlag(void);
void funcHandle_GetStateMotorFlag(void);
void funcHandle_GetStateFloorFlag(void);
void funcHandle_SetSpeedMotorFlag(void);
void funcHandle_GetAllStateFlag(void);
//void funcHandle_ResetDeviceFlag(void);

#endif /*MAINFUNCLIST_H*/