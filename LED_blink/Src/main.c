#include "stm32f103xb.h"


int main(void){
	 RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;	// Set APB2ENR to provide GPIOA with clock

	 GPIOA -> CRL |= GPIO_CRL_MODE5_1;		// Set GPIOA_5 as output mode 2MHz
	 GPIOA -> CRL &= ~GPIO_CRL_CNF5_0;		// Set GPIOA_5 as Push-Pull output

	 while(1){
		 GPIOA -> ODR |= GPIO_ODR_ODR5;		// Set GPIOA_5 output register
		 for(uint32_t delay = 300000; delay > 0; --delay);
		 GPIOA -> ODR &= ~GPIO_ODR_ODR5;	// Clear GPIOA_5 output register
		 for(uint32_t delay = 300000; delay > 0; --delay);
	 } /* while(1) */

} /* main */
