/*
 * UART_Implementation.c
 *
 * Created: 17/08/2024 4:23:09 PM
 * Author : xzhu664
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "UART.h"
#include "Individual_Digits.h"
#include "ASCII_Transmit.h"

#define F_OSC 2000000
#define BAUD 9600
#define UBRR F_OSC/16/BAUD-1

#define   RMSVoltage    14.5
#define   PeakCurrent   125
#define   Power         1.60

int main(void)
{
	/*initial*/
	uart_init(UBRR);
	
	/*Extract the individual digits of a 3 digit number*/
	uint8_t RMS_V[3];
	RMS_V[0] = Individual_Digits_first(RMSVoltage);
	RMS_V[1] = Individual_Digits_second(RMSVoltage);
	RMS_V[2] = Individual_Digits_third(RMSVoltage);
	uint8_t Peak_I[3];
	Peak_I[0] = Individual_Digits_first(PeakCurrent);
	Peak_I[1] = Individual_Digits_second(PeakCurrent);
	Peak_I[2] = Individual_Digits_third(PeakCurrent);
	uint8_t P[3];
	P[0] = Individual_Digits_first(Power);
	P[1] = Individual_Digits_second(Power);
	P[2] = Individual_Digits_third(Power);
	
	/*Output ASCII code*/
	/*32 = space; 88 = X (use to find if there is any bug, it will show 'X' when output); 46 = '.'; 13 + 10 = new line*/
	char RMS_V_Print[22] = {'R', 'M', 'S', 32, 'V', 'o', 'l', 't', 'a', 'g', 'e', 32, 'i', 's', ':', 32, 88, 88, 46, 88, 13, 10};
	RMS_V_Print[16] = ASCII_Transmit(RMS_V[0]);
	RMS_V_Print[17] = ASCII_Transmit(RMS_V[1]);
	RMS_V_Print[19] = ASCII_Transmit(RMS_V[2]);
	char Peak_I_Print[22] = {'P', 'e', 'a', 'k', 32, 'C', 'u', 'r', 'r', 'e', 'n', 't', 32, 'i', 's', ':', 32, 88, 88, 88, 13, 10};
	Peak_I_Print[17] = ASCII_Transmit(Peak_I[0]);
	Peak_I_Print[18] = ASCII_Transmit(Peak_I[1]);
	Peak_I_Print[19] = ASCII_Transmit(Peak_I[2]);
	char Power_Print[18] = {'P', 'o', 'w', 'e', 'r', 32, 'i', 's', ':', 32, 88, 46, 88, 88, 13, 10, 13, 10};
	Power_Print[10] = ASCII_Transmit(P[0]);
	Power_Print[12] = ASCII_Transmit(P[1]);
	Power_Print[13] = ASCII_Transmit(P[2]);
	
    while (1) 
    {
		for (uint8_t count1 = 0; count1 < 22; count1++)
		{
			uart_transmit(RMS_V_Print[count1]);
			_delay_ms(15);
		}
		for (uint8_t count2 = 0; count2 < 22; count2++)
		{
			uart_transmit(Peak_I_Print[count2]);
			_delay_ms(15);
		}
		for (uint8_t count3 = 0; count3 < 18; count3++)
		{
			uart_transmit(Power_Print[count3]);
			_delay_ms(15);
		}
		_delay_ms(70);
		/*time: (22 + 22 + 18) * 15ms + 70ms = 1000ms = 1s*/
    }
}

