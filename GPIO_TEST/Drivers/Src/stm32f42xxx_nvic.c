/*
 * stm32f42xxx_nvic.c
 *
 *  Created on: Dec 29, 2024
 *      Author: natan
 */
#include "stm32f42xxx_nvic.h"

void NVIC_EnableIRQ(IRQn_Type IRQn) {
	int temp = IRQn/31;
	int temp1 = IRQn%31;
	uint32_t *pISER = (uint32_t *) NVIC_ISER(temp);

	*pISER |= (0x01UL << temp1);
}
