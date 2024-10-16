/*
 ================================================================================================
 Name        : main.c
 Author      : Sandra Atef
 Description : Smart_Home_Project
 Date        : 9/10/2024
 ================================================================================================
 */
#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "dc_motor.h"
#include "flame_sensor.h"
#include "lm35_sensor.h"
#include "ldr_sensor.h"
#include "adc.h"
#include "gpio.h"

int main (void)
{
	uint16 light_value;
	uint8 temp_value;
	uint8 flame_sensor_value;
	uint8 flag_sensor=0,flag=0;

	/*initialize adc driver*/
	ADC_init();
	/*initialize lcd driver*/
	LCD_init();
	/*initialize flame sensor driver*/
	FlameSensor_init();
	/*initialize buzzer driver*/
	Buzzer_init();
	/*initialize dc motor driver*/
	DcMotor_Init();
	/*initialize leds driver*/
	LEDS_init();


	while(1)
	{
		/*read values of sensors*/
		temp_value = LM35_getTemperature();
		light_value = LDR_getLightIntensity();
		flame_sensor_value = FlameSensor_getValue();

		if (flame_sensor_value)
		{
			if(flag_sensor == 0)
			{
				Buzzer_on();
				LCD_clearScreen();
				LCD_displayStringRowColumn(0, 0,"Critical alert!");
				flag_sensor = 1;
			}
		}
		else
		{
			if(flag_sensor == 1)
			{
				Buzzer_off();
				LCD_clearScreen();
				flag_sensor = 0;
			}

			LCD_displayStringRowColumn(0,3,"FAN is ");

			if(flag == 1)
			{
				LCD_displayString("ON");
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_displayString("OFF");
			}

			/*light intensity display*/
			LCD_displayStringRowColumn(1, 8, "LDR=");
			LCD_moveCursor(1, 12);
			if(light_value >= 100)
			{
				LCD_intgerToString(light_value);
				LCD_displayCharacter('%');
			}
			else if(light_value >= 10)
			{
				LCD_intgerToString(light_value);
				LCD_displayCharacter(' ');
				LCD_displayCharacter('%');
			}
			else
			{
				LCD_intgerToString(light_value);
				LCD_displayCharacter(' ');
				LCD_displayCharacter(' ');
				LCD_displayCharacter('%');
			}

			/*temperature value display*/

			LCD_displayStringRowColumn(1, 0, "Temp=");
			LCD_moveCursor(1, 5);
			if(temp_value >= 100)
			{
				LCD_intgerToString(temp_value);
			}
			else if(temp_value >= 10)
			{
				LCD_intgerToString(temp_value);
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_intgerToString(temp_value);
				LCD_displayCharacter(' ');
				LCD_displayCharacter(' ');
			}


			/*LDR*/

			if (light_value <= 15)
			{
				LED_on(LED_RED_PIN_ID);
				LED_on(LED_GREEN_PIN_ID);
				LED_on(LED_BLUE_PIN_ID);
			}
			else if ((light_value >= 16) && (light_value <= 50))
			{
				LED_on(LED_RED_PIN_ID);
				LED_on(LED_GREEN_PIN_ID);
				LED_off(LED_BLUE_PIN_ID);
			}
			else if ((light_value >= 51) && (light_value <= 70))
			{
				LED_on(LED_RED_PIN_ID);
				LED_off(LED_GREEN_PIN_ID);
				LED_off(LED_BLUE_PIN_ID);
			}
			else if (light_value > 70)
			{
				LED_off(LED_RED_PIN_ID);
				LED_off(LED_GREEN_PIN_ID);
				LED_off(LED_BLUE_PIN_ID);
			}
			if (light_value <= 15)
			{
				LED_on(LED_RED_PIN_ID);
				LED_on(LED_GREEN_PIN_ID);
				LED_on(LED_BLUE_PIN_ID);
			}
			else if ((light_value >= 16) && (light_value <= 50))
			{
				LED_on(LED_RED_PIN_ID);
				LED_on(LED_GREEN_PIN_ID);
				LED_off(LED_BLUE_PIN_ID);
			}
			else if ((light_value >= 51) && (light_value <= 70))
			{
				LED_on(LED_RED_PIN_ID);
				LED_off(LED_GREEN_PIN_ID);
				LED_off(LED_BLUE_PIN_ID);
			}
			else if (light_value > 70)
			{
				LED_off(LED_RED_PIN_ID);
				LED_off(LED_GREEN_PIN_ID);
				LED_off(LED_BLUE_PIN_ID);
			}

			/*MOTOR*/

			if (temp_value >= 40)
			{
				flag=1;
				DcMotor_Rotate(CW,255);
			}
			else if ((temp_value >= 35) && (temp_value < 40))
			{
				flag=1;
				DcMotor_Rotate(CW,192);
			}
			else if ((temp_value >= 30) && (temp_value < 35))
			{
				flag=1;
				DcMotor_Rotate(CW,128);
			}
			else if ((temp_value >= 25) && (temp_value < 30))
			{
				flag=1;
				DcMotor_Rotate(CW,64);
			}
			else if (temp_value < 25)
			{
				flag=0;
				DcMotor_Rotate(Stop,0);
			}

		}

	}
}

