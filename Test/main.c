#include "rcc.h"                 
#include "RTE_Components.h"   
#include "TIM.h"

int main (void){
	
	rcc_init();
	
	GPIOA->MODER &= ~(3UL << 10);
	GPIOA->MODER |= (1UL << 10);
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_5;
	GPIOA->OSPEEDR |= (3 << 10);
	GPIOA->OTYPER &=~GPIO_OTYPER_OT_8;
	
	tim_innit();
	
	
	while(1){
		
	//GPIOA->BSRR |= GPIO_BSRR_BS_5;


		
		
	}
	
	
}
		
		
		
		
		
