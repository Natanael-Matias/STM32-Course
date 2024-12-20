/*
 * stm32f42xxx_rcc.h
 *
 *  Created on: Dec 20, 2024
 *      Author: Natanael.matias
 */

#ifndef INC_STM32F42XXX_RCC_H_
#define INC_STM32F42XXX_RCC_H_

#include "stm32f429xx.h"
#include "main.h"

/* Struct for RCC registers */

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

typedef union __attribute__((packed)) {
	struct {
		bool_t 			hsi_on:			1; /* Internal high-speed clock enable */
		__RO bool_t 	hsi_rdy:		1; /* Internal high-speed clock ready flag */
		bool_t 			reserved0:		1;
		uint8_t 		hsi_trim:		5; /* Internal high-speed clock trimming */
		__RO uint8_t 	hsi_cal:		8; /* Internal high-speed clock calibration */
		bool_t 			hse_on:			1; /* HSE clock enable */
		__RO bool_t 	hse_rdy:		1; /* HSE clock ready flag */
		bool_t 			hse_byp:		1; /* HSE clock bypass */
		bool_t			css_on:			1; /* Clock security system enable */
		uint8_t			reserved1:		4;
		bool_t			pll_on:			1; /* Main PLL (PLL) enable */
		__RO bool_t		pll_rdy:		1; /* Main PLL (PLL) clock ready flag */
		bool_t			pll_i2s_on:		1; /* PLLI2S enable */
		__RO bool_t		pll_i2s_rdy:	1; /* PLLI2S clock ready flag */
		bool_t			pll_sai_on:		1; /* PLLSAI enable */
		__RO bool_t		pll_sai_rdy:	1; /* PLLSAI clock ready flag */
		uint8_t			reserved2:		2;
	};
	uint32_t rcc_cr_all;
} RCC_CR_Bits;

#endif /* INC_STM32F42XXX_RCC_H_ */
