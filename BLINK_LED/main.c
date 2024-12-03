// Blink led
#include "stm32f10x.h"

int main() 
{
	//initalize the Clock for the Port C
	RCC -> APB2ENR = (1<<4);
	
	//configure Pin 13 on GPIOC 
	GPIOC -> CRH |=  (	(1<<20) | (1<<21));	//OUTPUT Mode 50KHz
	GPIOC -> CRH &=  ~( (1<<22) |  (1 <<23));	//SET GPIO Outpuyt
	
	while (1)
	{
		for (int i = 0; i <= 500000; i ++); // Wait 0.5s
		GPIOC -> BSRR = (1<<13); 	//SET Pin 13 High
		for (int i = 0; i <= 500000; i++); // Wait 0.5s
		GPIOC -> BSRR = (1 <<(13+16)); //Reset Pin 13 (low)
		
	}
}