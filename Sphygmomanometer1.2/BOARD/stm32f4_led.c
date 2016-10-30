//ע�⣺stm32ʹ���κ����趼����Ҫʹ�������ʱ�ӣ�GPIOҲ��һ��
#include "stm32f4_led.h"
#include "sys.h"

static led_gpio_t   leds_gpio[MAX_LED] =
{
		{LED_Red, GPIOF, GPIO_Pin_9}, 
    {LED_Blue, GPIOF, GPIO_Pin_10},
};


void Init_LED_GPIO(void)
{
	GPIO_InitTypeDef GPIO_Initstructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_OUT;             //
	GPIO_Initstructure.GPIO_OType = GPIO_OType_PP;            //�������
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;     //
	GPIO_Initstructure.GPIO_PuPd = GPIO_PuPd_UP;             //��������
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_100MHz;        //
	
	GPIO_Init(GPIOF,&GPIO_Initstructure);
}


void turn_led(int witch,int cmd)
{
	if(witch<0 || witch>MAX_LED)
		return ;
	if(OFF == cmd)
		GPIO_SetBits(leds_gpio[witch].group,leds_gpio[witch].pin);
	if(ON == cmd)
		GPIO_ResetBits(leds_gpio[witch].group,leds_gpio[witch].pin);
}

