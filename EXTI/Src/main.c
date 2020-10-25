#include "stm32f103xb.h"

int main(void)
{
    RCC -> APB2ENR = RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN;	// Enable CLK for GPIOC and AFIO


    GPIOC -> CRL |= GPIO_CRL_MODE2_1;						// Set GPIOC_2 as output mode 2MHz
    GPIOC -> CRL &= ~GPIO_CRL_CNF2_0;						// Set GPIOC_2 as Push-Pull output

    GPIOC -> CRL |= GPIO_CRL_MODE3_1;						// Set GPIOC_3 as output mode 2MHz
    GPIOC -> CRL &= ~GPIO_CRL_CNF3_0;						// Set GPIOC_3 as Push-Pull output

    GPIOC -> CRL |= GPIO_CRL_CNF4_1;
    GPIOC -> CRL &= ~GPIO_CRL_CNF4_0;						// Enable Pull-up for GPIOC_4

    // PC13 INPUT (floating - cuz Pull-up is built in)

    SysTick_Config(8000000 / 2);							// Configure SysTick

    AFIO -> EXTICR[3] = AFIO_EXTICR4_EXTI13_PC;				// Set GPIOC_13 as EXTI AFIO
    AFIO -> EXTICR[1] = AFIO_EXTICR2_EXTI4_PC;				// Set GPIOC_4 as EXTI AFIO

    EXTI->IMR |= EXTI_IMR_MR13;								// Set interrupt mask on line 13
    EXTI->IMR |= EXTI_IMR_MR4;								// Set interrupt mask on line 4

    EXTI->FTSR |= EXTI_FTSR_TR13;							// Falling edge interrupt
    EXTI->FTSR |= EXTI_FTSR_TR4;							// Falling edge interrupt

    NVIC_EnableIRQ(EXTI15_10_IRQn);							// Enable EXTI 10-15 IRQ lines
    NVIC_EnableIRQ(EXTI4_IRQn);

	while(1);
}



__attribute__((interrupt)) void SysTick_Handler(void){		// SysTick interrupt handler
	GPIOC -> ODR ^= GPIO_ODR_ODR2;							// Toggle LED
}



__attribute__((interrupt)) void EXTI15_10_IRQHandler(void){	// EXTI 10:15 interrupt handler
	if(EXTI->PR & EXTI_PR_PR13){
		EXTI->PR = EXTI_PR_PR13;
		GPIOC -> ODR ^= GPIO_ODR_ODR3;						// Toggle LED
	}
}


__attribute__((interrupt)) void EXTI4_IRQHandler(void){	// EXTI 4 interrupt handler
	if(EXTI->PR & EXTI_PR_PR4){
		EXTI->PR = EXTI_PR_PR4;
		GPIOC -> ODR ^= GPIO_ODR_ODR3;						// Toggle LED
	}
}
