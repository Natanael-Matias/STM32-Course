/*
 * stm32f42xxx_exti.h
 *
 *  Created on: Dec 29, 2024
 *      Author: natan
 */

#ifndef INC_STM32F42XXX_EXTI_H_
#define INC_STM32F42XXX_EXTI_H_

#include "stm32f42xxx.h"
#include "stm32f42xxx_syscfg.h"
#include "stm32f42xxx_nvic.h"

typedef enum {
	_L0 = 0,	/* PA0 ... PK0 */
	_L1,		/* PA1 ... PK1 */
	_L2,		/* PA2 ... PK2 */
	_L3,		/* PA3 ... PK3 */
	_L4,		/* PA4 ... PK4 */
	_L5,		/* PA5 ... PK5 */
	_L6,		/* PA6 ... PK6 */
	_L7,		/* PA7 ... PK7 */
	_L8,		/* PA8 ... PK8 */
	_L9,		/* PA9 ... PK9 */
	_L10,		/* PA10 ... PK10 */
	_L11,		/* PA11 ... PK11 */
	_L12,		/* PA12 ... PK12 */
	_L13,		/* PA13 ... PK13 */
	_L14,		/* PA14 ... PK14 */
	_L15,		/* PA15 ... PK15 */
	_L16,		/* PVD output */
	_L17,		/* RTC Alarm event */
	_L18,		/* USB OTG FS Wakeup event */
	_L19,		/* Ethernet Wakeup event */
	_L20,		/* USB OTG HS (configured in FS) Wakeup event */
	_L21,		/* RTC Tamper and TimeStamp events */
	_L22		/* RTC Wakeup event */
} EXTI_Line_t;

typedef struct {
	EXTI_Line_t line;
	GPIO_Port_t portPin;
	bool_t risingTrigger;
	bool_t fallingTrigger;
	IRQn_Type IRQn;
	uint8_t priority;
}GPIO_EXTI_CONFIG_t;

typedef struct {
	__IO uint32_t IMR;		/* Interrupt mask register */
	__IO uint32_t EMR;		/* Event mask register */
	__IO uint32_t RTSR;		/* Rising trigger selection register */
	__IO uint32_t FTSR;		/* Falling trigger selection register */
	__IO uint32_t SWIER;	/* Software interrupt event register */
	__IO uint32_t PR;		/* Pending register */
}EXTI_Reg_t;

#define EXTI		((EXTI_Reg_t *) EXTI_ADDR_BASE)

void GPIO_EXTI_SetInterrupt(GPIO_EXTI_CONFIG_t *pGPIO_Interrupt);

#endif /* INC_STM32F42XXX_EXTI_H_ */
