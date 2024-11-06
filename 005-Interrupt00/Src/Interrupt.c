/*
 * Interrupt.c
 *
 *  Created on: Nov 6, 2024
 *      Author: Natanael.matias
 */

#include "Interrupt.h"

void EXTI0_IRQHandler(void) {
	EXTI_PR_REG |= (1 << 0);
}
