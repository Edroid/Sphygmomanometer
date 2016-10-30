#ifndef __STM32F4_LED_H
#define __STM32F4_LED_H

#include "stm32f4xx.h"

#define ON	1
#define OFF	0
#define LED_STATUS 0

enum
{
	LED_Red = 0,
	LED_Blue = 1,
	MAX_LED,
};

typedef struct led_gpio_s
{
	int num; 	              /*led���*/
	GPIO_TypeDef	*group;   /*LEDʹ�õ�����һ��GPIO*/
	u16	pin;                /*LEDʹ�õ�GPIO������һ��pin*/
}led_gpio_t;

extern void Init_LED_GPIO(void);
extern void turn_led(int whitch,int cmd);

#endif

