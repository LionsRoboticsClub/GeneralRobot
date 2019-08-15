/*
  Motor.h - Library for controlling motors
  Created by Jose M. Carrillo, February 14, 2019.
*/

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor{
  public:
    //Constructor format: FPin, BPin, EncA, EncB
    Motor(byte pinFwd, byte pinBwd, byte encA, byte encB);

    /* MOTOR FUNCTIONS */
    void forward(int velocity);
    void backward(int velocity);
    void move(int velocity);
    void completeStop();
    void updateEncPos();
    void resetEncPos();
    int getEncoderA();
    int getEncPos();

  private:
    int _pinFwd, _pinBwd, _encA, _encB, _encPos;

};

#endif