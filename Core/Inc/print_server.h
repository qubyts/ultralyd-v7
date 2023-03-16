/*
 * print_server.h
 *
 *  Created on: 10 Mar 2023
 *      Author: metap
 */

#ifndef INC_PRINT_SERVER_H_
#define INC_PRINT_SERVER_H_


void PrintServerPrintf(const char *fmt, ...);
_Bool PrintServerPrintfInit(void);
#if 1
#define printf(...) PrintServerPrintf(__VA_ARGS__)
#else
#define printf(...) do {} while(0)
#endif



#endif /* INC_PRINT_SERVER_H_ */
