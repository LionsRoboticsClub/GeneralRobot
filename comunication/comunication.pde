import processing.serial.*;
Serial port;
//signed byte (only taking 8 bits space (decimal range between -128 and 128))
byte motor1 = -1; 
byte motor2 = 0;
byte motor3 = 0; 
byte motor4 = 0; 

byte intake = -128; 
byte band = 0;

void setup() {
  String portName = Serial.list()[1];
  port = new Serial(this, portName, 9600);
}

void draw() {      
   //0 velocidad motor 1
   //1 velocidad motor 2
   //2 velocidad motor 3
   //3 velocidad motor 4
   //4 intake data
   //5 band data
  byte signal[] = new byte[6];
  signal[0] = motor1;
  signal[1] = motor2; 
  signal[2] = motor3; 
  signal[3] = motor4; 
  signal[4] = intake; 
  signal[5] = band; 
  
  port.write(signal);
}
