/*
 * pwm.h
 *
 *  Created on: Jul 2, 2023
 *      Author: Tom
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "main.h"

#define APB_1_FREQ 200000000

void InitPwm(TIM_HandleTypeDef*);
void SetPwm(TIM_TypeDef*, int, float);

#endif /* INC_PWM_H_ */
