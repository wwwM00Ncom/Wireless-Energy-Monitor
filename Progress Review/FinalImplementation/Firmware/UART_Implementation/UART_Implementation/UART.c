/*
 * UART.c
 *
 * Created: 17/08/2024 4:28:40 PM
 *  Author: xzhu664
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

void usart_init(uint16_t ubrr)
{
	UCSR0A |= (1<<UDRE0);
	UCSR0B |= (1<<TXEN0);
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
	UBRR0H |= (ubrr>>8);
	UBRR0L |= ubrr;
}

void usart_transmit(char data)
{
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}