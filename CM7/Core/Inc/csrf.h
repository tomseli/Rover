/*
 * csrf.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Tom
 */

#ifndef SRC_CSRF_H_
#define SRC_CSRF_H_

#include "main.h"
#include "uart.h" // print functions
#include <stdlib.h> // malloc

#define CRSF_MAX_FRAME 64
#define CRSF_MAX_PAYLOAD 60

typedef union
{
    uint8_t payload[CRSF_MAX_PAYLOAD];

    struct __attribute__((packed))
    {
    	uint16_t ch00:11;
    	uint16_t ch01:11;
    	uint16_t ch02:11;
    	uint16_t ch03:11;
    	uint16_t ch04:11;
    	uint16_t ch05:11;
    	uint16_t ch06:11;
    	uint16_t ch07:11;
    	uint16_t ch08:11;
    	uint16_t ch09:11;
    	uint16_t ch10:11;
    	uint16_t ch11:11;
    	uint16_t ch12:11;
    	uint16_t ch13:11;
    	uint16_t ch14:11;
    	uint16_t ch15:11;
    } channels;
}CsrfRcChannels_t;

typedef struct
{
	uint16_t ch00;
	uint16_t ch01;
	uint16_t ch02;
	uint16_t ch03;
	uint16_t ch04;
	uint16_t ch05;
	uint16_t ch06;
	uint16_t ch07;
	uint16_t ch08;
	uint16_t ch09;
	uint16_t ch10;
	uint16_t ch11;
	uint16_t ch12;
	uint16_t ch13;
	uint16_t ch14;
	uint16_t ch15;
}PwmRcChannels_t;

void CsrfDecode(uint8_t*);
void CsrfLinkStatistics();
void CsrfRcChannels(uint8_t*, CsrfRcChannels_t*);
void CsrfDevicePing();
void CsrfDeviceInfo();
void CsrfParameterSettings();
void CsrfParameterRead();
void CsrfParamterWrite();
void CsrfCommand();

void CsrfToPwm(CsrfRcChannels_t*);



#endif /* SRC_CSRF_H_ */
