/******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.c
 *
 * Description: Source file for the Flame Sensor driver
 *
 * Author: Sandra Atef
 *
 *******************************************************************************/
#include "flame_sensor.h"
#include "gpio.h"
/*
 * Description :
 * Initializes the flame sensor pin direction.
 */
void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

/*
 * Description :
 * Reads the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void)
{
	uint8 sensor_value;
	sensor_value = GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);
	return sensor_value;
}


