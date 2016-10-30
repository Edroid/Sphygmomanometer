#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "stm32f4_led.h"


int main(void)
{
	u32 t=0;
	Init_LED_GPIO();
	uart_init(115200);
	delay_init(84);
	
  while(1)
		{
    printf("t:%d\r\n",t);
		turn_led(LED_Red,ON);
		delay_ms(1000);
		turn_led(LED_Blue,ON);
	  delay_ms(1000);
		turn_led(LED_Red,OFF);
		delay_ms(1000);
		turn_led(LED_Blue,OFF);
		delay_ms(1000);
		t++;
	}
}

