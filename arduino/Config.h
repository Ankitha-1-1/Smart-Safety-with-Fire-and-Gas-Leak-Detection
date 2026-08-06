#ifndef CONFIG_H
#define CONFIG_H

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// LCD
#define LCD_RS 12
#define LCD_EN 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2

// Sensors
#define LM35_PIN A0
#define MQ2_PIN  A1

// Output
#define BUZZER_PIN 10

// GSM
#define GSM_RX 8
#define GSM_TX 9

const int GAS_THRESHOLD = 400;
const float FIRE_THRESHOLD = 45.0;

const char PHONE[] = "+91XXXXXXXXXX";

#endif
