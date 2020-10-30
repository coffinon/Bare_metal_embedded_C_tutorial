#include "stm32f103xb.h"

int main(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN + RCC_APB2ENR_IOPAEN;

    GPIOA->CRL |= GPIO_CRL_MODE5_1;
    GPIOA->CRL &= ~GPIO_CRL_CNF5_0;
    GPIOA->CRH |= GPIO_CRH_CNF8_1;
    GPIOA->CRH &= ~GPIO_CRH_CNF8_0;

    TIM1->CCER = TIM_CCER_CC1P;
    TIM1->SMCR = TIM_SMCR_SMS | TIM_SMCR_TS_0 | TIM_SMCR_TS_2;

    TIM1->ARR = 10;
    TIM1->DIER = TIM_DIER_UIE;
    TIM1->CR1 = TIM_CR1_CEN;

    NVIC_EnableIRQ(TIM1_UP_IRQn);

    SysTick_Config(800000);

    while(1){
		__WFI();
	}
}


__attribute__((interrupt)) void SysTick_Handler(){
	GPIOA -> ODR ^= GPIO_ODR_ODR8;
}


__attribute__((interrupt)) void TIM1_UP_IRQHandler(void){
	if (TIM1->SR & TIM_SR_UIF){
		TIM1->SR = ~TIM_SR_UIF;
		GPIOA -> ODR ^= GPIO_ODR_ODR5;
	 }
}
