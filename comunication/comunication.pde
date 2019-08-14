import processing.serial.*;
Serial port;

void setup() {
  String portName = Serial.list()[0];
  port = new Serial(this, portName, 9600);
}

void draw() {      
  int value1 = 123;
   
  byte out[] = new byte[1];
  out[0] = byte(value1);

  port.write(out);
}
