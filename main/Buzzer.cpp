/*
  Buzzer.cpp - Library for controlling a buzzer
  Created by Jose M. Carrillo, February 15, 2019.
*/

#include "Arduino.h"
#include "Buzzer.h"

Buzzer::Buzzer(int _pin){
  pinMode(_pin, OUTPUT);
}

void Buzzer::beep(int pitch){
  digitalWrite(_pin, pitch);
  delay(50);
}
