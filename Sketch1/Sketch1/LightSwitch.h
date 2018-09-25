// LightSwitch.h

#ifndef _LIGHTSWITCH_h
#define _LIGHTSWITCH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define GOSTINNAYA_IN1_TOCHKA 0
#define GOSTINNAYA_IN1_SVET 1
#define GOSTINNAYA_IN1_LED 2
#define GOSTINNAYA_OUT_TOCHKA 0
#define GOSTINNAYA_OUT_SVET 1
#define GOSTINNAYA_OUT_LED 2

#define KORIDOR_IN1_BRA 3
#define KORIDOR_IN1_TOCHKA 4
#define KORIDOR_IN2_TOCHKA 5
#define KORIDOR_IN3_TOCHKA 6
#define KORIDOR_IN1_LED 7
#define KORIDOR_OUT_BRA 3
#define KORIDOR_OUT_TOCHKA 4
#define KORIDOR_OUT_LED 5

#define KUHNA_IN1_RABZONA 8
#define KUHNA_IN1_SVET 9
#define KUHNA_IN1_LED_UP 10
#define KUHNA_IN1_LED_DOWN 11
#define KUHNA_OUT_RABZONA 6
#define KUHNA_OUT_SVET 7
#define KUHNA_OUT_LED_UP 8
#define KUHNA_OUT_LED_DOWN 9

#define SANUZEL_IN1_SVET 12
#define SANUZEL_IN1_LED 13
#define SANUZEL_OUT_SVET 10
#define SANUZEL_OUT_LED 11

#define SPALNA_IN1_TOCHKA 0
#define SPALNA_IN2_TOCHKA 1
#define SPALNA_IN3_TOCHKA 2
#define SPALNA_IN1_BRA_LEFT 3
#define SPALNA_IN1_BRA_RIGHT 4
#define SPALNA_OUT_TOCHKA 0
#define SPALNA_OUT_BRA_LEFT 1
#define SPALNA_OUT_BRA_RIGHT 2

#define KABINET_IN1_TOCHKA 5
#define KABINET_OUT_TOCHKA 3

void setup_in_extender(void);
void setup_out_extender(void);
void gostinnaya_light(void);
void koridor_light(void);
void kuhna_light(void);
void sanuzel_light(void);
void spalna_light(void);
void kabinet_light(void);

#endif

