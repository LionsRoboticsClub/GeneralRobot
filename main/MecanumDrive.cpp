/*
  MecanumDrive.cpp - Library for controlling a Mecanum Drive
  Created by Pablo, August 14, 2019.
*/

#include "Arduino.h"
#include "Motor.h"

//Motor::Motor(){}

MecanumDrive::MecanumDrive(Motor A, Motor B, Motor C, Motor D, double magnitude, double angle, double rotationSpeed){
    this.magnitude = magnitude; 
    this.angle = angle; 
    this.rotationSpeed = rotationSpeed;
}


void MecanumDrive::moveTowards(double angle, double magnitude, double rotationSpeed){
    this.magnitude = magnitude; 
    this.angle = angle; 
    this.rotationSpeed = rotationSpeed; 
    
}

