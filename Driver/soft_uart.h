#ifndef _SOFT_UART_H_
#define _SOFT_UART_H_

void TICK_Count(void);
void SOFT_UART_Init(uint16_t baudRate);
void SOFT_UART_SendByte(uint8_t dataByte);
void SOFT_UART_SendData(uint8_t *str);
#endif /* _SOFT_UART_H_*/