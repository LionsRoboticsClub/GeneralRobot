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
float magnitude = 0;
float rotationSpeed = 0;
long intake = 0; 
long band = 0; 

boolean lastA = false;
boolean newA = false; 

boolean lastB = false; 
boolean newB = false;

boolean lastX = false;
boolean newX = false;

boolean lastY = false; 
boolean newY = false;

boolean A = false; 
boolean B = false; 
boolean X = false;
boolean Y = false;
boolean reset = false;

byte ButtonPressed(boolean A, boolean B, boolean Y, boolean X) {
  byte buttons = 0;
  if (A) buttons = 1;
  else if (B) buttons = 2;
  else if (Y) buttons = 3;
  else if (X) buttons = 4;
  return buttons;
}

byte GetMagnitude(float magnitude) {
  return byte(magnitude * 127F);
}

byte GetRotationSpeed(float rotationSpeed) {
  return byte(rotationSpeed * 127F);
}

byte GetAngle(float angle) {
  return byte(angle/3);
}

void setup() {
  size(400, 240);
  control = ControlIO.getInstance(this);
  gpad = control.getMatchedDevice("XboxOneController");
  if (gpad == null) {
    println("No suitable device configured");
    System.exit(-1);
  }
  String portName = Serial.list()[1];
  port = new Serial(this, portName, 9600);
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

  if (abs(yAxis) < 0.1 && abs(xAxis) < 0.1) {
    headingAngle = 0;
  } else {
    headingAngle = atan2(xAxis, yAxis) * 180 / PI;
  }

  if (headingAngle < 0) {
    headingAngle += 360;
  }

  magnitude = sqrt(xAxis * xAxis + yAxis * yAxis);

  if (magnitude > 1) {
    magnitude = 1;
  }

  if (abs(yRot) < 0.3 && abs(xRot) < 0.3) {
    rotationSpeed = 0;
  } else {
    rotationSpeed = sqrt(xRot * xRot + yRot * yRot);
    if (rotationSpeed > 1) {
      rotationSpeed = 1;
    }
  }




  println("angle: " + headingAngle);

  println("magnitud: " + magnitude);

  println("rotSpeed: " + rotationSpeed);

  println("X: " + X);
  println("Y: " + Y); 
  println("A: " + A);
  println("B: " + B);
  println("Reset: " + reset);
  char signal[] = new char[3];

  if ((headingAngle < 45 || headingAngle > 325) && magnitude > 0.15) {
    //signal[0] = 'F';
    port.write('F');
  } else if (headingAngle < 135 && headingAngle > 45  && magnitude > 0.15) {
    //signal[0] = 'R';
    port.write('R');
  } else if (headingAngle >135 && headingAngle < 225 && magnitude > 0.15) {
    //signal[0] = 'B';
    port.write('L');
  } else if(magnitude > 0.15){
    //signal[0] = 'L';
    port.write('B');
  }

  if (floor(magnitude) == 0) {
    //signal[0] = 0;
    port.write('S');
  }
  
  if(A){
    newA = true;
    if(lastA == false){
      port.write("A");
      lastA = true;
    }
  }else{
    newA = false;
    if(lastA == true){
      port.write('a');
      lastA = false;
    }
  }

  if(B){
    newB = true;
    if(lastB == false){
      port.write("B");
      lastB = true;
    }
  }else{
    newB = false;
    if(lastB == true){
      port.write('b');
      lastB = false;
    }
  }


  if(X){
    newX = true;
    if(lastX == false){
      port.write("X");
      lastX = true;
    }
  }else{
    newX = false;
    if(lastX == true){
      port.write('x');
      lastX = false;
    }
  }

  if(Y){
    newY = true;
    if(lastY == false){
      port.write("Y");
      lastY = true;
    }
  }else{
    newY = false;
    if(lastY == true){
      port.write('y');
      lastY = false;
    }
  }


  /*
  signal[1] = ((intake%2 == 0)?1:0);
  signal[2] = ((band%2 == 0)?1:0);
  */
  /*
  signal[0] = GetMagnitude(magnitude);
   signal[1] = GetRotationSpeed(rotationSpeed);
   signal[2] = GetAngle(headingAngle);
   signal[3] = ButtonPressed(A,B,Y,X); 
   */
  //port.write(signal);
  println(signal);
}
