#include "stm32f103xb.h"


#define PRIGROUP_16G_0S ((const uint32_t) 0x03)				// Priority group definitions
#define PRIGROUP_8G_2S ((const uint32_t) 0x04)
#define PRIGROUP_4G_4S ((const uint32_t) 0x05)
#define PRIGROUP_2G_8S ((const uint32_t) 0x06)
#define PRIGROUP_0G_16S ((const uint32_t) 0x07)


int main(void) {
	RCC->APB2ENR = RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN;	// Enable CLK for GPIOC and AFIO
	RCC->APB1ENR = RCC_APB1ENR_TIM3EN;						// Enable CLK for TIM3

	GPIOC -> CRL |= GPIO_CRL_MODE2_1;						// Set GPIOB_8 as output mode 2MHz
	GPIOC -> CRL &= ~GPIO_CRL_CNF2_0;						// Set GPIOB_8 as Push-Pull output
	GPIOC -> CRL |= GPIO_CRL_MODE3_1;						// Set GPIOB_9 as output mode 2MHz
	GPIOC -> CRL &= ~GPIO_CRL_CNF3_0;						// Set GPIOB_9 as Push-Pull output

	AFIO -> EXTICR[3] = AFIO_EXTICR4_EXTI13_PC;				// Set GPIOC_13 as EXTI AFIO

	EXTI->IMR = EXTI_IMR_MR13;								// Dunno what it does yet
	EXTI->FTSR = EXTI_FTSR_TR13;							// Dunno what it does yet

	TIM3->PSC = 8000-1;										// Set prescaler
	TIM3->ARR = 500-1;										// Dunno what it does
	TIM3->DIER = TIM_DIER_UIE;								// Dunno what it does
	TIM3->EGR = TIM_EGR_UG;									// Dunno what it does
	TIM3->CR1 = TIM_CR1_CEN;								// Dunno what it does

	SysTick_Config(8000000/6);								// Configure SysTick

	NVIC_SetPriorityGrouping(PRIGROUP_4G_4S);				// Create priority 4 group with 4 subgroup

	uint32_t prio;

	prio = NVIC_EncodePriority(PRIGROUP_4G_4S, 1, 0);		// Encode priority
	NVIC_SetPriority(TIM3_IRQn, prio);						// Set priority

	prio = NVIC_EncodePriority(PRIGROUP_4G_4S, 2, 0);		// Encode priority
	NVIC_SetPriority(EXTI15_10_IRQn, prio);					// Set priority

	prio = NVIC_EncodePriority(PRIGROUP_4G_4S, 3, 0);		// Encode priority
	NVIC_SetPriority(SysTick_IRQn, prio);					// Set priority

	NVIC_EnableIRQ(EXTI15_10_IRQn);							// Enable EXTI
	NVIC_EnableIRQ(TIM3_IRQn);								// Enable TIM3I

	while (1);												// Forever loop
} /* main */


__attribute__((interrupt)) void TIM3_IRQHandler(void){		// TIM3 interrupt handler
	TIM3->SR = ~TIM_SR_UIF;									// Dunno what it does yet
	GPIOC->ODR ^= GPIO_ODR_ODR2;							// Toggle diode
}
__attribute__((interrupt)) void EXTI15_10_IRQHandler(void){	// EXTI interrupt handler
	EXTI->PR = EXTI_PR_PR13;								// Dunno what it does yet
	while(1);												// Forever loop
}
__attribute__((interrupt)) void SysTick_Handler(void){		// SysTick interrupt handler
	GPIOC->ODR ^= GPIO_ODR_ODR3;							// Toggle diode
}
