#include "TemperatureProbe.h"

// Contructor initializes the OneWire and DallasTemperature objects 
// and 
TemperatureProbe::TemperatureProbe(int dataPin)
: p_dataWire(OneWire(dataPin)), 
  p_sensors(DallasTemperature(&p_dataWire)), p_currentTempFloat(0.0){
  pinMode(dataPin, INPUT); 
}


void TemperatureProbe::GetTemperatureReading(){
  p_sensors.requestTemperatures();
  p_currentTempFloat = p_sensors.getTempCByIndex(0);
  p_currentTempByte = round(p_currentTempFloat);
  this->UpdateTempHistory();
}

float TemperatureProbe::GetCurrentTempFloat(){return p_currentTempFloat;};

void TemperatureProbe::UpdateTempHistory(){
  for(int i = 299; i > 0; i--){
    p_TempHistory[i] = p_TempHistory[i-1];
  }
  p_TempHistory[0] = p_currentTempFloat;
}
