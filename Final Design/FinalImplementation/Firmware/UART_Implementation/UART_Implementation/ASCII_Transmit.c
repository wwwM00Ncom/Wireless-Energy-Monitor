/*
 * ASCII_Transmit.c
 *
 * Created: 17/08/2024 4:59:08 PM
 *  Author: xzhu664
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "ASCII_Transmit.h"

uint8_t ASCII_Transmit(uint8_t transmitting_number)
{
	uint8_t transmitted_number = transmitting_number + 48;
	return transmitted_number;
}