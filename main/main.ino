    
#include "Arduino.h"
#include "Buzzer.h"
#include "Motor.h"
#include "MecanumDrive.h"

byte movement_data[6] = {0,0,0,0,0,0};
byte current_index = 0;

template <typename T>
void LogData(T data){
  Serial.println(data);
}

Motor motor1(2,3,0,0);
Motor motor2(9,8,0,0);
Motor motor3(4,5,0,0);


void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
}
void loop()
{

if(Serial1.available()){
  movement_data[current_index] = Serial1.read();
  LogData(movement_data[current_index]);
  current_index == 6 ? current_index = 0 : ++current_index;

  if(current_index == 5) {
    // Do robot things.
  }
}
 
}   
