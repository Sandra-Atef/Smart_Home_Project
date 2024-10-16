/******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.c
 *
 * Description: Source file for the LED driver
 *
 * Author: Sandra Atef
 *
 *******************************************************************************/
#include "led.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initializes all Leds (red, green, blue) pins direction.
 * Turn off all the Leds
 */
void LEDS_init(void)
{
	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_TURN_OFF);
	GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LED_TURN_OFF);
	GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LED_TURN_OFF);
}

/*
 * Description :
 * Turns on the specified LED.
 */
void LED_on(LED_ID id)
{
	switch(id)
	{
	case LED_RED_PIN_ID:
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_TURN_ON);
		break;
	case LED_GREEN_PIN_ID:
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LED_TURN_ON);
		break;
	case LED_BLUE_PIN_ID:
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LED_TURN_ON);
		break;
	}
}
/*
 * Description :
 * Turns off the specified LED.
 */

void LED_off(LED_ID id)
{
	switch(id)
	{
	case LED_RED_PIN_ID:
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_TURN_OFF);
		break;
	case LED_GREEN_PIN_ID:
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LED_TURN_OFF);
		break;
	case LED_BLUE_PIN_ID:
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LED_TURN_OFF);
		break;
	}
}
