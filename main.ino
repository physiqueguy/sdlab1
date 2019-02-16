
#define err0 4
#define err1 5
#define err2 6
#define CLKPIN 3
#define DATAPIN 2
#define READPIN 7

#include "TemperatureProbe.h"
#include "LED_ARRAY.h"


TemperatureProbe probe(7);
Led_Array led(CLKPIN, DATAPIN, err0, err1, err2);


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   
   led.ledOn();
   
}

void loop() {
  // put your main code here, to run repeatedly:
  probe.GetTemperatureReading();
  led.setTemp(probe.GetCurrentTempByte());
  Serial.println(probe.GetCurrentTempFloat());
  delay(1000);
}
