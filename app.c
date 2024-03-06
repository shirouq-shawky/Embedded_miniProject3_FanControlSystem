/*
 * app.c
 *
 *  Created on: Oct 14, 2023
 *      Author: Shorouk Shawky
 */


#include"dc_motor.h"
#include"pwm_timer0.h"
#include"std_types.h"
#include"lm35_sensor.h"
#include "lcd.h"
#include"adc.h"
int main() {
	uint8 temperature;
	ADC_ConfigType ADC_Configurations={PRE_SCALE_8,INTERNAL};
	LCD_init();
	DcMotor_Init();
	ADC_init(&ADC_Configurations);
	LCD_moveCursor(0,2);
	LCD_displayString("FAN is ");
	LCD_moveCursor(1, 0);
	LCD_displayString("Temperature=    C");
	while(1){
		temperature = LM35_getTemperature();
		if (temperature<30){
			LCD_moveCursor(0, 9);
			LCD_displayString("OFF");
			LCD_moveCursor(1, 12);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(STOP, 0);
			LCD_displayCharacter(' ');
			}
		else if(temperature>=30){
			LCD_moveCursor(0, 9);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 12);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW, 25);
			LCD_displayCharacter(' ');
		}

		else if(temperature>=60){
			LCD_moveCursor(0, 9);
			LCD_displayString("ON");
			LCD_moveCursor(1, 12);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW, 50);
			LCD_displayCharacter(' ');
		}

		else if(temperature>=90){
			LCD_moveCursor(0, 9);
			LCD_displayString("ON");
			LCD_moveCursor(1, 12);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW, 75);
			LCD_displayCharacter(' ');
		}

		else if(temperature>=120){
			LCD_moveCursor(0, 9);
			LCD_displayString("ON");
			LCD_moveCursor(1, 12);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(CW, 100);
			LCD_displayCharacter(' ');
		}
	}
}
