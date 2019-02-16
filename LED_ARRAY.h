/*This header file is used in conjunction with LED_ARRAY.cpp
  to control the LED array with a serial shift register on 7 
  of the LEDs and 3 seperate pins for the LEDs that represent
  the error codes on the ESP32*/

#ifndef Led_Array_h     //used so that when Led_Array.h is included in
#define Led_Array_h     //other sketches, it wont create multiple copies

#include "Arduino.h"    //allows access to the main arduino functions

class Led_Array{        //declare class
  public:               //declare public functions and variables

    //Contructor for Object
	Led_Array(uint8_t clkPin, uint8_t dataPin, uint8_t err0Pin, uint8_t err1Pin, uint8_t err2Pin);
    
    //Public functions
	void errWrite(uint8_t num); //convert integer to binary and output to LED array
    void setTemp(int8_t temp);    //sets the stored temp in memory that waits to be displayed until the array is on
    void setErr(uint8_t error);   //setst the stored error in memeory that waits to be displayed until the array is turned on
    void ledOn();     //turns the LED array on
    void ledOff();     //turns the LED array off   
    
  private:              //declare private functions and variables
    uint8_t _clkPin;     //pin number of the clock
    uint8_t _dataPin;    //pin number of the data
    uint8_t _errPins[3]; //pin numbers of the errors with 0 being the MSB
    int8_t _temp;        //number stored for the current temp shown on the LED display
    int8_t _err;         //number stored for the current error shown on the LED display
    bool _pwr;           //keeps track if the display is on or off
    
};

#endif                  //end definition of class
