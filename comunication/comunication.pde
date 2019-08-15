import processing.serial.*;

import org.gamecontrolplus.gui.*;
import org.gamecontrolplus.*;
import net.java.games.input.*;

ControlIO control;
Configuration config;
ControlDevice gpad;

Serial port;
//signed byte (only taking 8 bits space (decimal range between -128 and 128))
float xAxis = 0; 
float yAxis = 0; 
float xRot = 0; 
float yRot = 0; 
float headingAngle = 0;
float magnitud = 0;
float rotationSpeed = 0;

boolean A = false; 
boolean B = false; 
boolean X = false;
boolean Y = false;
boolean reset = false;



byte motor1 = -1; 
byte motor2 = 0;
byte motor3 = 0; 
byte motor4 = 0; 

byte intake = -128; 
byte band = 0;

byte ButtonPressed(boolean A, boolean B, boolean Y, boolean X){
  byte buttons = 0;
  if(A) buttons = 1;
  else if(B) buttons = 2;
  else if(Y) buttons = 3;
  else if(X) buttons = 4;
  return buttons;
}

byte MagnitudeAndRotation(float magnitude, float rotationSpeed) {
  byte magnitudeRotation = 0;
  if(magnitude==1)
  magnitudeRotation |= 1;
  if(rotationSpeed==1)
  magnitudeRotation |=2;
  
  return magnitudeRotation;
}

void setup() {
  size(400,240);
  control = ControlIO.getInstance(this);
  gpad = control.getMatchedDevice("XboxOneController");
  if(gpad == null){
    println("No suitable device configured");
    System.exit(-1);
  }
  //String portName = Serial.list()[1];
  //port = new Serial(this, portName, 9600);
}

void draw() {    
  //Xbox Controller readings
  
  xAxis = gpad.getSlider("X").getValue();
  yAxis = -1 * gpad.getSlider("Y").getValue();
  xRot = gpad.getSlider("X_Rot").getValue();
  yRot = gpad.getSlider("Y_Rot").getValue();
  A = gpad.getButton("AButton").pressed();
  B = gpad.getButton("BButton").pressed();
  X = gpad.getButton("XButton").pressed();
  Y = gpad.getButton("YButton").pressed();
  reset = gpad.getButton("Reset").pressed(); 
  
  println("X = " + xAxis + " , Y = " + yAxis);
  
  if(abs(yAxis) < 0.1 && abs(xAxis) < 0.1){
    headingAngle = 0;
  }else{
    headingAngle = atan2(xAxis, yAxis) * 180 / PI;
  }
  
  if(headingAngle < 0){
    headingAngle += 360;
  }
  
  magnitud = sqrt(xAxis * xAxis + yAxis * yAxis);
  
  if(magnitud > 1){
    magnitud = 1;
  }
 
  if(abs(yRot) < 0.3 && abs(xRot) < 0.3){
    rotationSpeed = 0;
  }else{
    rotationSpeed = sqrt(xRot * xRot + yRot * yRot);
    if(rotationSpeed > 1){
      rotationSpeed = 1;
    }
  }



  
  println("angle: " + headingAngle);
  
  println("magnitud: " + magnitud);
  
  println("rotSpeed: " + rotationSpeed);
  
  println("X: " + X);
  println("Y: " + Y); 
  println("A: " + A);
  println("B: " + B);
  println("Reset: " + reset);
  
   //0 velocidad motor 1
   //1 velocidad motor 2
   //2 velocidad motor 3
   //3 velocidad motor 4
   //4 intake data
   //5 band data
   
   
  byte signal[] = new byte[6];
  signal[0] =
  signal[1] = motor2; 
  signal[2] = motor3; 
  signal[3] = motor4; 
  signal[4] = MagnitudeAndRotation(magnitud, rotationSpeed);
  signal[5] = ButtonPressed(A,B,Y,X); 
  
  //port.write(signal);
}
