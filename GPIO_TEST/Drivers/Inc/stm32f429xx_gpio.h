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
#include "main.h"

typedef enum {
	gpioa = 0,
	gpiob,
	gpioc,
	gpiod,
	gpioe,
	gpiof,
	gpiog,
	gpioh,
	gpioi,
	gpioj,
	gpiok
}GPIO_Port_t;

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

typedef enum {
	af0 = 0,
	af1,
	af2,
	af3,
	af4,
	af5,
	af6,
	af7,
	af8,
	af9,
	af10,
	af11,
	af12,
	af13,
	af14,
	af15
} GPIO_AF_t;

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
}GPIO_Reg_t;

typedef struct {
	GPIO_Port_t 	port;
	GPIO_Pin_t 		pin;
	GPIO_MODE_t 	mode;
	GPIO_TYPE_t 	type;
	GPIO_SPEED_t 	speed;
	GPIO_PUPD_t 	pupd;
	GPIO_AF_t 		alternate;
} GPIO_Init_t;

#define GPIO_PORTA			((GPIO_Reg_t *) GPIOA_ADDR_BASE)
#define GPIO_PORTB			((GPIO_Reg_t *) GPIOB_ADDR_BASE)
#define GPIO_PORTC			((GPIO_Reg_t *) GPIOC_ADDR_BASE)
#define GPIO_PORTD			((GPIO_Reg_t *) GPIOD_ADDR_BASE)
#define GPIO_PORTE			((GPIO_Reg_t *) GPIOE_ADDR_BASE)
#define GPIO_PORTF			((GPIO_Reg_t *) GPIOF_ADDR_BASE)
#define GPIO_PORTG			((GPIO_Reg_t *) GPIOG_ADDR_BASE)
#define GPIO_PORTH			((GPIO_Reg_t *) GPIOH_ADDR_BASE)
#define GPIO_PORTI			((GPIO_Reg_t *) GPIOI_ADDR_BASE)
#define GPIO_PORTJ			((GPIO_Reg_t *) GPIOJ_ADDR_BASE)
#define GPIO_PORTK			((GPIO_Reg_t *) GPIOK_ADDR_BASE)

#define GPIOx_CLK_EN(gpiox)		(RCC -> AHB1ENR |= (0x01U << gpiox))	/* Clock enable for GPIOx, x = A, ..., J,K */
#define GPIOx_CLK_DI(gpiox)		(RCC -> AHB1ENR &= ~(0x01U << gpiox))	/* Clock disable for GPIOx, x = A, ..., J,K */

void GPIO_Init(GPIO_Reg_t *pGPIOx, GPIO_Init_t *pGPIO_Init);
void GPIO_DeInit(GPIO_Reg_t *pGPIOx);

bool_t GPIO_ReadPin(GPIO_Reg_t *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_ReadPort(GPIO_Reg_t *pGPIOx);
void GPIO_WritePin(GPIO_Reg_t *pGPIOx, uint8_t pinNumber, bool_t pinValue);
void GPIO_WritePort(GPIO_Reg_t *pGPIOx, uint16_t portValue);
void GPIO_TogglePin(GPIO_Reg_t *pGPIOx, uint8_t pinNumber);

void GPIO_IRQConfig(GPIO_Reg_t *pGPIOx);
void GPIO_IRQHandle(GPIO_Reg_t *pGPIOx);

#endif /* INC_STM32F429XX_GPIO_H_ */
