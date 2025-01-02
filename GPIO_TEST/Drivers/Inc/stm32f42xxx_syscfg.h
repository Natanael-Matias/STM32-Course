 /*
 * stm32f42xxx_syscfg.h
 *
 *  Created on: Dec 28, 2024
 *      Author: natan
 */

#ifndef INC_STM32F42XXX_SYSCFG_H_
#define INC_STM32F42XXX_SYSCFG_H_

#include "stm32f42xxx_gpio.h"

typedef struct {
	__IO uint32_t	MEMRMP;		/* Offset 0x00 */
	__IO uint32_t	PMC;		/* Offset 0x04 */
	__IO uint32_t	EXTICRx[4];	/* Offset 0x08 - 0x14. x = 1 to 4 */
	__IO uint32_t	CMPCR;		/* Offset 0x20 */
} SYSCFG_REG_t;

#define SYSCFG			((SYSCFG_REG_t *) SYSCFG_ADDR_BASE)

#endif /* INC_STM32F42XXX_SYSCFG_H_ */
