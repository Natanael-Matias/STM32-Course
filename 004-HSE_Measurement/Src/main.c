/*
 ******************************************************************************
1. Enable the HSE clock using HSEON bit (RCC_CR)
2. Wait until HSE clock from the external crystal stabilizes (only if crystal is connected)
3. Switch the system clock to HSE (RCC_CFGR)
4. Do MCO1 setting to measure it
 ******************************************************************************
 */

#include <stdint.h>

// Clock configuration
#define RCC_BASE_ADDR					0x40023800UL
#define RCC_CR_OFFSET					0x00UL
#define RCC_CFGR_OFFSET					0x08UL
#define RCC_CR_ADDR						(RCC_BASE_ADDR + RCC_CR_OFFSET)
#define RCC_CFGR_ADDR					(RCC_BASE_ADDR + RCC_CFGR_OFFSET)
#define RCC_CR_REG						*((volatile uint32_t *) RCC_CR_ADDR)
#define RCC_CFGR_REG					*((volatile uint32_t *) RCC_CFGR_ADDR)

#define HSE_ON()						RCC_CR_REG |= (1 << 16)
#define SYS_CLK_SW(sysClk)				RCC_CFGR_REG |= (sysClk << 0) // 0x0: HSI; 0x1: HSE; 0x2: PLL; 0x3: not allowed

#define RCC_AHB1ENR_OFFSET				0x30UL
#define RCC_AHB1ENR_ADDR				(RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET)
#define RCC_AHB1ENR_REG					*((volatile uint32_t *) RCC_AHB1ENR_ADDR)

// GPIOx configuration
#define GPIOx_AFRH_OFFSET				0x24

#define GPIOA_BASE_ADDR					0x40020000
#define GPIOA_MODE_REG					*((volatile uint32_t *) GPIOA_BASE_ADDR)
#define GPIOA_AFRH_ADDR					(GPIOA_BASE_ADDR + GPIOx_AFRH_OFFSET)
#define GPIOA_AFRH_REG					*((volatile uint32_t *) GPIOA_AFRH_ADDR)

#define GPIOA_EN()						RCC_AHB1ENR_REG |= (1 << 0)
#define GPIOA_SET_MODE(pin, mode)		GPIOA_MODE_REG |= (mode << (pin*2)) // pin: 0 .. 15
#define GPIOA_SEL_AF0()					GPIOA_AFRH_REG |= (0 << 0)

void WaitHSE_RDY(void) {
	while(!(RCC_CR_REG & (1 << 17)));
}

int main(void)
{
	HSE_ON();
	WaitHSE_RDY();
	SYS_CLK_SW(0x1);

	RCC_CFGR_REG |= (0x2 << 21); // clear bits 21 and set 22.
	RCC_CFGR_REG |= (0x0 << 24);  // no division

	// Configuration of GPIOA pin
	GPIOA_EN();
	GPIOA_SET_MODE(8, 0x2); // mode 0x10 Alternate function mode
	GPIOA_SEL_AF0();

	for(;;);
}
