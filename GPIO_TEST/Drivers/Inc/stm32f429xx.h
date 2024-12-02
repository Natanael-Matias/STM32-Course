/*
 * stm32f429xx.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Natanael.matias
 */

#ifndef INC_STM32F429XX_H_
#define INC_STM32F429XX_H_

#include <stdint.h>

#define __IO				volatile
#define __RO				const volatile

/*
 * Base addresses of Memory mapping
 */
#define FLASH_ADDR_BASE				0x08000000UL
#define SYS_MEM_ADDR_BASE			0x1FFF0000UL
#define SRAM1_ADDR_BASE				0x20000000UL
#define SRAM2_ADDR_BASE				0x2001C000UL
#define SRAM3_ADDR_BASE				0x20020000UL

/*
 * Base addresses of bus APBx and AHBx peripherals
 */
#define APB1_ADDR_BASE				0x40000000UL
#define APB2_ADDR_BASE				0x40010000UL
#define AHB1_ADDR_BASE				0x40020000UL
#define AHB2_ADDR_BASE				0x50000000UL
#define AHB3_ADDR_BASE				0xA0000000UL /* FMC control register */

/*
 * Base addresses of peripherals which are hanging on APBx and AHB1 bus
 */
#define GPIOA_ADDR_BASE				(AHB1_ADDR_BASE + 0x0000UL)
#define GPIOB_ADDR_BASE				(AHB1_ADDR_BASE + 0x0400UL)
#define GPIOC_ADDR_BASE				(AHB1_ADDR_BASE + 0x0800UL)
#define GPIOD_ADDR_BASE				(AHB1_ADDR_BASE + 0x0C00UL)
#define GPIOE_ADDR_BASE				(AHB1_ADDR_BASE + 0x1000UL)
#define GPIOF_ADDR_BASE				(AHB1_ADDR_BASE + 0x1400UL)
#define GPIOG_ADDR_BASE				(AHB1_ADDR_BASE + 0x1800UL)
#define GPIOH_ADDR_BASE				(AHB1_ADDR_BASE + 0x1C00UL)
#define GPIOI_ADDR_BASE				(AHB1_ADDR_BASE + 0x2000UL)
#define GPIOJ_ADDR_BASE				(AHB1_ADDR_BASE + 0x2400UL)
#define GPIOK_ADDR_BASE				(AHB1_ADDR_BASE + 0x2800UL)
#define RCC_ADDR_BASE				(AHB1_ADDR_BASE + 0x3800UL)

#define SPI2_ADDR_BASE				(APB1_ADDR_BASE + 0x3800UL)
#define SPI3_ADDR_BASE				(APB1_ADDR_BASE + 0x3C00UL)
#define USART2_ADDR_BASE			(APB1_ADDR_BASE + 0x4400UL)
#define USART3_ADDR_BASE			(APB1_ADDR_BASE + 0x4800UL)
#define UART4_ADDR_BASE				(APB1_ADDR_BASE + 0x4C00UL)
#define UART5_ADDR_BASE				(APB1_ADDR_BASE + 0x5000UL)
#define I2C1_ADDR_BASE				(APB1_ADDR_BASE + 0x5400UL)
#define I2C2_ADDR_BASE				(APB1_ADDR_BASE + 0x5800UL)
#define I2C3_ADDR_BASE				(APB1_ADDR_BASE + 0x5C00UL)
#define UART7_ADDR_BASE				(APB1_ADDR_BASE + 0x7800UL)
#define UART8_ADDR_BASE				(APB1_ADDR_BASE + 0x7C00UL)

#define SPI1_ADDR_BASE				(APB2_ADDR_BASE + 0x3000UL)
#define SPI4_ADDR_BASE				(APB2_ADDR_BASE + 0x3400UL)
#define SYSCFG_ADDR_BASE			(APB2_ADDR_BASE + 0x3800UL)
#define EXTI_ADDR_BASE				(APB2_ADDR_BASE + 0x3C00UL)
#define USART1_ADDR_BASE			(APB2_ADDR_BASE + 0x1000UL)
#define USART6_ADDR_BASE			(APB2_ADDR_BASE + 0x1400UL)


/*
 * Struct for RCC registers
 */

typedef struct {
	__IO uint32_t CR;				/* Offset: 0x00 */
	__IO uint32_t PLLCFGR;			/* Offset: 0x04 */
	__IO uint32_t CFGR;				/* Offset: 0x08 */
	__IO uint32_t CIR;				/* Offset: 0x0C */
	__IO uint32_t AHB1RSTR;			/* Offset: 0x10 */
	__IO uint32_t AHB2RSTR;			/* Offset: 0x14 */
	__IO uint32_t AHB3RSTR;			/* Offset: 0x18 */
	__IO uint32_t Reserved0;		/* Offset: 0x1C */
	__IO uint32_t APB1RSTR;			/* Offset: 0x20 */
	__IO uint32_t APB2RSTR;			/* Offset: 0x24 */
	__IO uint32_t Reserved1[2];		/* Offset: 0x28 */
	__IO uint32_t AHB1ENR;			/* Offset: 0x30 */
	__IO uint32_t AHB2ENR;			/* Offset: 0x34 */
	__IO uint32_t AHB3ENR;			/* Offset: 0x38 */
	__IO uint32_t Reserved2;		/* Offset: 0x3C */
	__IO uint32_t APB1ENR;			/* Offset: 0x40 */
	__IO uint32_t APB2ENR;			/* Offset: 0x44 */
	__IO uint32_t Reserved3[2];		/* Offset: 0x48 */
	__IO uint32_t AHB1LPENR;		/* Offset: 0x50 */
	__IO uint32_t AHB2LPENR;		/* Offset: 0x54 */
	__IO uint32_t AHB3LPENR;		/* Offset: 0x58 */
	__IO uint32_t Reserved4;		/* Offset: 0x5C */
	__IO uint32_t APB1LPENR;		/* Offset: 0x60 */
	__IO uint32_t APB2LPENR;		/* Offset: 0x64 */
	__IO uint32_t Reserved5[2];		/* Offset: 0x68 */
	__IO uint32_t BDCR;				/* Offset: 0x70 */
	__IO uint32_t CSR;				/* Offset: 0x74 */
	__IO uint32_t Reserved6[2];		/* Offset: 0x78 */
	__IO uint32_t SSCGR;			/* Offset: 0x80 */
	__IO uint32_t PLLI2SCFGR;		/* Offset: 0x84 */
}RCC_RegTypedef;

#define RCC				((RCC_RegTypedef *) RCC_ADDR_BASE)

#endif /* INC_STM32F429XX_H_ */
