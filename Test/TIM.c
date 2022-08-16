#include "TIM.h"
#include "rcc.h"
void tim_innit (void){

  RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
  
	TIM6->PSC = (unsigned short)2399;
	TIM6->CR1 |= TIM_CR1_ARPE;
	TIM6->CNT = 0;
	TIM6->ARR= 49;
	TIM6->CR1 |=TIM_CR1_CEN;
	TIM6->DIER |=TIM_DIER_UIE;
  NVIC_EnableIRQ(TIM6_IRQn);
	NVIC_SetPriority(TIM6_IRQn,2);
	




}

void TIM6_DAC_IRQHandler(void){
	
if (TIM6->SR &=(1UL << 0)){
	
 if (GPIOA->ODR &=(1UL << 5)) {
		GPIOA->BRR |=GPIO_BRR_BR_5;
	}
	
  else {
	
	GPIOA->BSRR |=GPIO_BSRR_BS_5;
	
	}

	TIM6->SR = 0;
//}
	//GPIOA->ODR ^= (1 << 5);

}
}


