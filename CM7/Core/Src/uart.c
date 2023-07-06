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

/*
 * @brief print int as hex to UART
 * @param int to print
 * @param minimum size of number, 2 = 0x00, 4 = 0x0000
 */
void UartIntHex(unsigned int value, unsigned int size)
{
	uint16_t remainder, quotient = 0;
	uint8_t result[] = {0, 0, 0, 0};
	uint8_t j = 0;
	quotient = value;

	while(quotient != 0)
	{
		remainder = quotient % 16;
		result[j++] = remainder < 10 ? 48 + remainder : 55 + remainder;
		quotient /= 16;
	}

	for(int i = 0; (i + j) < size; i++)
		UartInt(0);

	for(int i = j - 1; i >= 0; i--)
		UartChar(result[i]);
}

/*
 * TODO: print string to hex
 * AA BB CC DD
 */
void UartStringHex(unsigned char* c)
{

}
