/******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the DC MOTOR driver
 *
 * Author: Sandra Atef
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

# define DC_MOTOR_IN1_PORT_ID            PORTB_ID
# define DC_MOTOR_IN2_PORT_ID            PORTB_ID
# define DC_MOTOR_IN1_PIN_ID             PIN0_ID
# define DC_MOTOR_IN2_PIN_ID             PIN1_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	CW, A_CW, Stop
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initializes the DC motor by setting the direction for the motor pins
 * and stopping the motor at the beginning.
 */
void DcMotor_Init(void);

/*
 * Description :
 * Controls the motor's state (Clockwise/Anti-Clockwise/Stop)
 * and adjusts the speed based on the input duty cycle.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
