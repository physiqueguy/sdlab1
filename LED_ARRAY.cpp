/*This cpp file is used in conjunction with LED_ARRAY.h
  to control the LED array with a serial shift register on 7 
  of the LEDs and 3 seperate pins for the LEDs that represent
  the error codes on the ESP32*/

#include "Arduino.h"
#include "LED_ARRAY.h"

Led_Array::Led_Array(uint8_t clkPin, uint8_t dataPin, uint8_t err0Pin, uint8_t err1Pin, uint8_t err2Pin){
  
  //set the pins of the LED array
  pinMode(clkPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(err0Pin, OUTPUT);
  pinMode(err1Pin, OUTPUT);
  pinMode(err2Pin, OUTPUT);

  //setting values of private pin number variables
  _clkPin = clkPin;
  _dataPin = dataPin;
  
  _errPins[0] = err0Pin;
  _errPins[1] = err1Pin;
  _errPins[2] = err2Pin;

  //setting the starting values of the on state, current temp, and the current error to 0
  _temp = 0;
  _err = B00000000;
  _pwr = 0;

}

void Led_Array::setTemp(int8_t temp){
    _temp = temp;
  if(_pwr == 1){
    shiftOut(_dataPin, _clkPin, LSBFIRST, _temp);
  }else{
    shiftOut(_dataPin, _clkPin, LSBFIRST, 0);
  }
  
}

void Led_Array::setErr(uint8_t error){
  _err = error;
  if(_pwr == 1){
    this->errWrite(_err);
  }else{
    this->errWrite(0);
  }
  
}

void Led_Array::ledOn(){
  shiftOut(_dataPin, _clkPin, LSBFIRST, _temp);
  this->errWrite(_err);
  _pwr = 1;
  
}

void Led_Array::ledOff(){
  shiftOut(_dataPin, _clkPin, LSBFIRST, 0);
  this->errWrite(0);
  _pwr = 0;
  
}

void Led_Array::errWrite(byte num){
  //assuming that the integer is already between 0 and 8
  byte mask = B10000000;
  for (int i = 5; i < 8; i++){
    if ( ((mask >> i) & num) == (mask >> i) ){
      digitalWrite(_errPins[i-5], HIGH);
    }else{
      digitalWrite(_errPins[i-5], LOW);
    }
  }
}
