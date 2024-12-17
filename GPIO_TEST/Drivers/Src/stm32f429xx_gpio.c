/*
 * stm32f429xx_gpio.c
 *
 *  Created on: Dec 12, 2024
 *      Author: Natanael.matias
 */

#include "main.h"
#include "stm32f429xx_gpio.h"

/***********************************************************************
 * @fn				- GPIO_Init
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- none
 *
 * @note			- none
 *
 */
void GPIO_Init(GPIO_Reg_t *pGPIOx, GPIO_Init_t pGPIO_Init) {
	uint8_t pinNumber = 0;

	uint16_t temp = pGPIO_Init.pin;
	while (temp > 0) {
		pinNumber = SelectPin(&temp);
		pGPIOx -> MODER 	&= ~(0x03U)	<< (pinNumber * 2);
		pGPIOx -> MODER 	|= pGPIO_Init.mode	<< (pinNumber * 2);

		pGPIOx -> OTYPER 	&= ~(0x03U)	<< (pinNumber);
		pGPIOx -> OTYPER 	|= pGPIO_Init.type 	<< (pinNumber);

		pGPIOx -> OSPEEDR 	&= ~(0x03U)	<< (pinNumber * 2);
		pGPIOx -> OSPEEDR 	|= pGPIO_Init.speed	<< (pinNumber * 2);

		pGPIOx -> PUPDR 	&= ~(0x03U)	<< (pinNumber * 2);
		pGPIOx -> PUPDR 	|= pGPIO_Init.pupd 	<< (pinNumber * 2);

		if (pGPIO_Init.mode == alt_function) {
			pGPIOx -> AFR[pinNumber/8]	&= ~(0x0FU) << ((pinNumber % 8) * 4);
			pGPIOx -> AFR[pinNumber/8]	|= pGPIO_Init.alternate << ((pinNumber % 8) * 4);
		}
	}


}

void GPIO_DeInit(GPIO_Reg_t *pGPIOx) {

}

bool_t GPIO_ReadPin(GPIO_Reg_t *pGPIOx, uint8_t pinNumber) {

}

uint16_t GPIO_ReadPort(GPIO_Reg_t *pGPIOx) {

}

void GPIO_WritePin(GPIO_Reg_t *pGPIOx, uint8_t pinNumber, bool_t pinValue) {

}

void GPIO_WritePort(GPIO_Reg_t *pGPIOx, uint16_t portValue) {

}

void GPIO_TogglePin(GPIO_Reg_t *pGPIOx, uint8_t pinNumber) {

}

void GPIO_IRQConfig(GPIO_Reg_t *pGPIOx) {

}

void GPIO_IRQHandle(GPIO_Reg_t *pGPIOx) {

}

uint8_t SelectPin(uint16_t *x) {
	uint8_t temp = 0;

	while (!(*x & 0x01U)) {
		*x = *x >> 1;
		temp++;
	}
	*x = *x >> 1;
	return temp;
}
