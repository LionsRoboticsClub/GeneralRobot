/*
  MecanumDrive.cpp - Library for controlling a Mecanum Drive
  Created by Pablo, August 14, 2019.
*/

#include "Arduino.h"
#include "Motor.h"

#define PI 3.1415926535897932384626433832795028841971
#define MAX_SPEED = 255;

//Motor::Motor(){}

MecanumDrive::MecanumDrive(Motor A, Motor B, Motor C, Motor D, double magnitude, double angle, double rotationSpeed){
    this.magnitude = magnitude; 
    this.angle = angle; 
    this.rotationSpeed = rotationSpeed;
    this.A = A; 
    this.B = B;
    this.C = C; 
    this.D = D;
}


void MecanumDrive::moveTowards(double angle, double magnitude, double rotationSpeed){
    this.magnitude = magnitude; 
    this.angle = angle; 
    this.rotationSpeed = rotationSpeed; 
    A.move(MAX_SPEED * magnitude * (sin(angle * PI / 180 + PI/4) + rotationSpeed));
    B.move(MAX_SPEED * magnigude * (cos(angle * PI / 180 + PI/4) - rotationSpeed));
    C.move(MAX_SPEED * magnitude * (cos(angle * PI / 180 + PI/4) + rotationSpeed));
    D.move(MAX_SPEED * magnitude * (sin(angle * PI / 180 + PI/4) - rotationSpeed));
}

