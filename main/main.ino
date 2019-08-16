
#include "Arduino.h"
#include "Buzzer.h"
#include "Motor.h"
#include "MecanumDrive.h"
#include <Servo.h>
int movement_data[3] = {0,0,0};
float actualData[4] = {0, 0, 0, 0};
byte current_index = 0;
int countZeros = 0; 
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
char lectura; 
bool a = false, b = false, x = false, y = false;

void setup() {
  band.attach(29);
  intake.attach(30);
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  if (Serial1.available()) {
    //movement_data[current_index] = Serial1.read();
    //current_index == 4 ? current_index = 0 : ++current_index;
    lectura = Serial1.read();
    Serial.println(lectura);
  }
  if (lectura== 'F') {
    //mecanum.moveTowards(2,1,0);
      //Serial.println("estado 1");
    motor1.forward(155);
    motor2.forward(155);
    motor3.forward(155);
    motor4.forward(155);
        countZeros = 0;
   
  } else if (lectura== 'R') {
    //mecanum.moveTowards(270,1,0);
          //Serial.println("estado 2");
    motor1.backward(155);
    motor2.forward(155);
    motor3.forward(155);
    motor4.backward(155);

    countZeros = 0;
  } else if (lectura== 'L') {
    //mecanum.moveTowards(180,1,0);
          //Serial.println("estado 3");
        motor1.backward(155);
    motor2.backward(155);
    motor3.backward(155);
    
    motor4.backward(155);
        countZeros = 0;
    

  } else if (lectura== 'S') {
    countZeros++;
    //mecanum.moveTowards(0, 0, 0);
    //Serial.println("estado 0");
    motor1.forward(0);
    motor2.backward(0);
    motor3.backward(0);
    motor4.forward(0);
   

  } else if(lectura == 'B'){
    //mecanum.moveTowards(90,1,0);ç
     //Serial.println("estado 4");
        motor1.forward(155);
    motor2.backward(155);
    motor3.backward(155);
    motor4.forward(155);
  }

  if(lectura == 'A') band.writeMicroseconds(1000);
  if(lectura == 'B') intake.writeMicroseconds(2000);

  intake.writeMicroseconds(1500);
  band.writeMicroseconds(1500);


  //mecanum.moveTowards(actualData[2],actualData[0],0);
  //intake.writeMicroseconds(1500);
  //band.writeMicroseconds(1500);
}
