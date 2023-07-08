/*
 * lpf.h
 *
 *  Created on: Jul 7, 2023
 *      Author: Tom
 */

#ifndef INC_LPF_H_
#define INC_LPF_H_

#include "main.h"

typedef struct
{
	int32_t x;				// current filter output
	int32_t xPrevious;		// previous filter output
	uint32_t tau;			// tau in us
	uint32_t previousTime;  // previous update in us
}LpfData_t;

LpfData_t* LpfInit(uint32_t tau);
uint32_t LpfUpdate(LpfData_t*, uint32_t x);

#endif /* INC_LPF_H_ */
