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

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 5
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
	mySerial.begin(9600);
	mySerial.println("Hello, world?");
	sensors.begin();
}

void loop()
{
	sensors.requestTemperatures(); // Send the command to get temperature readings
	mySerial.print(sensors.getTempFByIndex(0)); // Why "byIndex"?
	// You can have more than one DS18B20 on the same bus.
	// 0 refers to the first IC on the wire
	delay(1000);
}