/*
 * Interrupt.c
 *
 *  Created on: Nov 6, 2024
 *      Author: Natanael.matias
 */

#include "Interrupt.h"

void EXTI0_IRQHandler(void) {
	int i = 0;
	EXTI_PR_REG |= (1 << 0);
	i = 1;
}
