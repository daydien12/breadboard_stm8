#ifndef     _SYS_H_
#define	    _SYS_H_

#include "stm8s.h"
#include "uart.h"
#include "Config_GPIO.h"
#include "tiny-json.h"
#include "DELAY.H"
#include <stdlib.h>

void SYS_Init(void);
void SYS_Run(void);
#endif

