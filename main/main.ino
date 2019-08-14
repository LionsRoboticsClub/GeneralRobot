#include "Arduino.h"
#include "Buzzer.h"
#include "Motor.h"
#include <EnableInterrupt.h>

char Incoming_value = 0;                //Variable for storing Incoming_value
Buzzer buzz(28);
void setup(){
  Serial1.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
}
void loop()
{
  if(Serial1.available() > 0)  
  {
    Incoming_value = Serial1.read();      //Read the incoming data and store it into variable Incoming_value
    Serial1.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    Serial1.print("\n");        //New line 
    if(Incoming_value == '1') buzz.beep(0);
    else if(Incoming_value == '0') buzz.beep(100);
  }                            
 
}   
