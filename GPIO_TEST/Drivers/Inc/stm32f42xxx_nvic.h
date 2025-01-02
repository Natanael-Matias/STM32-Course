/*
 * stm32f42xxx_nvic.h
 *
 *	Nested Vectored Interrupt Controller (NVIC).
 *
 *  Created on: Dec 27, 2024
 *      Author: Natanael.matias
 */

#ifndef INC_STM32F42XXX_NVIC_H_
#define INC_STM32F42XXX_NVIC_H_

#include <stdint.h>

typedef enum {
	WWDG = 0,				// Window Watchdog interrupt 0x0000 0040
	PVD, 					// PVD through EXTI line detection interrupt 0x0000 0044
	TAMP_STAMP, 			// Tamper and TimeStamp interrupts through the EXTI line 0x0000 0048
	RTC_WKUP, 				// RTC Wakeup interrupt through the EXTI line 0x0000 004C
	FLASH, 					//Flash global interrupt 0x0000 0050
	RCC_int, 					// RCC global interrupt 0x0000 0054
	EXTI0, 					// EXTI Line0 interrupt 0x0000 0058
	EXTI1, 					// EXTI Line1 interrupt 0x0000 005C
	EXTI2, 					// EXTI Line2 interrupt 0x0000 0060
	EXTI3, 					// EXTI Line3 interrupt 0x0000 0064
	EXTI4, 					// EXTI Line4 interrupt 0x0000 0068
	DMA1_Stream0, 			// DMA1 Stream0 global interrupt 0x0000 006C
	DMA1_Stream1, 			// DMA1 Stream1 global interrupt 0x0000 0070
	DMA1_Stream2, 			// DMA1 Stream2 global interrupt 0x0000 0074
	DMA1_Stream3, 			// DMA1 Stream3 global interrupt 0x0000 0078
	DMA1_Stream4, 			// DMA1 Stream4 global interrupt 0x0000 007C
	DMA1_Stream5, 			// DMA1 Stream5 global interrupt 0x0000 0080
	DMA1_Stream6, 			// DMA1 Stream6 global interrupt
	ADC, 					// ADC1, ADC2 and ADC3 global interrupts 0x0000 0088
	CAN1_TX, 				// CAN1 TX interrupts 0x0000 008C
	CAN1_RX0, 				// CAN1 RX0 interrupts 0x0000 0090
	CAN1_RX1, 				// CAN1 RX1 interrupt 0x0000 0094
	CAN1_SCE, 				// CAN1 SCE interrupt 0x0000 0098
	EXTI9_5,				// EXTI Line[9:5] interrupts 0x0000 009C
	TIM1_BRK_TIM9, 			//TIM1 Break interrupt and TIM9 global interrupt 0x0000 00A0
	TIM1_UP_TIM10, 			// TIM1 Update interrupt and TIM10 global interrupt 0x0000 00A4
	TIM1_TRG_COM_TIM11, 	// TIM1 Trigger and Commutation interrupts and TIM11 global interrupt 0x0000 00A8
	TIM1_CC, 				// TIM1 Capture Compare interrupt 0x0000 00AC
	TIM2, 					// TIM2 global interrupt 0x0000 00B0
	TIM3, 					// TIM3 global interrupt 0x0000 00B4
	TIM4, 					// TIM4 global interrupt 0x0000 00B8
	I2C1_EV, 				// I2C1 event interrupt 0x0000 00BC
	I2C1_ER, 				// I2C1 error interrupt 0x0000 00C0
	I2C2_EV,				// I2C2 event interrupt 0x0000 00C4
	I2C2_ER, 				// I2C2 error interrupt 0x0000 00C8
	SPI1, 					// SPI1 global interrupt 0x0000 00CC
	SPI2, 					// SPI2 global interrupt 0x0000 00D0
	USART1, 				// USART1 global interrupt 0x0000 00D4
	USART2, 				// USART2 global interrupt 0x0000 00D8
	USART3, 				// USART3 global interrupt 0x0000 00DC
	EXTI15_10, 				// EXTI Line[15:10] interrupts 0x0000 00E0
	RTC_Alarm,				// RTC Alarms (A and B) through EXTI line interrupt 0x0000 00E4
	OTG_FS_WKUP,			// USB On-The-Go FS Wakeup through EXTI line interrupt 0x0000 00E8
	TIM8_BRK_TIM12, 		// TIM8 Break interrupt and TIM12 global interrupt
	TIM8_UP_TIM13, 			// TIM8 Update interrupt and TIM13 global interrupt 0x0000 00F0
	TIM8_TRG_COM_TIM14, 	// TIM8 Trigger and Commutation interrupts and TIM14 global interrupt 0x0000 00F4
	TIM8_CC, 				// TIM8 Capture Compare interrupt 0x0000 00F8
	DMA1_Stream7, 			// DMA1 Stream7 global interrupt 0x0000 00FC
	FSMC, 					// FSMC global interrupt 0x0000 0100
	SDIO, 					// SDIO global interrupt 0x0000 0104
	TIM5, 					// TIM5 global interrupt 0x0000 0108
	SPI3, 					// SPI3 global interrupt 0x0000 010C
	UART4, 					// UART4 global interrupt 0x0000 0110
	UART5, 					// UART5 global interrupt 0x0000 0114
	TIM6_DAC, 				// TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts 0x0000 0118
	TIM7, 					// TIM7 global interrupt 0x0000 011C
	DMA2_Stream0, 			// DMA2 Stream0 global interrupt 0x0000 0120
	DMA2_Stream1, 			// DMA2 Stream1 global interrupt 0x0000 0124
	DMA2_Stream2, 			// DMA2 Stream2 global interrupt 0x0000 0128
	DMA2_Stream3, 			// DMA2 Stream3 global interrupt 0x0000 012C
	DMA2_Stream4, 			// DMA2 Stream4 global interrupt 0x0000 0130
	ETH, 					// Ethernet global interrupt 0x0000 0134
	ETH_WKUP, 				// Ethernet Wakeup through EXTI line interrupt 0x0000 0138
	CAN2_TX, 				// CAN2 TX interrupts 0x0000 013C
	CAN2_RX0, 				// CAN2 RX0 interrupts 0x0000 0140
	CAN2_RX1, 				// CAN2 RX1 interrupt 0x0000 0144
	CAN2_SCE, 				// CAN2 SCE interrupt 0x0000 0148
	OTG_FS, 				// USB On The Go FS global interrupt 0x0000 014C
	DMA2_Stream5, 			// DMA2 Stream5 global interrupt 0x0000 0150
	DMA2_Stream6, 			// DMA2 Stream6 global interrupt 0x0000 0154
	DMA2_Stream7, 			// DMA2 Stream7 global interrupt 0x0000 0158
	USART6, 				// USART6 global interrupt
	I2C3_EV, 				// I2C3 event interrupt 0x0000 0160
	I2C3_ER, 				// I2C3 error interrupt 0x0000 0164
	OTG_HS_EP1_OUT, 		// USB On The Go HS End Point 1 Out global interrupt 0x0000 0168
	OTG_HS_EP1_IN, 			// USB On The Go HS End Point 1 In global interrupt 0x0000 016C
	OTG_HS_WKUP, 			// USB On The Go HS Wakeup through EXTI interrupt 0x0000 0170
	OTG_HS, 				// USB On The Go HS global interrupt 0x0000 0174
	DCMI, 					// DCMI global interrupt 0x0000 0178
	CRYP, 					// CRYP crypto global interrupt 0x0000 017C
	HASH_RNG, 				// Hash and Rng global interrupt 0x0000 0180
	FPU, 					// FPU global interrupt 0x0000 0184
	UART7, 					// UART 7 global interrupt 0x0000 0188
	UART8, 					// UART 8 global interrupt 0x0000 018C
	SPI4, 					// SPI 4 global interrupt 0x0000 0190
	SPI5, 					// SPI 5 global interrupt 0x0000 0194
	SPI6, 					// SPI 6 global interrupt 0x0000 0198
	SAI1, 					// SAI1 global interrupt 0x0000 019C
	LCD_TFT, 				// LTDC global interrupt 0x0000 01A0
	LCD_TFT_ERR, 			// LTDC global Error interrupt 0x0000 01A4
	DMA2D 					// DMA2D global interrupt
} IRQn_Type;

