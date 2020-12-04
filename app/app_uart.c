/*
*****************************************************************************************************************************************
FileName:			app_uart.c
Date:				2020.12.01

Description:
	1.
*****************************************************************************************************************************************
*/



#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "uart.h"
#include "app_uart.h"
#include "base_types.h"



#if		DEBUG_EN
#pragma import(__use_no_semihosting)             

struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       

_sys_exit(int x) 
{ 
	x = x; 
}


#if 0
int fputc(int ch, FILE *f)
{ 	
	while(RESET == USART_GetFlagStatus(DEBUG_USART, USART_FLAG_TC))
	{
		;
	}

	USART_SendData(DEBUG_USART, (uint16_t) ch);

	return ch;
}
#endif		//	End of "0"


#endif		//	End of "DEBUG_EN"

INT8 DebugUartInit()
{

	return 0;
}

INT8 DEBUGUartGpioInit()
{

	return 0;
}




























