#include<Arduino.h>

int PINW=6;
int PING=7;

void setup() {
	Serial.begin(9600);
  // initialize digital pin PIN as an output.
  pinMode(PINW, INPUT);
  pinMode(PING, INPUT);
  Serial.println("Board ready");
}

// the loop function runs over and over again forever
void loop() {
	int vw=0, vg=0;
  vw=digitalRead(PINW);
  vg=digitalRead(PING);
  Serial.print("green: "); Serial.println(vg);
  Serial.print("white: "); Serial.println(vw);
}
