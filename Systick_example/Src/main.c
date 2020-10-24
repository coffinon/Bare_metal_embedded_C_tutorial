#include "stm32f103xb.h"

int main(void)
{
    RCC -> APB2ENR = RCC_APB2ENR_IOPCEN;

    GPIOC -> CRL |= GPIO_CRL_MODE2_1;						// Set GPIOB_8 as output mode 2MHz
    GPIOC -> CRL &= ~GPIO_CRL_CNF2_0;						// Set GPIOB_8 as Push-Pull output

    SysTick_Config(8000000 / 2);							// Configure SysTick

	while(1);
}

__attribute__((interrupt)) void SysTick_Handler(void){									// SysTick interrupt handler
	GPIOC -> ODR ^= GPIO_ODR_ODR2;							// Toggle diode
}