#define NVIC_ADDR_BASE			0xE000E000UL
#define ISERx_OFFSET(x)			(0x100UL + (0x04*x))	/* Interrupt set-enable register x (x = 0 to 7)*/
#define ICERx_OFFSET(x)			(0x180UL + (0x04*x))	/* Interrupt clear-enable register x */
#define ISPRx_OFFSET(x)			(0x200UL + (0x04*x))	/* Interrupt set-pending register x */
#define ICPRx_OFFSET(x)			(0x280UL + (0x04*x))	/* Interrupt clear-pending register x */
#define IABRx_OFFSET(x)			(0x300UL + (0x04*x))	/* Interrupt active bit register x */
#define IPRx_OFFSET(x)			(0x400UL + (0x04*x))	/* Interrupt priority register x (x = 0 to 59)*/
#define STIR_OFFSET				0xE00UL					/* Software trigger interrupt register */

#define NVIC_ISER(x)			(NVIC_ADDR_BASE + ISERx_OFFSET(x))

void NVIC_EnableIRQ(IRQn_Type IRQn); 						/* Enables an interrupt or exception. */
void NVIC_DisableIRQ(IRQn_Type IRQn); 						/* Disables an interrupt or exception.*/
void NVIC_SetPendingIRQ(IRQn_Type IRQn); 					/* Sets the pending status of interrupt or exception to 1.*/
void NVIC_ClearPendingIRQ(IRQn_Type IRQn); 					/* Clears the pending status of interrupt or exception to 0. */
uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn); 				/* Reads the pending status of interrupt or exception.
																This function returns nonzero value if the pending status is set to 1.*/
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority); 	/* Sets the priority of an interrupt or exception
																with configurable priority level to 1.*/
uint32_t NVIC_GetPriority(IRQn_Type IRQn); 					/* Reads the priority of an interrupt or exception with configurable priority
																level. This function return the current priority level. */

#endif /* INC_STM32F42XXX_NVIC_H_ */
