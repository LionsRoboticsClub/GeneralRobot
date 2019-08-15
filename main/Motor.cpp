/*
  Motor.cpp - Library for controlling motors
  Created by Jose M. Carrillo, February 14, 2019.
*/

#include "Arduino.h"
#include "Motor.h"

Motor::Motor(){}

Motor::Motor(byte pinFwd, byte pinBwd, byte encA, byte encB){
  _pinFwd = pinFwd;
  _pinBwd = pinBwd;
  
  _encA = encA;
  _encB = encB;

  pinMode(_pinFwd, OUTPUT);
  pinMode(_pinBwd, OUTPUT);

  pinMode(_encA, INPUT);
  pinMode(_encB, INPUT);
  digitalWrite(_encA, HIGH);
  digitalWrite(_encB, HIGH);
}

void Motor::move(int velocity){
  if(velocity>0){
    analogWrite(_pinFwd, velocity);
    analogWrite(_pinBwd, 0);
  }else if(velocity<0){
    analogWrite(_pinFwd, 0);
    analogWrite(_pinBwd, velocity);
  }else{
    analogWrite(_pinFwd, 0);
    analogWrite(_pinBwd, 0);
  }
}

void Motor::forward(int velocity){
  analogWrite(_pinFwd, velocity);
  analogWrite(_pinBwd, 0);
}

void Motor::backward(int velocity){
  analogWrite(_pinFwd, 0);
  analogWrite(_pinBwd, velocity);
}

void Motor::completeStop(){
  analogWrite(_pinFwd, 0);
  analogWrite(_pinBwd, 0);
}

void Motor::updateEncPos(){
  if(digitalRead(_encA)){
    _encPos++;
  }
}

void Motor::resetEncPos(){
  _encPos = 0;
}

int Motor::getEncoderA(){
  return _encA;
}

int Motor::getEncPos(){
  return _encPos;
}