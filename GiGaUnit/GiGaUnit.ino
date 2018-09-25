// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       GiGaUnit.ino
    Created:	9/16/2018 11:00:08 PM
    Author:     DESKTOP-H0VFUKT\prosp
*/

//#include <VirtualWire/VirtualWire.h>
//#include <RCSwitch/RCSwitch.h>
#include <VirtualWire.h>
#include <RCSwitch.h>

// Define User Types below here or use a .h file
#define PIN_KEYBOARD_ANALOG 2
#define PIN_LIGHTSENSOR_ANALOG 1
#define PIN_AIR_ANALOG 0

#define PIN_MOTION_DIGITAL 3
#define PIN_DHT22_DIGITAL 4
#define PIN_AIR_DIGITAL 5
#define PIN_IR_DIGITAL 7
#define PIN_433_TRANS_DIGITAL 8
#define PIN_433_RES_DIGITAL 9
#define PIN_315_TRANS_DIGITAL 10
#define PIN_315_RES_DIGITAL 11
#define PIN_WATER_C_FLOW_DIGITAL 18
#define PIN_WATER_H_FLOW_DIGITAL 19
#define PIN_WATER_C_TEMP_DIGITAL 22
#define PIN_WATER_H_TEMP_DIGITAL 23

#define PIN_SDA 20
#define PIN_SCL 21

#define PIN_SPI_MISO_DIGITAL 50
#define PIN_SPI_MOSI_DIGITAL 51
#define PIN_SPI_SCK_DIGITAL 52

#define PIN_SPI_MISO_NRF_DIGITAL 50
#define PIN_SPI_MOSI_NRF_DIGITAL 51
#define PIN_SPI_SCK_NRF_DIGITAL 52
#define PIN_SPI_CE_NRF_DIGITAL 6
#define PIN_SPI_CS_MRF_DIGITAL 53

RCSwitch rc315 = RCSwitch();
RCSwitch rc433 = RCSwitch();

//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
void setup()
{	
	rc315.enableTransmit(PIN_315_TRANS_DIGITAL);
	rc315.enableReceive(PIN_315_RES_DIGITAL);

	rc433.enableTransmit(PIN_433_TRANS_DIGITAL);
	rc433.enableReceive(PIN_433_RES_DIGITAL);




}

// Add the main program code into the continuous loop() function
void loop()
{


}
