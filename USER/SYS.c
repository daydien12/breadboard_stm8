#include "SYS.h"

char vrc_DINCOR1[32] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
char vrc_DINCOR2[32] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

char vrc_DINCOL1[32] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
char vrc_DINCOL2[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0};

unsigned long Convert2Number (char *_Str);

void SYS_Init(void)
{
  IO_Init();
}

void SYS_Run(void)
{
  int i = 0;
  json_t mem[32];
  //char str1[] = "{\"L1\":\"f0000000\",\"L2\":\"0f000000\",\"L3\":\"00f00000\",\"L4\":\"000f0000\"}";
  json_t const* json = json_create( RRX, mem, sizeof mem / sizeof * mem );
  long Number1 = Convert2Number(json_ReturnData(json, "L1"));
  long Number2 = Convert2Number(json_ReturnData(json, "L2"));
  long Number3 = Convert2Number(json_ReturnData(json, "L3"));
  long Number4 = Convert2Number(json_ReturnData(json, "L4"));

  for (int i = 32; i >= 0; i--)
  {
    UART_Send_Char(((Number1 >> i) & 0x00000001) + 48);
    Fn_Delayms(1);
  }
  UART_Send_String("\n");
  
  for (int i = 32; i >= 0; i--)
  {
    UART_Send_Char(((Number2 >> i) & 0x00000001) + 48);
    Fn_Delayms(1);
  }
  UART_Send_String("\n");
  
  for (int i = 32; i >= 0; i--)
  {
    UART_Send_Char(((Number3 >> i) & 0x00000001) + 48);
    Fn_Delayms(1);
  }
  UART_Send_String("\n");
  
  for (int i = 32; i >= 0; i--)
  {
    UART_Send_Char(((Number4 >> i) & 0x00000001) + 48);
    Fn_Delayms(1);
  }
  UART_Send_String("\n");

  for (i = 32; i >= 0; i--)
  {
    IO_ControlData(GPIOC,DF_CPIND01,((Number1 >> i) & 0x00000001) );
    IO_ControlData(GPIOD,DF_DPIND09,((Number2 >> i) & 0x00000001) );

    IO_ControlData(GPIOC,DF_CPIND13,((Number3 >> i) & 0x00000001) );
    IO_ControlData(GPIOD,DF_DPIND15,((Number4 >> i) & 0x00000001) );
    IO_CLK();
  }
  IO_SYN();
}


unsigned long Convert2Number (char *_Str) {
  char vrsc_A;
  unsigned long Return = 0;

  for (int i = 0; i < 8; i++) {
    if ((*_Str) <= '9') {
      vrsc_A = (*_Str) - '0';
    }
    else {
      vrsc_A = (*_Str) - 'a' + 10;
    }
    Return <<= 4;
    Return |= vrsc_A;
    _Str++;
  }

  return Return;
}