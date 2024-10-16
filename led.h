/******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.h
 *
 * Description: Header file for the LED driver
 *
 * Author: Sandra Atef
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
# define LED_RED_PORT_ID            PORTB_ID
# define LED_GREEN_PORT_ID          PORTB_ID
# define LED_BLUE_PORT_ID           PORTB_ID
# define LED_RED_PIN_ID             PIN5_ID
# define LED_GREEN_PIN_ID           PIN6_ID
# define LED_BLUE_PIN_ID            PIN7_ID
# define LED_TURN_ON                LOGIC_HIGH
# define LED_TURN_OFF               LOGIC_LOW

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	LED_RED_PIN_ID, LED_GREEN_PIN_ID, LED_BLUE_PIN_ID
}LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initializes all Leds (red, green, blue) pins direction.
 * Turn off all the Leds
 */
void LEDS_init(void);

/*
 * Description :
 * Turns on the specified LED.
 */
void LED_on(LED_ID id);

/*
 * Description :
 * Turns off the specified LED.
 */

void LED_off(LED_ID id);

#endif /* LED_H_ */
