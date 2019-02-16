#include <OneWire.h> 
#include <DallasTemperature.h>
#include "Arduino.h" 

#ifndef TemperatureProbe_h     
#define TemperatureProbe_h 

#include "TemperatureProbe.h"


class TemperatureProbe{
  public:    
    // Constructor, takes temperature data pin (input):
    TemperatureProbe(int dataPin);
    void GetTemperatureReading();
    
    void UpdateTempHistory();
    // Makes the data pin start reading temperatures: 
    void InitSensors(){p_sensors.begin();};
    
    int8_t GetCurrentTempByte(){return p_currentTempByte;};
    float GetCurrentTempFloat();
    
  private:
      float p_TempHistory[300];
      int8_t p_currentTempByte;
      float p_currentTempFloat;
      OneWire p_dataWire;
      DallasTemperature p_sensors;
  
};
#endif   
