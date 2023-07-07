/*
 * pwm.h
 *
 *  Created on: Jul 2, 2023
 *      Author: Tom
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "main.h"
#include "csrf.h"

#define APB_1_FREQ 200000000

#define TIM4_CH1_US_START 1500
#define TIM4_CH2_US_START 1500

void InitPwm(TIM_HandleTypeDef*);
void InitPwmGlobals();
void SetPwm(TIM_TypeDef*, int, int);

#endif /* INC_PWM_H_ */
