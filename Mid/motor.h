/*
 *      motor.h
 *
 *      Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef MOTOR_H
#define MOTOR_H
/*****************************************************************************/
/*                              DEFINE                                      */
/******************************************************************************/
#define DEFAULTDUTY     533
#define DEFAULTSPEED    490
/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

void MOTOR_Config(void);
void MOTOR_Init(uint16_t defaultDuty);
uint16_t MOTOR_GetCurrentSpeed(u8 revSpeed);
void MOTOR_SetSpeed(uint16_t currentDuty, uint16_t desireDuty);

#endif /* MOTOR_H */