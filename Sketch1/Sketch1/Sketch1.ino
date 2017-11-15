/*
 Name:		Sketch1.ino
 Created:	10/21/2017 2:16:12 PM
 Author:	Oleg
*/


#include "LightSwitch.h"

// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.println("---SETUP START---");
	Serial.begin(9600);

	setup_in_extender();
	setup_out_extender();

	Serial.println("---SETUP END---");
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	gostinnaya_light();
 
	/*
	if (Serial.available())
	{
		serial_val = Serial.read()==48 ? 0 : 1;
		get_uart=1;
	}

	get_uart=-1;
	*/
}

