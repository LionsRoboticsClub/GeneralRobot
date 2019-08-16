
#include "Arduino.h"
#include "Buzzer.h"
#include "Motor.h"
#include "MecanumDrive.h"
#include <Servo.h>
int movement_data[1] = {0};
float actualData[4] = {0, 0, 0, 0};
byte current_index = 0;

template <typename T>
void LogData(T data) {
  Serial.println(data);
}


Motor motor1(7, 6, 0, 0);
Motor motor2(4, 5, 0, 0);
Motor motor3(9, 8, 0, 0);
Motor motor4(3, 2, 0, 0);
MecanumDrive mecanum(motor1, motor2, motor3, motor4, 0, 0, 0);
Servo band;
Servo intake;
Buzzer buzz(28);

bool a = false, b = false, x = false, y = false;

void setup() {
  //band.attach(29);
  //intake.attach(30);
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  if (Serial1.available()) {
    movement_data[current_index] = Serial1.read();
    current_index == 4 ? current_index = 0 : ++current_index;
  }
  if (movement_data[0] == 1) {
    //mecanum.moveTowards(2,1,0);
    motor1.forward(155);
    motor2.forward(155);
    motor3.forward(155);
    motor4.forward(155);
   
  } else if (movement_data[0] == 2) {
    //mecanum.moveTowards(270,1,0);
    motor1.backward(155);
    motor2.forward(155);
    motor3.forward(155);
    motor4.backward(155);

  } else if (movement_data[0] == 3) {
    //mecanum.moveTowards(180,1,0);
        motor1.backward(155);
    motor2.backward(155);
    motor3.backward(155);
    motor4.backward(155);
    

  } else if (movement_data[0] == 0) {
    mecanum.moveTowards(0, 0, 0);
  } else {
    //mecanum.moveTowards(90,1,0);ç
        motor1.forward(155);
    motor2.backward(155);
    motor3.backward(155);
    motor4.forward(155);

  }
  Serial.println(movement_data[0]);

  //mecanum.moveTowards(actualData[2],actualData[0],0);
  //intake.writeMicroseconds(1500);
  //band.writeMicroseconds(1500);
}