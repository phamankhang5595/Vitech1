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
/*******************************************************************************
 * Definition
 ******************************************************************************/

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
    uint8_t buffer;
    uint16_t currentDuty = DEFAULTDUTY;
    //delay_ms(10000);
    //p10 gpio
    MOTOR_Config();
    delay_ms(1000);
    RELAY_Config();
    RELAY_AC(1);
    delay_ms(1000);
    MOTOR_Init(850);
    QUEUE_Init(&CommandQueue, CommandBuff, QueueSize, sizeof(u8)); //
    //uart init
    UART_Init(1200);
    UART_CallBackInit(handleUart);
    ENABLE_AllInterrupt();
    UART_Enable();
//    currentDuty = DEFAULTDUTY;
    while(1)
    {
//        if(!QUEUE_Empty(&CommandQueue))
//        {
//            QUEUE_Get(&CommandQueue,&buffer);
//            switch (buffer)
//            {
//                case START_RUN:
//                    MOTOR_SetSpeed(currentDuty,DEFAULTSPEED);
//                    currentDuty = DEFAULTSPEED;
//                    break;
//                case STOP_RUN:
//                    MOTOR_SetSpeed(currentDuty,DEFAULTDUTY);
//                    currentDuty = DEFAULTDUTY;
//                    break;
//                case SPEED_UP:
//                    if(currentDuty>50)
//                    {
//                        MOTOR_SetSpeed(currentDuty,currentDuty-50);
//                        currentDuty -= 50;
//                    }
//                    break;
//                case SPEED_DOWN:
//                    if(currentDuty<500)
//                    {
//                        MOTOR_SetSpeed(currentDuty,currentDuty+50);
//                        currentDuty += 50;
//                    }
//                    break;
//                default: 
//                    break;
//            }
//        } 
//    }
    }
}
