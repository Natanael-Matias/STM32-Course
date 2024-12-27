/*
 * stm32f42xxx_nvic.h
 *
 *  Created on: Dec 27, 2024
 *      Author: Natanael.matias
 */

#ifndef INC_STM32F42XXX_NVIC_H_
#define INC_STM32F42XXX_NVIC_H_

#define NVIC_ADDR_BASE			0xE000E000UL
#define ISERx_OFFSET(x)			(0x100UL + (0x04*x))		/* Interrupt set-enable register x (x = 0 to 7)*/
#define ICERx_OFFSET(x)			(0x180UL + (0x04*x))		/* Interrupt clear-enable register x */
#define ISPRx_OFFSET(x)			(0x200UL + (0x04*x))		/* Interrupt set-pending register x */
#define ICPRx_OFFSET(x)			(0x280UL + (0x04*x))		/* Interrupt clear-pending register x */
#define IABRx_OFFSET(x)			(0x300UL + (0x04*x))		/* Interrupt active bit register x */
#define IPRx_OFFSET(x)			(0x400UL + (0x04*x))		/* Interrupt priority register x (x = 0 to 59)*/
#define STIR_OFFSET(x)			0xE00UL		/* Software trigger interrupt register */

#endif /* INC_STM32F42XXX_NVIC_H_ */
