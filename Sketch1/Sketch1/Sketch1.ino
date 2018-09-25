/*
 Name:		Sketch1.ino
 Created:	10/21/2017 2:16:12 PM
 Author:	Oleg
*/

<<<<<<< HEAD
#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp_IN;
Adafruit_MCP23017 mcp_OUT;

int IN0_val, IN1_val, IN2_val, OUT0_val, serial_val;
=======

#include "LightSwitch.h"
>>>>>>> 08941adbaac0e111510e3bf93e1b31b26db9fb2a

// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.println("---SETUP START---");
	Serial.begin(9600);

<<<<<<< HEAD
	mcp_IN.begin(0);
	mcp_IN.pinMode(0, INPUT); //21
	mcp_IN.pinMode(1, INPUT); //22
	mcp_IN.pinMode(2, INPUT); //23
	//mcp_IN.pullUp(0, HIGH);  // turn on a 100K pullup internally

	mcp_OUT.begin(1);
	mcp_OUT.pinMode(0, OUTPUT);
=======
	setup_in_extender();
	setup_out_extender();
>>>>>>> 08941adbaac0e111510e3bf93e1b31b26db9fb2a

	Serial.println("---SETUP END---");
}

// the loop function runs over and over again until power down or reset
void loop() 
{
<<<<<<< HEAD
	
	if (Serial.available())
	{
		serial_val = Serial.read();
		//Serial.write(serial_val);
	}
	
	IN0_val = mcp_IN.digitalRead(0);
	IN1_val = mcp_IN.digitalRead(1);
	IN2_val = mcp_IN.digitalRead(2);

	//_MCP2307_1_O_IO1 = ((((((_MCP2307_0_O_IO9) ^ (_MCP2307_0_O_IO10))) ^ (_MCP2307_0_O_IO11))) ^ (_gtv1));
	OUT0_val = ((((((IN0_val) ^ (IN1_val))) ^ (IN2_val))) ^ (serial_val));
	//OUT0_val = ((((IN0_val) ^ (IN1_val))) ^ (IN2_val));
	//OUT0_val = IN0_val;


	mcp_OUT.digitalWrite(0, OUT0_val);
	/*
	Serial.println(IN0_val, DEC);
	Serial.println(IN1_val, DEC);
	Serial.println(IN2_val, DEC);

	Serial.println(OUT0_val, DEC);

	mcp_OUT.digitalWrite(1, HIGH);
	mcp_OUT.digitalWrite(7, LOW);
	Serial.println("=========================== LOOP ======================");	
	delay(1000);
	*/
}
=======
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

>>>>>>> 08941adbaac0e111510e3bf93e1b31b26db9fb2a
