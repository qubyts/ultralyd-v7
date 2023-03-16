/*
 * print_server.c
 *
 *  Created on: 10 Mar 2023
 *      Author: metap
 */



#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "usart.h"
#include "stdbool.h"
#include "print_server.h"
#include "FreeRTOS.h"
//#include "stm32f4xx_hal_conf.h"
#include "cmsis_os2.h"

/* Define print buffer size */
#define PRINT_BUFFER_SIZE 64
#define callbacks HAL_UART_TxCpltCallback
#define MSG_size 16
#define print_Pool 32

//define the ids and uart handle shorthand
static osMessageQueueId_t 	PrintMsgQ;
osThreadId_t  		PrintThread;
osMemoryPoolId_t 	PrintPool;
osEventFlagsId_t 	Printflag;
UART_HandleTypeDef *uart_handle_p = &huart2;

void PrintServer(void *arg);




typedef struct{
	uint8_t buffer[PRINT_BUFFER_SIZE];
} PrintStruct;

//oppgave e
void PrintServerPrintf(const char *fmt, ...)
{

	PrintStruct *PrintMem;

	PrintMem = (PrintStruct *) osMemoryPoolAlloc(PrintPool, 0U);
	if(PrintMem == NULL){
		return;
	}

	va_list args;

	va_start(args, fmt);

	vsnprintf((char *)PrintMem -> buffer, PRINT_BUFFER_SIZE, fmt, args);

	va_end(args);

	if(osMessageQueuePut(PrintMsgQ, &PrintMem, 0U, 0U) != osOK){
		osMemoryPoolFree(PrintPool, PrintMem);
	}
}

void callbacks (UART_HandleTypeDef *huart){
	if(huart == uart_handle_p){
		osEventFlagsSet(Printflag, 0x1U);
	}
}


//oppgave f

void PrintServer(void *arg){
	PrintStruct *PrintMem;
	osStatus_t status;
	while(1){
		status = osMessageQueueGet(PrintMsgQ, (PrintStruct*)&PrintMem, NULL, osWaitForever);
		if(status  == osOK){
			if(HAL_UART_Transmit_DMA(uart_handle_p, (uint8_t*)PrintMem->buffer, strlen((char*)PrintMem->buffer)) == HAL_OK)
			{
				osEventFlagsWait(Printflag, 0x1U, osFlagsWaitAny, osWaitForever);

			}
		}

		osMemoryPoolFree(PrintPool, PrintMem);
	}
}


// oppgave c og d

_Bool PrintServerPrintfInit(void){
	PrintMsgQ = osMessageQueueNew(print_Pool, 4, NULL);
	PrintThread = osThreadNew(PrintServer, NULL, NULL);
	PrintPool = osMemoryPoolNew(print_Pool, sizeof(PrintStruct), NULL);
	Printflag = osEventFlagsNew(NULL);

	return true;
}
/* End of print_server.c */
