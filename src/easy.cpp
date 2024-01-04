#include<Arduino.h>

int PINWin=6, PINWinState=LOW;
int PINGin=7, PINGinState=LOW;
int PINWout=4, PINWoutState=LOW;
int PINGout=5, PINGoutState=LOW;

void setup(){
  Serial.begin(9600);
  pinMode(PINWin, INPUT);
  pinMode(PINGin, INPUT);
  pinMode(PINWout, OUTPUT);
  pinMode(PINGout, OUTPUT);
  Serial.println("Board ready");
}

void loop(){
  digitalWrite(PINWout, digitalRead(PINWin));
  digitalWrite(PINGout, digitalRead(PINGin));
}
