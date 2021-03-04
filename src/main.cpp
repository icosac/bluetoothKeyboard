#include<Arduino.h>

enum STATUS {BLUET, CABLE};

int PINLEDCI=8;
int PINLEDCO=9;

int PINW=6;
int PING=7;

int deviceStatus=STATUS::BLUET;

void changeStatus(){
  switch(deviceStatus){
    case STATUS::BLUET:{
      deviceStatus=STATUS::CABLE;
      digitalWrite(PINLEDCO, HIGH);
      break;
    }
    case STATUS::CABLE:{
      deviceStatus=STATUS::BLUET;
      digitalWrite(PINLEDCO, LOW);
    }
  }

  delay(1000);
}

void setup() {
	Serial.begin(9600);
  // initialize digital pin PIN as an output.
  pinMode(PINW, INPUT);
  pinMode(PING, INPUT);
  pinMode(PINLEDCI, INPUT);
  pinMode(PINLEDCO, OUTPUT);

  Serial.println("Board ready");
}

// the loop function runs over and over again forever
void loop() {
	int vw=0, vg=0;
  vw=digitalRead(PINW);
  vg=digitalRead(PING);
  Serial.print("green: "); Serial.println(vg);
  Serial.print("white: "); Serial.println(vw);

  if (digitalRead(PINLEDCI)==HIGH){
    changeStatus();
  }
}
