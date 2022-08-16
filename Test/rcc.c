#include "rcc.h"
     
void rcc_init(void)
{
	
	RCC->CR |= RCC_CR_HSION;	
  RCC->CFGR |= RCC_CFGR_SW_PLL;
	RCC->CR |= RCC_CR_PLLON;
  while(! (RCC->CR & RCC_CR_PLLRDY) )
	{
		__ASM("NOP");
	}
	//RCC->CFGR |=RCC_CFGR_SWS_PLL;
	

	RCC->CFGR &= ~RCC_CFGR_PLLSRC;
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSI_PREDIV;
	RCC->CFGR2 &= ~RCC_CFGR2_PREDIV;
	RCC->CFGR &= ~RCC_CFGR_PLLMUL;
	RCC->CFGR |= RCC_CFGR_PLLMUL6;
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	
	RCC->CFGR |= RCC_CFGR_PPRE_2;
	RCC->CFGR |= RCC_CFGR_HPRE_2;
	
	
	
		
		
		

  while(!(RCC->CR &=RCC_CR_HSIRDY)){
	__ASM("NOP");
	}
	
}
