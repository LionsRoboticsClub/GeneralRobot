/*
  MecanumDrive.h - Library for controlling a Mecanum Drive
  Created by Pablo C Ruiz, August 14, 2019.
*/

#ifndef MecanumDrive_h
#define MecanumDrive_h

#include "Arduino.h"
#include "Motor.h"

class MecanumDrive{
  public:
    MecanumDrive(Motor, Motor, Motor, Motor, double, double, double);

    void moveTowards(double, double, double);

  private:
    double angle, magnitude, rotationSpeed;
    Motor A,B,C,D;
};

#endif