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
#define DEFAULTDUTY     5
#define DEFAULTSPEED    0
#define MAXDUTY         130
/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

void MOTOR_Config(void);
void MOTOR_Init(uint16_t defaultDuty);
uint16_t MOTOR_GetCurrentSpeed(void);
void MOTOR_SetSpeed(uint16_t currentDuty, uint16_t desireDuty);
void MOTOR_SetStop(uint16_t currentDuty);
#endif /* MOTOR_H */