#include<Arduino.h>

int PINWin=6, PINWout=4;
int PINGin=7, PINGout=5;

void setup() {
	Serial.begin(9600);
  // initialize analog pin PIN as an output.
  pinMode(PINWin, INPUT);
  pinMode(PINGin, INPUT);
  Serial.println("Board ready");
}

// the loop function runs over and over again forever
void loop() {
	int vw=0, vg=0;
  vw=analogRead(PINWin);
  vg=analogRead(PINGin);
  Serial.print("green: "); Serial.println(vg);
  Serial.print("white: "); Serial.println(vw);
  analogWrite(PINWout, vw);
  analogWrite(PINGout, vg);
}
