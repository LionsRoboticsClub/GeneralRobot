    
#include "Arduino.h"
#include "Buzzer.h"
#include "Motor.h"

// Variable used to store data read from Serial1.
int unproccesed_data;

template <typename T>
void LogData(T data){
  Serial.println(data);
}

int InputData(){
  int data = 0;
  Serial.println("This was called");
  data = Serial1.read();
  LogData(data);

  return data;
}

Buzzer buzz(28);
void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
}
void loop()
{

if(Serial1.available()){
unproccesed_data = InputData(); 
  if(unproccesed_data == 123) buzz.beep(100);
  else buzz.beep(0);
}                   
 
}   
