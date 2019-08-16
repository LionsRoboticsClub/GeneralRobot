    
#include "Arduino.h"
#include "Buzzer.h"
#include "Motor.h"
#include "MecanumDrive.h"

byte movement_data[4] = {0,0,0,0};
byte current_index = 0;

template <typename T>
void LogData(T data){
  Serial.println(data);
}


Motor motor1(2,3,0,0);
Motor motor2(9,8,0,0);
Motor motor3(4,5,0,0);
Motor motor4(6,7,0,0);
MecanumDrive mecanum(motor1, motor2, motor3, motor4, 0,0,0);
Servo band; 
Servo intake; 

bool a = false, b = false, x = false, y = false; 

void setup(){
  band.attach(29);
  intake.attach(30);
  Serial.begin(9600);
  Serial1.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
}
void loop()
{

if(Serial1.available()){
  movement_data[current_index] = Serial1.read();
  LogData(movement_data[current_index]);
  current_index == 4 ? current_index = 0 : ++current_index;

  if(current_index == 3) {
    // Do robot things.
    //movement_data[0] magnitude
//    movement data 1 rotation
//    movement data 2 angle 
//    movement data 3 buttons a b y x
    movement_data[0] /= 128;
    movement_data[1] /= 128;
    movement_data[2] *= 3;
    
    mecanum.moveTowards(movement_data[2],movement_data[0],0);
    if(movement_data[3] == 1){
      intake.writeMicroseconds(1000);
    }else if(movement_data[3] == 2){
      intake.writeMicroseconds(2000);
    }else if(movement_data[3] == 3){
      band.writeMicroseconds(1000);
    }else if(movement_data[3] == 4){
      band.writeMicroseconds(2000);
    }else{
      band.writeMicroseconds(1500);
      intake.writeMicroseconds(1500);
    }
  }
}
 
}   
