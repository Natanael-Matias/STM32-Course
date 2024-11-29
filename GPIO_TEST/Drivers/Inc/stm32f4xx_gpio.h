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
}GPIO_Reg_Typedef;

#define GPIOA			((GPIO_Reg_Typedef *) GPIOA_ADDR_BASE)
#define GPIOB			((GPIO_Reg_Typedef *) GPIOB_ADDR_BASE)
#define GPIOC			((GPIO_Reg_Typedef *) GPIOC_ADDR_BASE)
#define GPIOD			((GPIO_Reg_Typedef *) GPIOD_ADDR_BASE)
#define GPIOE			((GPIO_Reg_Typedef *) GPIOE_ADDR_BASE)
#define GPIOF			((GPIO_Reg_Typedef *) GPIOF_ADDR_BASE)
#define GPIOG			((GPIO_Reg_Typedef *) GPIOG_ADDR_BASE)
#define GPIOH			((GPIO_Reg_Typedef *) GPIOH_ADDR_BASE)
#define GPIOI			((GPIO_Reg_Typedef *) GPIOI_ADDR_BASE)
#define GPIOJ			((GPIO_Reg_Typedef *) GPIOJ_ADDR_BASE)
#define GPIOK			((GPIO_Reg_Typedef *) GPIOK_ADDR_BASE)



#endif /* INC_STM32F4XX_GPIO_H_ */
