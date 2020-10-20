#include "stm32f103xb.h"

void delay(void);


int main(void){
	 RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN;	// Set APB2ENR to provide GPIOC with clock

	 GPIOC -> CRL |= GPIO_CRL_MODE2_1;		// Set GPIOB_8 as output mode 2MHz
	 GPIOC -> CRL &= ~GPIO_CRL_CNF2_0;		// Set GPIOB_8 as Push-Pull output
	 GPIOC -> CRL |= GPIO_CRL_MODE3_1;		// Set GPIOB_9 as output mode 2MHz
	 GPIOC -> CRL &= ~GPIO_CRL_CNF3_0;		// Set GPIOB_9 as Push-Pull output

	 while(1){
		 if(GPIOC -> IDR & GPIO_IDR_IDR13){
			 GPIOC -> BSRR = GPIO_BSRR_BS2 + GPIO_BSRR_BR3;
			 delay();
		 }
		 else{
			 GPIOC -> BSRR = GPIO_BSRR_BR2 + GPIO_BSRR_BS3;
			 delay();
		 }
	 } /* while(1) */
} /* main */


void delay(void){
	for(uint32_t delay = 100000; delay > 0; --delay);
}