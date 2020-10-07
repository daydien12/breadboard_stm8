#include "SYS.h"

void delay_ms(int a)
{
  for (int i = 0; i < a; i++)
    for (int index = 0; index < 400; index++);
}

int main( void )
{
  UART_Init(9600);
  SYS_Init();
  while (1)
  {
    if(UART_Flag())
    {
      SYS_Run();
      UART_Send_Array_RX();
    }
  }
}