/*
 * stm32f4xx_gpio.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Natanael.matias
 */

#ifndef INC_STM32F4XX_GPIO_H_
#define INC_STM32F4XX_GPIO_H_

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
	pin0    = 0x0001,
	pin1    = 0x0002,
	pin2    = 0x0004,
	pin3    = 0x0008,
	pin4    = 0x0010,
	pin5    = 0x0020,
	pin6    = 0x0040,
	pin7    = 0x0080,
	pin8    = 0x0100,
	pin9    = 0x0200,
	pin10   = 0x0400,
	pin11   = 0x0800,
	pin12   = 0x1000,
	pin13   = 0x2000,
	pin14   = 0x4000,
	pin15   = 0x8000,
	pin_all = 0xFFFF
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

#endif /* INC_STM32F4XX_GPIO_H_ */
