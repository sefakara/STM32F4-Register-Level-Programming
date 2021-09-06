/********************************************************************
** 						 Buton Kontrol							   **
** Sefa Kara 06.09.2021											   **
** Register seviyesinde kullanici butonu ile led konrtol edilmesi. **
** Kullanilan registerlar:										   **
** mode register, type register, pull-up/pull-down register, 	   **
** output data register ve clock enable register.				   **
********************************************************************/


#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"



void GPIO_Config(void);

void Delay(uint32_t time){
	while(time--);
}



int main(void){

	GPIO_Config();

	while(1){
		if(GPIOB->IDR & 0x00000001){
			while(GPIOB->IDR & 0x00000001);
			GPIOG->ODR = 0x00002000;
			Delay(4500000); //Arký onlemek icin 200ms
		}
		else
			GPIOG->ODR = 0x00004000;
	}
}


void GPIO_Config(){
	RCC->AHB1ENR 	= ((uint32_t)0x00000042);	//B ve G portu aktif

	GPIOG->MODER    = ((uint32_t)0x14000000);	//13 ve 14 out
	GPIOG->OTYPER   = ((uint32_t)0x00000000);	//Push-pull
	GPIOG->OSPEEDR  = ((uint32_t)0x3C000000);	//Very high
	GPIOG->PUPDR    = ((uint32_t)0x00000000);	//no pull up-pull down

	GPIOB->MODER	= ((uint32_t)0x00000000);	//0 input(reset state)
	GPIOB->OTYPER	= ((uint32_t)0x00000000);	//Push-pull
	GPIOB->OSPEEDR  = ((uint32_t)0x00000003);	//Very high(0.pin)
	GPIOB->PUPDR	= ((uint32_t)0x00000002);	//0 pull down
}





uint32_t sEE_TIMEOUT_UserCallback(void)
{
  /* TODO, implement your code here */
  while (1)
  {
  }
}
