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
