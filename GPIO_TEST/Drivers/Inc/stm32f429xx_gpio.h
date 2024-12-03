/*
 * stm32f4xx_gpio.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Natanael.matias
 */

#ifndef INC_STM32F429XX_GPIO_H_
#define INC_STM32F429XX_GPIO_H_

#include <stdint.h>
#include "stm32f429xx.h"

typedef struct {
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t LCKR;
	__IO uint32_t AFR[2];
}GPIO_RegTypedef;

typedef struct {
	uint8_t pin;
	uint8_t mode;
	uint8_t type;
	uint8_t speed;
	uint8_t pupd;
	uint8_t afr;
} GPIO_Init_t;

typedef enum {
	gpioA = 0,
	gpioB,
	gpioC,
	gpioD,
	gpioE,
	gpioF,
	gpioG,
	gpioH,
	gpioI,
	gpioJ,
	gpioK
}GPIOx_t;

typedef enum {
	pin0    = (uint16_t)0x0001,
	pin1    = (uint16_t)0x0002,
	pin2    = (uint16_t)0x0004,
	pin3    = (uint16_t)0x0008,
	pin4    = (uint16_t)0x0010,
	pin5    = (uint16_t)0x0020,
	pin6    = (uint16_t)0x0040,
	pin7    = (uint16_t)0x0080,
	pin8    = (uint16_t)0x0100,
	pin9    = (uint16_t)0x0200,
	pin10   = (uint16_t)0x0400,
	pin11   = (uint16_t)0x0800,
	pin12   = (uint16_t)0x1000,
	pin13   = (uint16_t)0x2000,
	pin14   = (uint16_t)0x4000,
	pin15   = (uint16_t)0x8000,
	pin_all = (uint16_t)0xFFFF
} GPIO_Pin_t;

typedef enum {
	input = 0, 			/* Input mode */
	output,				/* Output mode */
	alt_function,		/* Alternate function mode */
	analog				/* Analog mode */
} GPIO_MODE_t;

typedef enum {
	low = 0,
	medium,
	high,
	very_high
} GPIO_SPEED_t;

typedef enum {
	no_pull = 0,
	pull_up,
	pull_down
} GPIO_PUPD_t;

typedef enum {
	push_pull = 0,
	open_drain
} GPIO_TYPE_t;

#define GPIOA			((GPIO_RegTypedef *) GPIOA_ADDR_BASE)
#define GPIOB			((GPIO_RegTypedef *) GPIOB_ADDR_BASE)
#define GPIOC			((GPIO_RegTypedef *) GPIOC_ADDR_BASE)
#define GPIOD			((GPIO_RegTypedef *) GPIOD_ADDR_BASE)
#define GPIOE			((GPIO_RegTypedef *) GPIOE_ADDR_BASE)
#define GPIOF			((GPIO_RegTypedef *) GPIOF_ADDR_BASE)
#define GPIOG			((GPIO_RegTypedef *) GPIOG_ADDR_BASE)
#define GPIOH			((GPIO_RegTypedef *) GPIOH_ADDR_BASE)
#define GPIOI			((GPIO_RegTypedef *) GPIOI_ADDR_BASE)
#define GPIOJ			((GPIO_RegTypedef *) GPIOJ_ADDR_BASE)
#define GPIOK			((GPIO_RegTypedef *) GPIOK_ADDR_BASE)

#define GPIOx_CLK_EN(gpiox)		(RCC -> AHB1ENR |= (0x01U << gpiox))	/* Clock enable for GPIOx, x = A, ..., J,K */
#define GPIOx_CLK_DI(gpiox)		(RCC -> AHB1ENR &= ~(0x01U << gpiox))	/* Clock disable for GPIOx, x = A, ..., J,K */

void GPIO_Init(GPIO_RegTypedef *pGPIOx);
void GPIO_DeInit(GPIO_RegTypedef *pGPIOx);
void GPIO_ReadPin(GPIO_RegTypedef *pGPIOx);
void GPIO_ReadPort(GPIO_RegTypedef *pGPIOx);
void GPIO_WritePin(GPIO_RegTypedef *pGPIOx);
void GPIO_WritePort(GPIO_RegTypedef *pGPIOx);
void GPIO_TogglePin(GPIO_RegTypedef *pGPIOx);
void GPIO_IRQConfig(GPIO_RegTypedef *pGPIOx);
void GPIO_IRQHandle(GPIO_RegTypedef *pGPIOx);

#endif /* INC_STM32F429XX_GPIO_H_ */
