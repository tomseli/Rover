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

#define CRSF_MAX_PAYLOAD 64

void CsrfDecode(uint8_t*);

#endif /* SRC_CSRF_H_ */
