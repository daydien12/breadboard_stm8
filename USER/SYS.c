#include "SYS.h"

char vrc_DINCOR1[32] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
char vrc_DINCOR2[32] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

char vrc_DINCOL1[32] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
char vrc_DINCOL2[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0};


void SYS_Init(void)
{
  IO_Init();
}

void SYS_Run(void)
{
  int i=0;
  for (i = 32; i >= 0; i--)
  {
    IO_ControlData(GPIOC,DF_CPIND01,vrc_DINCOR1[i]);
    IO_ControlData(GPIOD,DF_DPIND09,vrc_DINCOR2[i]);
    
    IO_ControlData(GPIOC,DF_CPIND13,vrc_DINCOL1[i]);
    IO_ControlData(GPIOD,DF_DPIND15,vrc_DINCOL2[i]);
    IO_CLK();
  }
  IO_SYN();
}