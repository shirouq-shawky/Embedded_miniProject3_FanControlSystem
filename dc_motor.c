/*
 * dc_motor.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Shorouk Shawky
 */

#include"dc_motor.h"
#include"pwm_timer0.h"
#include"common_macros.h"
#include"gpio.h"

/*
 * Description :
 * setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void){
	GPIO_setupPinDirection(DC_MOTOR_PIN1_PORT_ID,DC_MOTOR_PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PIN2_PORT_ID,DC_MOTOR_PIN2_ID,PIN_OUTPUT);
	DcMotor_Rotate(STOP,0);
}


/*
 * Description :
 * rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {

	switch (state) {
	case STOP:
		GPIO_writePin(DC_MOTOR_PIN1_PORT_ID, DC_MOTOR_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PIN2_PORT_ID, DC_MOTOR_PIN2_ID, LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(DC_MOTOR_PIN1_PORT_ID, DC_MOTOR_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PIN2_PORT_ID, DC_MOTOR_PIN2_ID, LOGIC_LOW);
		break;
	case A_CW:
		GPIO_writePin(DC_MOTOR_PIN1_PORT_ID, DC_MOTOR_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PIN2_PORT_ID, DC_MOTOR_PIN2_ID, LOGIC_HIGH);
		break;
	}
	Timer0_PWM_Init(speed);


}
