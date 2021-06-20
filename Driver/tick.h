#ifndef _TICK_H_
#define _TICK_H_

void TICK_Init(void);
void TICK_Count(void);
uint32_t Handle_Tick(void);
void TICK_Delay_ms(uint32_t time_ms);

#endif /*_TICK_H_*/