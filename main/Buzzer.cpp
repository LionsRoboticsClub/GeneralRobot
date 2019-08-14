/*
  Buzzer.cpp - Library for controlling a buzzer
  Created by Jose M. Carrillo, February 15, 2019.
*/

#include "Arduino.h"
#include "Buzzer.h"

Buzzer::Buzzer(){
  pinMode(_pin, OUTPUT);
}

void Buzzer::beep(){
  digitalWrite(_pin, HIGH);
  delay(50);
  digitalWrite(_pin, LOW);
  delay(50);
}