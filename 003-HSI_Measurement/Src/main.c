/*
 ******************************************************************************
1) Configure the  RCC_CFGR
	a) MCO1 bit fields to select HSI as clock source.
	b) Configure prescaler of the MCO1.
2) Configure PA8 to AF0 mode to behave as MCO1 signal.
	a) Enable the peripheral clock for GPIAOA peripheral
	b) Configure the mode of GPIOA pin 8 as alternate function mode
	c) Configure the alternation function register to set the mode 0 for PA8

 ******************************************************************************
 */

#include <stdint.h>

// Clock configuration
#define RCC_BASE_ADDR					0x40023800UL
#define RCC_CFGR_OFFSET					0x08UL
#define RCC_CFGR_ADDR					(RCC_BASE_ADDR + RCC_CFGR_OFFSET)
#define RCC_CFGR_REG					*((volatile uint32_t *) RCC_CFGR_ADDR)

#define RCC_AHB1ENR_OFFSET				0x30UL
#define RCC_AHB1ENR_ADDR				(RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET)
#define RCC_AHB1ENR_REG					*((volatile uint32_t *) RCC_AHB1ENR_ADDR)

// GPIOx configuration
#define GPIOx_AFRH_OFFSET				0x24

#define GPIOA_BASE_ADDR					0x40020000
#define GPIOA_MODER_REG					*((volatile uint32_t *) GPIOA_BASE_ADDR)
#define GPIOA_AFRH_ADDR					(GPIOA_BASE_ADDR + GPIOx_AFRH_OFFSET)
#define GPIOA_AFRH_REG					*((volatile uint32_t *) GPIOA_AFRH_ADDR)

#define GPIOA_EN()						RCC_AHB1ENR_REG |= (1 << 0)
#define GPIOA_SET_MODE(pin, mode)		GPIOA_MODER_REG |= (mode << (pin*2)) // pin: 0 .. 15
#define GPIOA_SEL_AF0()					GPIOA_AFRH_REG |= (0 << 0)


int main(void)
{
	RCC_CFGR_REG &= ~(0x3 << 21); // clear bits 21 and 22.
    RCC_CFGR_REG |= (0x6 << 24);  // 110: division by 4

    // Configuration of GPIOA pin
    GPIOA_EN();
    GPIOA_SET_MODE(8, 0x2); // mode 0x10 Alternate function mode
    GPIOA_SEL_AF0();


	for(;;);
}
