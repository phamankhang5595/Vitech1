/*
 *  irfapp_main.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef IRFAPP_MAIN_H_
#define IRFAPP_MAIN_H_
/******************************************************************************/
/*                              DEFINE                                        */
/******************************************************************************/
/* Command type */
#define MASTER_REQUEST_TYPE              0xB0
#define MASTER_REPONSE_TYE               0xB1
#define SLAVE_REQUEST_TYPE               0xA0
#define SLAVE_REPONSE_TYPE               0xA1

/* Command */

/* Start */
#define START_RUN                       0x30

/* Stop */
#define STOP_RUN                        0x40

/* SET SPEED MOTOR */
#define SET_SPEED_MOTOR_UP              0x80
#define SET_SPEED_MOTOR_DOWN            0x81

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
void APP_Proc(void);
void APP_CheckCommandExistAndTurnFlag(u8 command, u8 type, u8* buff, u8 length);

#endif /*IRFAPP_MAIN_H_*/