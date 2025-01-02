/*
 * stm32f42xxx_syscfg.c
 *
 *  Created on: Dec 28, 2024
 *      Author: natan
 */

#include "stm32f42xxx_exti.h"
#include "stm32f42xxx_nvic.h"

void GPIO_EXTI_SetInterrupt(GPIO_EXTI_CONFIG_t *pGPIO_Interrupt) {

	if (pGPIO_Interrupt->line > 7 && pGPIO_Interrupt->portPin == gpiok)
		return;

	if (pGPIO_Interrupt->line & 0xF0) /* Verifica se line = 0 to 15 */
		return;

	uint8_t extiLine;
	uint8_t posLine;

	extiLine = pGPIO_Interrupt->line/4; /* Lines 0 to 15, EXTI[0] to EXTI[3] */
	posLine = pGPIO_Interrupt->line%4;

	SYSCFG->EXTICRx[extiLine] = (pGPIO_Interrupt->portPin << (posLine*4));

	EXTI->IMR |= (0x01UL << pGPIO_Interrupt->line);
	EXTI->RTSR |= (pGPIO_Interrupt->risingTrigger << pGPIO_Interrupt->line);
	EXTI->FTSR |= (pGPIO_Interrupt->fallingTrigger << pGPIO_Interrupt->line);

	NVIC_EnableIRQ(pGPIO_Interrupt->IRQn);
}
