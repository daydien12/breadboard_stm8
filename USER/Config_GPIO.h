#ifndef     _CONFIGGPIO_H_
#define	    _CONFIGGPIO_H_
#include "stm8s_gpio.h"
#include "Define.h"
#include "DELAY.H"

  void IO_Init(void);
  void IO_RST(void);
  void IO_SYN(void);
  void IO_CLK(void);
  void IO_ControlData(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins, unsigned char DataStt);
#endif

