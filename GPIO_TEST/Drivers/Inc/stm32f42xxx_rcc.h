/*
 * stm32f42xxx_rcc.h
 *
 *  Created on: Dec 20, 2024
 *      Author: Natanael.matias
 */

#ifndef INC_STM32F42XXX_RCC_H_
#define INC_STM32F42XXX_RCC_H_

#include <stm32f42xxx.h>
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

typedef union __attribute__((packed)) {
	struct {
		bool_t 			hsi_on:			1; /* Internal high-speed clock enable */
		__RO bool_t 	hsi_rdy:		1; /* Internal high-speed clock ready flag */
		bool_t 			reserved0:		1;
		uint8_t 		hsi_trim:		5; /* Internal high-speed clock trimming */
		__RO uint8_t 	hsi_cal:		8; /* Internal high-speed clock calibration */
		bool_t 			hse_on:			1; /* HSE clock enable */
		__RO bool_t		hse_rdy:		1; /* HSE clock ready flag */
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
	uint32_t all_bits;
} CR_Bits;

/********************************************************************************************************/

typedef enum {
	HSI_osc = 0,
	HSE_osc,
	PLL_osc
}SW_t; /* System clock switch values */

typedef SW_t	SWS_t; /* System clock switch status */

typedef enum {
	HPRE_noDiv = 0,	HPRE_div2 = 8, HPRE_div4,
	HPRE_div8, HPRE_div16, HPRE_div64,
	HPRE_div128, HPRE_div256, HPRE_div512
}HPRE_t; /* AHB prescaler */

typedef enum {
	AHB_noDiv = 0,
	AHB_div2 = 4,
	AHB_div4,
	AHB_div8,
	AHB_div16
}PPREx_t; /* APB1 (Low speed prescaler) and APB2 (High-speed prescaler) */

typedef enum {
	HSEdiv2 = 2, HSEdiv3, HSEdiv4, HSEdiv5, HSEdiv6, HSEdiv7, HSEdiv8, HSEdiv9,
	HSEdiv10, HSEdiv11,	HSEdiv12, HSEdiv13, HSEdiv14, HSEdiv15, HSEdiv16, HSEdiv17,
	HSEdiv18, HSEdiv19, HSEdiv20, HSEdiv21, HSEdiv22, HSEdiv23, HSEdiv24, HSEdiv25,
	HSEdiv26, HSEdiv27, HSEdiv28, HSEdiv29, HSEdiv30, HSEdiv31
} RTCPRE_t; /* HSE division factor for RTC clock */

typedef enum {
	MCO1_HSI = 0,
	MCO1_LSE,
	MCO1_HSE,
	MCO1_PLL
} MCO1_t; /* Microcontroller clock output 1 selction */

typedef enum {
	PLL_I2S = 0,	/*  PLLI2S clock used as I2S clock source */
	I2S_CKIN		/* External clock mapped on the I2S_CKIN pin used as I2S clock source */
}I2SSRC_t; /* I2S clock selection source */

typedef enum {
	MCO_noDiv = 0,
	MCO_div2 = 4,
	MCO_div3,
	MCO_div4,
	MCO_div5
} MCOxPRE_t; /* MCOx prescaler */

typedef enum {
	MCO2_SYSCLK = 0,
	MCO2_PLLI2S,
	MCO2_HSE,
	MCO2_PLL
}MCO2_t;

typedef union __attribute__((packed)) {
	struct {
		SW_t	 		sw:			2; /* System clock switch */
		__RO SWS_t 		sws:		2; /* System clock switch status */
		HPRE_t	 		hpre:		4; /* AHB prescaler */
		uint8_t 		reserved:	2;
		PPREx_t 		ppre1:		3; /* APB Low speed prescaler (APB1) */
		PPREx_t 		ppre2:		3; /* APB high-speed prescaler (APB2) */
		RTCPRE_t 		rtc_pre:	5; /* HSE division factor for RTC clock */
		MCO1_t			mco1:		2; /* Microcontroller clock output 1 */
		I2SSRC_t		i2s_sc:		1; /* I2S clock selection */
		MCOxPRE_t		mco1_pre:	3; /* MCO1 prescaler */
		MCOxPRE_t		mco2_pre:	3; /* MCO2 prescaler */
		MCO2_t			mco2:		2; /* Microcontroller clock output 2 */
	};
	uint32_t all_bits;
} CFGR_Bits;

/********************************************************************************************************/

typedef union __attribute__((packed)) {
	struct {
		bool_t tim1_en:		1;	/* TIM1 clock enable */
		bool_t tim8_en:		1;	/* TIM8 clock enable */
		uint8_t res0:		2;
		bool_t usart1_en:	1;	/* USART1 clock enable */
		bool_t usart6_en:	1;	/* USART6 clock enable */
		uint8_t res1:		2;
		bool_t adc1_en:		1;	/* ADC1 clock enable */
		bool_t adc2_en:		1;	/* ADC2 clock enable */
		bool_t adc3_en:		1;	/* ADC3 clock enable */
		bool_t sdio_en:		1;	/* SDIO clock enable */
		bool_t spi1_en:		1;	/* SPI1 clock enable */
		bool_t spi4_en:		1;	/* SPI4 clock enable */
		bool_t syscfg_en:	1;	/* System configuration controller clock enable */
		bool_t res2:		1;
		bool_t tim9_en:		1;	/* TIM9 clock enable */
		bool_t tim10_en:	1;	/* TIM10 clock enable */
		bool_t tim11_en:	1;	/* TIM11 clock enable */
		bool_t res3:		1;
		bool_t spi5_en:		1;	/* SPI5 clock enable */
		bool_t spi6_en:		1;	/* SPI6 clock enable */
		bool_t sai1_en:		1;	/* SAI1 clock enable */
		uint8_t res4:		3;
		bool_t ltdc_en:		1;	/* LTDC clock enable */
		uint8_t res5:		5;
	};
	uint32_t all_bits;
} APB2ENR_Bits;

#define RCC					((RCC_RegTypedef *) RCC_ADDR_BASE)
#define RCC_CR_Bits			((CR_Bits *) 		&RCC->CR)
#define RCC_CFGR_Bits		((CFGR_Bits *) 		&RCC->CFGR)
#define RCC_APB2ENR_Bits	((APB2ENR_Bits *)	&RCC->APB2ENR)

#endif /* INC_STM32F42XXX_RCC_H_ */
