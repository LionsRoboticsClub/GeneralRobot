    
/*
  Buzzer.h - Library for controlling a buzzer
  Created by Jose M. Carrillo, February 15, 2019.
*/

#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer{
  public:
    Buzzer(int);
    void beep(int);
    
  private:
    byte _pin = 28;
};

#endif
