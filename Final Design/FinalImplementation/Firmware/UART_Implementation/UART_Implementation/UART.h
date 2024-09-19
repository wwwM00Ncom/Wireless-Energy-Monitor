/*
 * UART.h
 *
 * Created: 17/08/2024 4:29:28 PM
 *  Author: xzhu664
 */ 

#ifndef UART_H_
#define UART_H_

void uart_init(uint16_t ubrr);
void uart_transmit(char data);

#endif /* UART_H_ */