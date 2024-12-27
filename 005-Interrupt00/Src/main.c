/*
 * Observações importantes:
 * 			Neste código foi necessário configurar o NVIC.
 * 			E foi necessário configurar o SYSCFG no RCC_APB2ENR_REG
 * 			É necessário investigar o porquê disso.
 */

#include <stdint.h>
#include "main.h"
#include "Interrupt.h"

/********************************************************************************************************/

void WaitHSE_RDY(void);

uint32_t volatile *pNVICIRQEn = (uint32_t*) 0xE000E100; // programming manual PM0214. Interrupt set-enable register

int main(void)
{
	RCC_CR_REG |= (1 << 16); //  HSE oscillator ON
	WaitHSE_RDY();

	RCC_CFGR_REG |= (1 << 0); // HSE oscillator selected as system clock

	GPIOA_EN();
	GPIOA_MODER_REG &= ~(0x3 << 0); // PA0 input mode
	RCC_APB2ENR_REG |= (1 << 14); // TODO: Por quê??

	EXTI_IMR_REG |= (1 << 0);
	EXTI_RTSR_REG |= (1 << 0);	// Rising trigger enabled

	*pNVICIRQEn |= (1 << 6); // Table 62: Vector table. Position column.

    /* Loop forever */
	for(;;);
}

void WaitHSE_RDY(void) {
	while(!(RCC_CR_REG & (1 << 17)));
}
