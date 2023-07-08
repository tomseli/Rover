/*
 * lpf.c
 *
 *  Created on: Jul 7, 2023
 *      Author: Tom
 */
#include "lpf.h"

extern TIM_HandleTypeDef htim2;

LpfData_t* LpfInit(uint32_t tau)
{
	LpfData_t* p = (LpfData_t*)malloc(sizeof(LpfData_t));
	p->tau = tau;
	p->previousTime = htim2.Instance->CNT;
	p->x = 0;
	p->xPrevious = 0;

	return p;
}

uint32_t LpfUpdate(LpfData_t* p, uint32_t x)
{
	uint32_t time = htim2.Instance->CNT;
	uint32_t dt = (time - p->previousTime);
	p->x = x;

	if(dt > 1e5)
		dt = 1e5;

	double x_dot_filter = (double)(p->x - p->xPrevious) / p->tau;
	double intermediate = p->xPrevious + (x_dot_filter * dt);
	p->xPrevious = (int32_t) intermediate;

	p->previousTime = time;

	return p->xPrevious;
}
