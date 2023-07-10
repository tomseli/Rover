PWM Frequency: 330 Hz
PWM Range: 1ms - 2ms

Timers:
TIM4
Best fit, since it has 4 output channels 

RM0399, p.140 TIM4is on APB1

PWM Frequency:
$$
F_{pwm} = \frac{F_{clk}}{ARR \cdot PSC}
$$
PWM Duty Cycle
$$
DutcyCycle_{pwm}[\%] = \frac{CCR_x}{ARR_x}
$$
Where
ARR: Auto Reload Register
CCR: Count Compare Register
PSC: Prescaler

# Calc
PWM Frequency
$$
330 \ Hz = \frac{200e6 \ Hz}{ARR \cdot PSC} 
$$
$$
ARR \cdot PSC = \frac{200e6 \ Hz}{330 \ Hz}
$$
$$ARR = \frac{200e6 \ Hz}{330 \ Hz \cdot PSC }$$
PSC: 30
$$ARR = \frac{200e6 \ Hz}{330 \ Hz \cdot 30 }$$

![[Pasted image 20230702101421.png]]