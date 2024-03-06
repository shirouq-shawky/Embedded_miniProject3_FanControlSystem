/*
 * pwm_timer0.h
 *
 *  Created on: Oct 14, 2023
 *      Author: Shorouk Shawky
 */

#ifndef PWM_TIMER0_H_
#define PWM_TIMER0_H_
#include "std_types.h"


/*Functions Prototypes*/
/*Description:
 * The function responsible for trigger the Timer0 with the PWM Mode
 * Setup the PWM mode with Non-Inverting.
 * Setup the prescaler with F_CPU/8
 * Setup the compare value based on the required input duty cycle
 * Setup the direction for OC0 as output pin through the GPIO driver.
 * The generated PWM signal frequency will be 500Hz to control the DC
Motor speed.
 */
void Timer0_PWM_Init(uint8 set_duty_cycle);


#endif /* PWM_TIMER0_H_ */
