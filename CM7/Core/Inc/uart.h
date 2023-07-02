/*
 * uart.h
 *
 *  Created on: Jul 1, 2023
 *      Author: Tom
 */
#ifndef SRC_UART_H_
#define SRC_UART_H_

#include "main.h"
#include "stdio.h"
#include "string.h"

void UartChar(unsigned char);
void UartInt(unsigned int);
void UartString(char*);

#endif /* SRC_UART_H_ */
