// 
// 
// 

#include "LightSwitch.h"

#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp1_IN;
Adafruit_MCP23017 mcp1_OUT;

Adafruit_MCP23017 mcp2_IN;
Adafruit_MCP23017 mcp2_OUT;

//gostinnaya
int gostinnaya_in_tochka1, gostinnaya_in_svet1, gostinnaya_in_led1;
int gostinnaya_out_tochka, gostinnaya_out_svet, gostinnaya_out_led;
int gostinnaya_tochka, gostinnaya_svet, gostinnaya_led;

// koridor
int koridor_in_bra1, koridor_in_tochka1, koridor_in_tochka2, koridor_in_tochka3, koridor_in_led1;
int koridor_out_bra, koridor_out_tochka, koridor_out_led;
int koridor_bra, koridor_tochka, koridor_led;

// kuhna
int kuhna_in_rabzone1, kuhna_in_svet1, kuhna_in_led_up1, kuhna_in_led_down1;
int kuhna_out_rabzone, kuhna_out_svet, kuhna_out_led_up, kuhna_out_led_down;
int kuhna_rabzone, kuhna_svet, kuhna_led_up, kuhna_led_down;

//san uzel
int sanuzel_in_tochka1, sanuzel_in_led1;
int sanuzel_out_tochka, sanuzel_out_led;
int sanuzel_tochka, sanuzel_led;

// spalna
int spalna_in_tochka1, spalna_in_tochka2, spalna_in_tochka3, spalna_in_bra_left1, spalna_in_bra_right1;
int spalna_out_tochka, spalna_out_bra_left, spalna_out_bra_right;
int spalna_tochka, spalna_bra_left, spalna_bra_right;

// kabinet
int kabinet_in_tochka1;
int kabinet_out_tochka;
int kabinet_tochka;

void setup_in_extender(void)
{
	mcp1_IN.begin(0);
	mcp2_IN.begin(2);

	for (int i = 0; i < 16; i++)
	{
		mcp1_IN.pinMode(i, INPUT);
		mcp2_IN.pinMode(i, INPUT);
	}
}

void setup_out_extender(void)
{
	mcp1_OUT.begin(1);
	mcp2_OUT.begin(3);

	for (int i = 0; i < 16; i++)
	{
		mcp1_OUT.pinMode(i, OUTPUT);
		mcp2_OUT.pinMode(i, OUTPUT);
	}
}

void gostinnaya_light(void)
{
	// read input
	gostinnaya_in_tochka1 = mcp1_IN.digitalRead(GOSTINNAYA_IN1_TOCHKA);
	gostinnaya_in_svet1 = mcp1_IN.digitalRead(GOSTINNAYA_IN1_SVET);
	gostinnaya_in_led1 = mcp1_IN.digitalRead(GOSTINNAYA_IN1_LED);

	// compare state by XOR operation
	gostinnaya_out_tochka = gostinnaya_in_tochka1 ^ gostinnaya_tochka;
	gostinnaya_out_svet = gostinnaya_in_svet1 ^ gostinnaya_svet;
	gostinnaya_out_led = gostinnaya_in_led1 ^ gostinnaya_led;

	// write value
	mcp1_OUT.digitalWrite(GOSTINNAYA_OUT_TOCHKA, gostinnaya_out_tochka);
	mcp1_OUT.digitalWrite(GOSTINNAYA_OUT_SVET, gostinnaya_out_svet);
	mcp1_OUT.digitalWrite(GOSTINNAYA_OUT_LED, gostinnaya_out_led);
}

