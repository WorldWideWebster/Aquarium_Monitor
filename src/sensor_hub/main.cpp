//#include <avr/io.h>
//#include <util/delay.h>
//#include "drivers/atm328p/custom/Uart.h"


//uint8_t my_strlen(const unsigned char *str)
//{
//	uint8_t i;
//
//	for (i = 0; str[i]; i++);
//	return i;
//}
//
//int main(void){
//	Uart uart(BAUD_RATE);
//
//	while(1)
//	{
//		uart.sendByteArr(String, my_strlen(String));
//		_delay_ms(5000);
//	}
//
//	return 0;
//}
//
//
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 8

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <ds18b20/ds18b20.h>

#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup()
{
	Serial.begin(9600);
	Serial.println("Hello, world?");
	sensors.begin();

}
int16_t temp;

void loop()
{
//	//Start conversion (without ROM matching)
//	ds18b20convert( &PORTB, &DDRB, &PINB, ( 1 << 0 ), NULL );
//
//	//Delay (sensor needs time to perform conversion)
//	_delay_ms( 1000 );
//
//	//Read temperature (without ROM matching)
//	ds18b20read( &PORTB, &DDRB, &PINB, ( 1 << 0 ), NULL, &temp );


// PROTOTYPE TEMPERATURE CODE
	sensors.requestTemperatures(); // Send the command to get temperature readings
	Serial.print("Temperature is: ");
	Serial.print(sensors.getTempFByIndex(0));
	Serial.print("F\n");

	// You can have more than one DS18B20 on the same bus.
	// 0 refers to the first IC on the wire
	delay(1000);

//	Serial.print(temp);
}