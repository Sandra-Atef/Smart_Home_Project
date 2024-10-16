/******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the DC MOTOR driver
 *
 * Author: Sandra Atef
 *
 *******************************************************************************/
#include "dc_motor.h"
#include "pwm.h"
#include "gpio.h"

/*
 * Description :
 * Initializes the DC motor by setting the direction for the motor pins
 * and stopping the motor at the beginning.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);

}

/*
 * Description :
 * Controls the motor's state (Clockwise/Anti-Clockwise/Stop)
 * and adjusts the speed based on the input duty cycle.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	PWM_Timer0_Start(speed);
	switch(state)
	{
	case CW:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	case A_CW:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	case Stop:
		GPIO_writePin(DC_MOTOR_IN1_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	}
}

