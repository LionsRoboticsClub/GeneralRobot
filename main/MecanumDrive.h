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
    MecanumDrive(Motor A, Motor B, Motor C, Motor D, double angle, double magnitude, double rotationSpeed);

    /* MOTOR FUNCTIONS */
    void moveTowards(double angle, double magnitude, double rotationSpeed);

  private:
    double angle, magnitude, rotationSpeed;
    Motor A,B,C,D;
};

#endif