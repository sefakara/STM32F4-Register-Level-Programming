/********************************************************************
 * 				 Led blink 			    *
 * Sefa Kara 06.09.2021						    *
 * Register seviyesinde kullanici ledlerinin blink edilmesi.	    *
 * Kullanilan registerlar:					    *
 * mode register, type register, pull-up/pull-down register, 	    *
 * output data register ve clock enable register.		    *
 *******************************************************************/

#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"


void GPIO_Config(void);
void Delay(uint32_t time);




int main(void)
{
	GPIO_Config();

	while(1){
		GPIOG->ODR    = 0x00006000;	//13 ve 14. pin high
		Delay(22500000);
		GPIOG->ODR    = 0x00000000; 	//13 ve 14. pin low
		Delay(22500000);

		//GPIOG->ODR    = 1<<13;	//13 pin high
		//Delay(22500000);
		//GPIOG->ODR    = 0<<13;        //13 pin low
		//Delay(22500000);
	}
}


void GPIO_Config(){

	RCC->AHB1ENR	= ((uint32_t)0x00000040);	//G portu aktif

	GPIOG->MODER	= ((uint32_t)0x14000000);	//13 ve 14. pin cikis
	GPIOG->OTYPER	= ((uint32_t)0x00000000);	//13 ve 14. pin output push-pull
	GPIOG->OSPEEDR	= ((uint32_t)0x3C000000);	//13 ve 14. pin very high speed
	GPIOG->PUPDR	= ((uint32_t)0x00000000);	//13 ve 14. pin no pull up/ pull down
	GPIOG->ODR      = ((uint32_t)0x60000000);	//13 ve 14. pin low
}


/*
 * Saat frekansi 180MHz
 * while dongusu ve cýkarma islemi 4'er cyle
 * 180000000/(4+4) = 22500000 ~ 1sn
 */
void Delay(uint32_t count)
{
	while(count--);
}







uint32_t sEE_TIMEOUT_UserCallback(void)
{
  /* TODO, implement your code here */
  while (1)
  {
  }
}
