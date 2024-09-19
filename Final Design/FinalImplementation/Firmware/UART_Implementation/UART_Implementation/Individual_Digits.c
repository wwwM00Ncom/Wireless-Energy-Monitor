/*
 * Individual_Digits.c
 *
 * Created: 17/08/2024 4:36:47 PM
 *  Author: xzhu664
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "Individual_Digits.h"

uint8_t Individual_Digits_first(float number)
{
	uint16_t integer;
	if ((number < 10) && (number > 0))
	{
		integer = number * 100;
	}
	else if ((number >= 10) && (number < 100))
	{
		integer = number * 10;
	}
	else
	{
		integer = number;
	}
	uint8_t first = (uint8_t) (integer / 100);
	
	return first;
}

uint8_t Individual_Digits_second(float number)
{
	uint16_t integer;
	if ((number < 10) && (number > 0))
	{
		integer = number * 100;
	}
	else if ((number >= 10) && (number < 100))
	{
		integer = number * 10;
	}
	else
	{
		integer = number;
	}
	uint8_t second = (uint8_t) ((integer / 10) % 10);
	
	return second;
}

uint8_t Individual_Digits_third(float number)
{
	uint16_t integer;
	if ((number < 10) && (number > 0))
	{
		integer = number * 100;
	}
	else if ((number >= 10) && (number < 100))
	{
		integer = number * 10;
	}
	else{
		integer = number;
	}
	uint8_t third = (uint8_t) (integer % 10);
	
	return third;
}