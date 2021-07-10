/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/


#ifndef PWM_H

#define PWM_H


/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

#define PWM_PinInit()           P10_PushPull_Mode
#define PWM_PORT                P1
#define PWM_MaxDuty             (533u)
/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

void PWM_Init (void);
void PWM_SetDuty (uint16_t pwmDuty);
void PWM_Stop(uint16_t pwmDuty);
void PWM_Start(uint16_t pwmDuty);


#endif    /* PWM_H*/