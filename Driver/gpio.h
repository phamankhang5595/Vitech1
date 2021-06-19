#ifndef _GPIO_H_
#define _GPIO_H_

typedef void (*type_GpioCallBackFnc)(void);

void GPIO_P10_Config();
void GPIO_P01_Config();
void GPIO_CallBackInit(type_GpioCallBackFnc gpioCallBackFun);
#endif /*_GPIO_H_*/