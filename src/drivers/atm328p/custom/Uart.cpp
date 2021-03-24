//
// Created by Sean on 2/23/2021.
//

#include "Uart.h"
#include <avr/io.h>

Uart::Uart(uint32_t baud) : m_baud(baud)
{
	this->init();
}

void Uart::init()
{
	// Set baud rate registers
	UBRR0H = (uint8_t)(BAUD_PRESCALER >> 8);
	UBRR0L = (uint8_t)(BAUD_PRESCALER & 0xFF);
	// Enable TX/RX
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	// Set 8 bit character
	UCSR0C = (3 << UCSZ00);
}

unsigned char Uart::receiveByte(void)
{
	// Wait for rx
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}


void Uart::receiveByteArray(char* buffer, uint8_t buffSize, char stopChar = '\r')
{
	uint8_t bufIdx = 0;
	// receive byte while received character is not stopChar
	// and end of buffer has not been reached
	do
	{
		buffer[bufIdx++] = this->receiveByte();
	}
	while((bufIdx < buffSize) && (buffer[bufIdx] != stopChar));
}

void Uart::sendByte( unsigned char data)
{
	// Wait for tx buffer to be empty
	while(!(UCSR0A & (1 << UDRE0)));
	// Load tx register
	UDR0 = data;

}

void Uart::sendString(char* StringPtr)
{
	while(*StringPtr != 0x00)
	{
		sendByte(*StringPtr);
		StringPtr++;
	}
}
void Uart::sendByteArr(unsigned char* byteArr, uint8_t arrSize)
{
	for(int i = 0; i < arrSize; i++)
	{
		sendByte(byteArr[i]);
	}
}