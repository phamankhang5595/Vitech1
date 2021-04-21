/*
 * Copyright (c) 2021
 * Vitech Solutions
 * All Rights Reserved
 *
 *
 * Description:
 *
 * Author: Truongvv
 *
 * Last Changed By:  $Author: Truongvv $
 * Revision:         $Revision: 1.0 $
 * Last Changed:     $Date: x/x/xxxx $
 */
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "uart.h"
#include "delay.h"
#include "relay.h"
#include "motor.h"
#include "pwm.h"
#include "queue.h"
#include "adc.h"
/*******************************************************************************
 * Definition
 ******************************************************************************/

uint16_t topLimitFloor;
uint16_t botLimitFloor;

/* Command */
#define START_RUN    0x01
#define STOP_RUN     0x02
#define SPEED_UP     0x03
#define SPEED_DOWN   0x04

//queue
#define QueueSize  6
/*******************************************************************************
 * Variable
 ******************************************************************************/

QUEUEx_t CommandQueue;
u8 CommandBuff[QueueSize];
unsigned int currentDuty=DEFAULTDUTY;

void handleUart(void)
{
   static u8 revByte = 0;
   revByte = UART_RevData();
   QUEUE_Push(&CommandQueue,&revByte);
}

void main(void)
{
    uint16_t convert;
    char ch;
		// MOTOR_Config();
    // delay_ms(1000);
    // RELAY_Config();
    // RELAY_AC(1);         
    // delay_ms(1000);
    // MOTOR_Init(120);
    while(1)
    {
			  //MOTOR_SetSpeed(120,120);
        // MOTOR_SetSpeed(120,50);
        // delay_ms(500);
        // MOTOR_SetSpeed(50,10);
        // delay_ms(500);
        // MOTOR_SetSpeed(10,120);
        // delay_ms(500);
    }
}
