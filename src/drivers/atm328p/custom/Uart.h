//
// Created by Sean on 2/23/2021.
//

#ifndef SENSOR_HUB_UART_H
#define SENSOR_HUB_UART_H

#include <stdint.h>

#define DEFAULT_BAUD 9600
#define BAUD_RATE DEFAULT_BAUD
#define BAUD_PRESCALER  (((F_CPU / (BAUD_RATE * 16UL))) - 1)

class Uart
{
public:
	Uart(uint32_t baud);
	void init(void);
	unsigned char receiveByte(void);
	void receiveByteArray(char* buffer, uint8_t buffSize, char stopChar);
	void sendByte( unsigned char data);
	void sendByteArr(unsigned char* byteArr, uint8_t arrSize);
	void sendString(char* StringPtr);


private:
	uint32_t m_baud;
};


#endif //SENSOR_HUB_UART_H
