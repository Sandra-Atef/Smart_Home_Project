/******************************************************************************
 *
 * Module: LDR Sensor
 *
 * File Name: ldr_sensor.c
 *
 * Description: Source file for the LDR Sensor driver
 *
 * Author: Sandra Atef
 *
 *******************************************************************************/
#include "ldr_sensor.h"
#include "adc.h"

/*
 * Description :
 * Function responsible for calculate the light intensity from the ADC digital value.
 */

uint16 LDR_getLightIntensity(void)
{
	uint16 light_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the ldr sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the light intensity from the ADC value*/
	light_value = (uint16)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return light_value;
}


