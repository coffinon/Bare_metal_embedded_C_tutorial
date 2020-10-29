#include "stm32f103xb.h"

int main(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN + RCC_APB2ENR_TIM1EN;

    GPIOA->CRL |= GPIO_CRL_MODE5_1;
    GPIOA->CRL &= ~GPIO_CRL_CNF5_0;

    TIM1->PSC = 4000 - 1;
    TIM1->ARR = 1000 - 1;
    TIM1->DIER |= TIM_DIER_UIE;
    TIM1->CR1 |= TIM_CR1_CEN;

    NVIC_EnableIRQ(TIM1_UP_IRQn);
	while(1){
		__WFI();
	}
}


__attribute__((interrupt)) void TIM1_UP_IRQHandler(void){
	if (TIM1->SR & TIM_SR_UIF){
		TIM1->SR = ~TIM_SR_UIF;
		GPIOA -> ODR ^= GPIO_ODR_ODR5;
	 }
}
