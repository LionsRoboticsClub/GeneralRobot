#include "Arduino.h"
#include "Buzzer.h"
#include "Motor.h"

// Variable used to store data read from Serial1.
int unproccesed_data;

template <typename T>
void LogData(T data){
  Serial1.println(data);
}

int InputData(){
  int data = 0;
  Serial1.println("This was called");
  if(Serial1.available() > 0) {
    data = Serial1.read();
    LogData(data);
  }
  return data;
}

Buzzer buzz(28);
void setup(){
  Serial1.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
}
void loop()
{
unproccesed_data = InputData();                    
 
}   
