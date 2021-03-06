#include "timer.h"

void Tim_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	TIM1->CCMR1 = TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
	TIM1->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
	TIM1->CCMR2 = TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;

	TIM1->CCER = TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E;
	TIM1->BDTR = TIM_BDTR_MOE;

	TIM1->PSC = 7;
	TIM1->ARR = 99;
	TIM1->CCR1 = 10;
	TIM1->CCR2 = 30;
	TIM1->CCR3 = 80;

	TIM1->CR1 = TIM_CR1_CEN;
}
