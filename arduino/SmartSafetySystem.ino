/*
 Smart Safety with Fire and Gas Leak Detection
 Cleaned example based on original project.
*/

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// LCD Pins
LiquidCrystal lcd(12,11,5,4,3,2);

// GSM
SoftwareSerial gsm(8,9); // RX, TX

// Pins
const int LM35_PIN = A0;
const int MQ2_PIN  = A1;
const int BUZZER   = 10;

// Thresholds
const int GAS_THRESHOLD = 400;
const float FIRE_THRESHOLD = 45.0;

// Replace with your phone number
const char PHONE[] = "+91XXXXXXXXXX";

bool gasAlertSent=false;
bool fireAlertSent=false;

void sendSMS(String msg){
  gsm.println("AT+CMGF=1");
  delay(500);
  gsm.print("AT+CMGS=\"");
  gsm.print(PHONE);
  gsm.println("\"");
  delay(500);
  gsm.print(msg);
  delay(500);
  gsm.write(26);
  delay(3000);
}

float readTemperature(){
  int raw=analogRead(LM35_PIN);
  float voltage=raw*(5.0/1023.0);
  return voltage*100.0;
}

void setup(){
  Serial.begin(9600);
  gsm.begin(9600);

  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Smart Safety");
  lcd.setCursor(0,1);
  lcd.print("Initializing");
  pinMode(BUZZER,OUTPUT);
  digitalWrite(BUZZER,LOW);
  delay(2000);
}

void loop(){

  float temp=readTemperature();
  int gas=analogRead(MQ2_PIN);

  bool gasLeak = gas > GAS_THRESHOLD;
  bool fire = temp > FIRE_THRESHOLD;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temp,1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("G:");
  lcd.print(gas);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C   Gas: ");
  Serial.println(gas);

  if(gasLeak){
    digitalWrite(BUZZER,HIGH);
    lcd.clear();
    lcd.print("GAS LEAK!");
    lcd.setCursor(0,1);
    lcd.print("Check Area");

    if(!gasAlertSent){
      sendSMS("ALERT!\nGas leakage detected.\nTake immediate action.");
      gasAlertSent=true;
    }
  }
  else if(fire){
    digitalWrite(BUZZER,HIGH);
    lcd.clear();
    lcd.print("FIRE ALERT!");
    lcd.setCursor(0,1);
    lcd.print(temp,1);
    lcd.print(" C");

    if(!fireAlertSent){
      sendSMS("ALERT!\nHigh temperature / Fire detected.");
      fireAlertSent=true;
    }
  }
  else{
    digitalWrite(BUZZER,LOW);
    gasAlertSent=false;
    fireAlertSent=false;
  }

  delay(1000);
}
