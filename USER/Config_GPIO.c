#include "Config_GPIO.h"

void IO_Config(void);

void IO_Init(void)
{
  IO_Config();
  IO_RST();
  IO_SYN();
  IO_CLK();
}
void IO_Config(void)
{
  GPIO_Init(GPIOC, DF_CPINCLK, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOC, DF_CPINSYN, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOC, DF_CPINRST, GPIO_MODE_OUT_PP_LOW_FAST);
  
  GPIO_Init(GPIOC, DF_CPIND01, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOD, DF_DPIND09, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOC, DF_CPIND13, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOD, DF_DPIND15, GPIO_MODE_OUT_PP_LOW_FAST);
}

void IO_RST(void)
{
  DF_RESETRST;
  Fn_Delayms(1);
  DF_SETRST;
  Fn_Delayms(1);
}
void IO_SYN(void)
{
  DF_SETSYN;
  Fn_Delayms(1);
  DF_RESETSYN;
  Fn_Delayms(1);
}
void IO_CLK(void)
{
  DF_SETCLK;
  Fn_Delayms(1);
  DF_RESETCLK;
  Fn_Delayms(1);
}

void IO_ControlData(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins, unsigned char DataStt)
{
  if(DataStt)
    {
      GPIO_WriteHigh(GPIOx,PortPins);
    }
    else
    {
      GPIO_WriteLow(GPIOx,PortPins);
    }
}
