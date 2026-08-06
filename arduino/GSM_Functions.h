#ifndef GSM_FUNCTIONS_H
#define GSM_FUNCTIONS_H

#include <SoftwareSerial.h>

extern SoftwareSerial mySerial;


const String PHONE_NUMBER = "+919591073131";

void updateSerial()
{
  delay(500);

  while (mySerial.available())
  {
    Serial.write(mySerial.read());
  }
}

void sendSMS(String message)
{
  mySerial.println("AT+CMGF=1");      // Set SMS mode
  updateSerial();

  mySerial.print("AT+CMGS=\"");
  mySerial.print(PHONE_NUMBER);
  mySerial.println("\"");
  updateSerial();

  mySerial.print(message);

  delay(500);

  mySerial.write(26);   // Ctrl+Z to send SMS
  updateSerial();
}

#endif
