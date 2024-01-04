#include<Arduino.h>
#include<SoftwareSerial.h>

SoftwareSerial blue(8,9);

void setup(){
  Serial.begin(38400);
  blue.begin(38400);
}

void loop(){
  if(blue.available()){
    Serial.write(blue.read());
  }
  if(Serial.available()){
    blue.write(Serial.read());
  }
}