void koridor_light(void)
{
	koridor_in_bra1 = mcp1_IN.digitalRead(KORIDOR_IN1_BRA);
	koridor_in_tochka1 = mcp1_IN.digitalRead(KORIDOR_IN1_TOCHKA);
	koridor_in_tochka2 = mcp1_IN.digitalRead(KORIDOR_IN2_TOCHKA);
	koridor_in_tochka3 = mcp1_IN.digitalRead(KORIDOR_IN3_TOCHKA);
	koridor_in_led1 = mcp1_IN.digitalRead(KORIDOR_IN1_LED);

	koridor_out_bra = koridor_in_bra1 ^ koridor_bra;
	koridor_out_tochka = (((koridor_in_tochka1 ^ koridor_in_tochka2) ^ koridor_in_tochka3) ^ koridor_tochka);
	koridor_out_led = koridor_in_led1 ^ koridor_led;

	mcp1_OUT.digitalWrite(KORIDOR_OUT_BRA, koridor_out_bra);
	mcp1_OUT.digitalWrite(KORIDOR_OUT_TOCHKA, koridor_out_tochka);
	mcp1_OUT.digitalWrite(KORIDOR_OUT_LED, koridor_out_led);

}
void kuhna_light(void)
{
	kuhna_in_svet1 = mcp1_IN.digitalRead(KUHNA_IN1_SVET);
	kuhna_in_rabzone1 = mcp1_IN.digitalRead(KUHNA_IN1_RABZONA);
	kuhna_in_led_up1 = mcp1_IN.digitalRead(KUHNA_IN1_LED_UP);
	kuhna_in_led_down1 = mcp1_IN.digitalRead(KUHNA_IN1_LED_DOWN);

	kuhna_out_svet = kuhna_in_svet1 ^ kuhna_svet;
	kuhna_out_rabzone = kuhna_in_rabzone1 ^ kuhna_rabzone;
	kuhna_out_led_up = kuhna_in_led_up1 ^ kuhna_led_up;
	kuhna_out_led_down = kuhna_in_led_down1 ^ kuhna_led_down;

	mcp1_IN.digitalWrite(KUHNA_OUT_SVET, kuhna_out_svet);
	mcp1_IN.digitalWrite(KUHNA_OUT_RABZONA, kuhna_out_rabzone);
	mcp1_IN.digitalWrite(KUHNA_OUT_LED_UP, kuhna_out_led_up);
	mcp1_IN.digitalWrite(KUHNA_OUT_LED_DOWN, kuhna_out_led_down);


}

void sanuzel_light(void)
{
	sanuzel_in_tochka1 = mcp1_IN.digitalRead(SANUZEL_IN1_SVET);
	sanuzel_in_led1 = mcp1_IN.digitalRead(SANUZEL_IN1_LED);
	
	sanuzel_out_tochka = sanuzel_in_tochka1 ^ sanuzel_tochka;
	sanuzel_out_led = sanuzel_in_led1 ^ sanuzel_led;

	mcp1_IN.digitalWrite(SANUZEL_OUT_SVET, sanuzel_out_tochka);
	mcp1_IN.digitalWrite(SANUZEL_OUT_LED, sanuzel_out_led);
}

void spalna_light(void)
{
	spalna_in_tochka1 = mcp2_IN.digitalRead(SPALNA_IN1_TOCHKA);
	spalna_in_tochka2 = mcp2_IN.digitalRead(SPALNA_IN2_TOCHKA);
	spalna_in_tochka3 = mcp2_IN.digitalRead(SPALNA_IN3_TOCHKA);
	spalna_in_bra_left1 = mcp2_IN.digitalRead(SPALNA_IN1_BRA_LEFT);
	spalna_in_bra_right1 = mcp2_IN.digitalRead(SPALNA_IN1_BRA_RIGHT);

	spalna_out_tochka = (((spalna_in_tochka1 ^ spalna_in_tochka2) ^ spalna_in_tochka3) ^ spalna_tochka);
	spalna_out_bra_left = spalna_in_bra_left1 ^ spalna_bra_left;
	spalna_out_bra_right = spalna_in_bra_right1 ^ spalna_bra_right;

	mcp2_OUT.digitalWrite(SPALNA_OUT_TOCHKA, spalna_out_tochka);
	mcp2_OUT.digitalWrite(SPALNA_OUT_BRA_LEFT, spalna_out_bra_left);
	mcp2_OUT.digitalWrite(SPALNA_OUT_BRA_RIGHT, spalna_out_bra_right);
}

void kabinet_light(void)
{
	kabinet_in_tochka1 = mcp2_IN.digitalRead(KABINET_IN1_TOCHKA);

	kabinet_out_tochka = kabinet_in_tochka1^kabinet_tochka;

	mcp2_OUT.digitalWrite(KABINET_OUT_TOCHKA, kabinet_out_tochka);
}



