/*
 * main.h
 *
 *  Created on: Nov 6, 2024
 *      Author: Natanael.matias
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

/********************************************* RCC Register *********************************************/
#define RCC_BASE_ADDR					0x40023800UL

#define RCC_CR_OFFSET					0x00UL
#define RCC_CFGR_OFFSET					0x08UL
#define RCC_AHB1ENR_OFFSET				0x30UL
#define RCC_APB2ENR_OFFSET				0x44UL

#define RCC_CR_ADDR						(RCC_BASE_ADDR + RCC_CR_OFFSET)
#define RCC_CFGR_ADDR					(RCC_BASE_ADDR + RCC_CFGR_OFFSET)
#define RCC_AHB1ENR_ADDR				(RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET)
#define RCC_APB2ENR_ADDR				(RCC_BASE_ADDR + RCC_APB2ENR_OFFSET)

#define RCC_CR_REG						*((volatile uint32_t *) RCC_CR_ADDR)			//	RCC clock control register
#define RCC_CFGR_REG					*((volatile uint32_t *) RCC_CFGR_ADDR)			//	RCC clock configuration register
#define RCC_AHB1ENR_REG					*((volatile uint32_t *) RCC_AHB1ENR_ADDR)		//	RCC AHB1 peripheral clock register
#define RCC_APB2ENR_REG					*((volatile uint32_t *) RCC_APB2ENR_ADDR)

/********************************************************************************************************/

/******************************************** GPIO Register *********************************************/
#define GPIOx_BASE_ADDR					0x40020000UL

#define GPIOA_OFFSET					0x00UL
#define GPIOx_MODER_OFFSET				0x00UL

#define GPIOA_ADDR						(GPIOx_BASE_ADDR + GPIOA_OFFSET)
#define GPIOA_MODER_ADDR				(GPIOA_ADDR + GPIOx_MODER_OFFSET)

#define GPIOA_MODER_REG					*((volatile uint32_t *) GPIOA_MODER_ADDR)	//	GPIO port mode register

#define GPIOA_EN()						RCC_AHB1ENR_REG |= (1 << 0)

/********************************************************************************************************/

/******************************************** EXTI Register *********************************************/
#define EXTI_BASE_ADDR 					0x40013C00UL

#define EXTI_IMR_OFFSET					0x00UL	//	Interrupt mask register offset
#define EXTI_RTSR_OFFSET				0x08UL	//	Rising trigger selection register offset
#define EXTI_PR_OFFSET					0x14UL	//	Pending register offset

#define EXTI_IMR_ADDR					(EXTI_BASE_ADDR + EXTI_IMR_OFFSET)
#define EXTI_RTSR_ADDR					(EXTI_BASE_ADDR + EXTI_RTSR_OFFSET)
#define EXTI_PR_ADDR					(EXTI_BASE_ADDR + EXTI_PR_OFFSET)

#define EXTI_IMR_REG					*((volatile uint32_t *) EXTI_IMR_ADDR)	//	Interrupt mask register
#define EXTI_RTSR_REG					*((volatile uint32_t *) EXTI_RTSR_ADDR)	//	Rising trigger selection register
#define EXTI_PR_REG						*((volatile uint32_t *) EXTI_PR_ADDR)	//	Pending register

#endif /* MAIN_H_ */
