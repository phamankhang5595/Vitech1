/* 
Copyright (c) Jul 2021
 * Company: VITECH Solution
 * Group: 
 * Author: Bui Xuan Hung 
*/

#ifndef _FLOOR_H_
#define _FLOOR_H_

typedef enum{
    F_UP =0,
    F_DOWN = 1,
    F_DEFAULT
}directionFloor_t;
void FLOOR_Init(void);
int FLOOR_UpOrDown(uint16_t desireLevel);
void FLOOR_GetTopAndBotLimitValue(void);
#endif /* _FLOOR_H_*/
