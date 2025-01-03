/*
 * stm32f429xx.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Natanael.matias
 */

#ifndef INC_STM32F42XXX_H_
#define INC_STM32F42XXX_H_

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



#endif /* INC_STM32F42XXX_H_ */
