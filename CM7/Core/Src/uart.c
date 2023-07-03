/*
 * uart.c
 *
 *  Created on: Jul 1, 2023
 *      Author: Tom
 */
#include "uart.h"

extern UART_HandleTypeDef huart3;

/*
 * @brief print any char to UART
 * @param char to print
 */
void UartChar(unsigned char c)
{
	 HAL_UART_Transmit(&huart3, &c, 1, 10);
}

/*
 * @brief print any int to UART
 * @param int to print
 */
void UartInt(unsigned int value)
{
	char text[8];

	HAL_UART_Transmit(&huart3, (uint8_t*) text, sprintf(text, "%d", value), 100);
}

/*
 * @brief print any string to UART
 * @param char* to string
 */
void UartString(unsigned char* s)
{
	int i = 0;

	for(; s[i]; i++)
		UartChar(s[i]);
}
