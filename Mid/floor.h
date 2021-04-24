#ifndef _FLOOR_H_
#define _FLOOR_H_

typedef enum{
    F_UP =0,
    F_DOWN = 1,
    F_DEFAULT
}directionFloor_t;

int floor_UpDown(uint16_t desireLevel);
int floor_Down(uint16_t desireLevel);
#endif /* _FLOOR_H_*/