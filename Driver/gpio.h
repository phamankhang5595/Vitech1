#ifndef _GPIO_H_
#define _GPIO_H_

typedef void (*type_GpioCallBackFnc)(void);
typedef enum
{
    NO = 0,
    YES
}boolen_t;
void GPIO_getValueMode();
void GPIO_P01_Config();
void GPIO_CallBackInit(type_GpioCallBackFnc gpioCallBackFnc);
#endif /*_GPIO_H_*/