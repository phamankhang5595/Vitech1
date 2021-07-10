/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/


#ifndef UART_H_

#define UART_H_


/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

#define UART_BAUDRATE           9600
typedef void (*type_UartCallBackFnc)(void);

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

void UART_Init(uint32_t baudRate);
void UART_Enable(void);
void UART_Disable(void);
void UART_SendByte (u8 byte);
void UART_SendData (u8* buff, u8 length);
u8   UART_RevData (void);
//void MODIFY_Hirc166(void);
void UART_CallBackInit(type_UartCallBackFnc uartCallBackFnc);

#endif    /* UART_H_ */