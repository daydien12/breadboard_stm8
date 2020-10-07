#ifndef     _DEFINE_H_
#define	    _DEFINE_H_

#include "stm8s_gpio.h"

#define DF_CPINCLK GPIO_PIN_5 //c5
#define DF_CPINSYN GPIO_PIN_4 //c4
#define DF_CPINRST GPIO_PIN_3 //c3

#define DF_DPIND15 GPIO_PIN_2 //d2
#define DF_CPIND13 GPIO_PIN_6 //c6
#define DF_CPIND01 GPIO_PIN_7 //c7
#define DF_DPIND09 GPIO_PIN_3 //d3

/*----------------------------------(CLK)----------------------------------*/	
#define DF_SETCLK       GPIO_WriteHigh(GPIOC, DF_CPINCLK)
#define DF_RESETCLK     GPIO_WriteLow(GPIOC, DF_CPINCLK)
/*----------------------------------(SYN)----------------------------------*/		
#define DF_SETSYN       GPIO_WriteHigh(GPIOC, DF_CPINSYN)
#define DF_RESETSYN     GPIO_WriteLow(GPIOC, DF_CPINSYN)
/*----------------------------------(RST)----------------------------------*/		
#define DF_SETRST       GPIO_WriteHigh(GPIOC, DF_CPINRST)
#define DF_RESETRST     GPIO_WriteLow(GPIOC, DF_CPINRST)

#endif

