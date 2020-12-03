/*
*****************************************************************************************************************************************
FileName:			app_uart.h
Date:			2020.12.01

Description:
	1.
*****************************************************************************************************************************************
*/

#ifndef		APP_UART_H
#define		APP_UART_H

#include "hc32l13x.h"

#include "base_types.h"
#include "gpio.h"
#include "uart.h"


#define		DEBUG_EN					1							//	默认调试使能，出货固件需要禁用关闭串口打印;

/* UART 端口分配 */
#define		DEBUG_UART				M0P_UART0
#define		GPRS_UART					M0P_UART1
#define		RS485_UART				M0P_LPUART0
#define		RS232_UART				M0P_LPUART1

/* UART 引脚分配 */
#define		DEBUG_UART_RX_PIN			GpioPin13						//	PA13
#define		DEBUG_UART_TX_PIN			GpioPin14						//	PA14

#define		GPRS_UART_RX_PIN			GpioPin3						//	PA03
#define		GPRS_UART_TX_PIN			GpioPin2						//	PA02

#define		RS485_UART_RX_PIN			GpioPin11						//	PB11
#define		RS485_UART_TX_PIN			GpioPin12						//	PB12

#define		RS232_UART_RX_PIN			GpioPin1						//	PA01
#define		RS232_UART_TX_PIN			GpioPin0						//	PA00

/* 相关函数声明 */
INT8 DebugUartInit(void);

#endif		//	End of "APP_UART_H"
































