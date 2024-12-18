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
void GPIO_Init(GPIO_Reg_t *pGPIOx, const GPIO_Config_t *pGPIO_Init) {
	uint8_t pinNumber = 0;

	/* Clock enable for GPIO port */
	GPIO_CLK_EN(pGPIO_Init -> port);

	uint16_t temp = pGPIO_Init -> pin;
	while (temp > 0) {
		pinNumber = SelectPin(&temp);

		pGPIOx -> MODER 	&= ~(0x03U)	<< (pinNumber * 2);
		pGPIOx -> MODER 	|= pGPIO_Init -> mode	<< (pinNumber * 2);

		pGPIOx -> OTYPER 	&= ~(0x03U)	<< (pinNumber);
		pGPIOx -> OTYPER 	|= pGPIO_Init -> type 	<< (pinNumber);

		pGPIOx -> OSPEEDR 	&= ~(0x03U)	<< (pinNumber * 2);
		pGPIOx -> OSPEEDR 	|= pGPIO_Init -> speed	<< (pinNumber * 2);

		pGPIOx -> PUPDR 	&= ~(0x03U)	<< (pinNumber * 2);
		pGPIOx -> PUPDR 	|= pGPIO_Init -> pupd 	<< (pinNumber * 2);

		if (pGPIO_Init -> mode == alt_function) {
			uint8_t temp1 = pinNumber/8;
			uint8_t temp2 = pinNumber%8;
			pGPIOx -> AFR[temp1]	&= ~(0x0FU) << ((temp2) * 4);
			pGPIOx -> AFR[temp1]	|= pGPIO_Init -> alternate << ((temp2) * 4);
		}
	}


}

void GPIO_DeInit(const GPIO_Config_t *pGPIOx) {
	GPIO_PORT_RESET(pGPIOx -> port);
}

bool_t GPIO_ReadPin(GPIO_Reg_t *pGPIOx, const GPIO_Pin_t *pGPIO_Pin) {
	bool_t value;
	uint16_t temp = *pGPIO_Pin;
	value = (pGPIOx -> IDR & *pGPIO_Pin) >> SelectPin(&temp);
	return value;
}

uint16_t GPIO_ReadPort(GPIO_Reg_t *pGPIOx) {
	uint16_t value;
	value = (uint16_t) pGPIOx -> IDR;
	return value;
}

void GPIO_WritePin(GPIO_Reg_t *pGPIOx, const GPIO_Pin_t *pGPIO_Pin, state_t pinValue) {
	uint16_t temp = *pGPIO_Pin;
	uint16_t temp1 = SelectPin(&temp);
	uint16_t temp2 = (uint16_t) pinValue << temp1;
	pGPIOx ->  ODR &= ~(0x1 << temp1);
	pGPIOx ->  ODR |= (*pGPIO_Pin & temp2);
}

void GPIO_WritePort(GPIO_Reg_t *pGPIOx, uint16_t portValue) {
	pGPIOx -> ODR = portValue;
}

void GPIO_TogglePin(GPIO_Reg_t *pGPIOx, const GPIO_Pin_t *pGPIO_Pin) {
	pGPIOx -> ODR ^= *pGPIO_Pin;
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
