#include "SYS.h"

int main( void )
{
 
  UART_Init(9600);
  SYS_Init();
  while (1)
  {
    if(UART_Flag())
    {
      SYS_Run();
    }
  }
}