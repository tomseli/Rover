/*
 * pwm.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Tom
 */
#include "pwm.h"

void InitPwm(TIM_HandleTypeDef* tim)
{
	HAL_TIM_PWM_Start(tim, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(tim, TIM_CHANNEL_2);
}

void SetPwm(TIM_TypeDef* tim, int channel, float ms)
{
	uint32_t clock = APB_1_FREQ/(tim->PSC+1); 	// 200 MHz/30 = 6,666,666 Hz
	uint32_t freq = clock/(tim->ARR+1); 		// 6,666,666 Hz / 20202 = 330.00033 Hz
	float period = 1.0/freq; 					// 1/330.00033 Hz = 3.03 ms
	float dc = (ms/1000)/period; 				// 2 ms / 3 ms * 100 = 66%

	switch(channel)
	{
		case 1:
			tim->CCR1 = (dc * (tim->ARR+1));
			break;
		case 2:
			tim->CCR2 = (dc * (tim->ARR+1));
			break;
		case 3:
			tim->CCR3 = (dc * (tim->ARR+1));
			break;
		case 4:
			tim->CCR4 = (dc * (tim->ARR+1));
			break;
	}
}

