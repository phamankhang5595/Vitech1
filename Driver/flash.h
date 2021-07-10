/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/

#ifndef _FLASH_H_
#define _FLASH_H_

#define FLASH_ADDS_TOP_LIM_VAL 0x3700
#define FLASH_ADDS_BOT_LIM_VAL 0x3705

void FLASH_write(uint16_t add, uint16_t dt);
uint16_t FLASH_read(uint16_t add);
#endif /*_FLASH_H_*/