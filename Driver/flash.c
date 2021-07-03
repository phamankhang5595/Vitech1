#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "flash.h"

#define PAGE_ERASE_AP 0x22
#define BYTE_PROGRAM_AP 0x21
volatile unsigned char code Data_Flash[128] _at_ 0x3700;

static void FLASH_enable_IAP_mode()
{
    TA = 0Xaa;
    TA = 0x55;
    CHPCON |= 0x01;
}

static void FLASH_enable_APROM_update()
{
    TA = 0Xaa;
    TA = 0x55;
    IAPUEN |= 0x01;
}

static void FLASH_erasePage(uint16_t add)
{
    IAPCN = PAGE_ERASE_AP;
    IAPAH = (add >> 8) & 0xff;
    IAPAL = add & 0xff;
    IAPFD = 0Xff;
    TA = 0Xaa;
    TA = 0x55;
    IAPTRG |= 0x01;
}

static void FLASH_writeToAdd(uint16_t add, uint8_t dt)
{  
    IAPCN = BYTE_PROGRAM_AP;
    IAPAH = (add >> 8) & 0xff;
    IAPAL = add & 0xff;
    IAPFD = dt;
    TA = 0Xaa;
    TA = 0x55;
    IAPTRG |= 0x01;
}

static void FLASH_disable_APROM_update()
{
    TA = 0Xaa;
    TA = 0x55;
    IAPUEN &= ~0x01;
}
static void FLASH_disable_IAP_mode()
{
    TA = 0Xaa;
    TA = 0x55;
    CHPCON &= ~0x01;
}
void FLASH_write(uint16_t add, uint16_t dt)
{
    FLASH_enable_IAP_mode();
    FLASH_enable_APROM_update();
    //FLASH_erasePage(add);
    FLASH_writeToAdd(add, (dt >> 8) & 0xff);
    FLASH_writeToAdd(add + 1, dt & 0xff);
    FLASH_disable_APROM_update();
    FLASH_disable_IAP_mode();
}
uint16_t FLASH_read(uint16_t add)
{
    uint16_t i;
    uint16_t val;
    uint8_t highVal;
    uint8_t lowVal;
    for ( i = 0; i < 128; i++)
    {
        if (add == (uint16_t)&Data_Flash[i])
        {
            highVal = Data_Flash[i];
            lowVal  = Data_Flash[i+1];
        }
        val = (highVal << 8) | lowVal;
    }
    return val;
}