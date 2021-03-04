#include<Arduino.h>

enum STATUS {BLUET, CABLE};

int PINLEDCI=8;
int PINLEDCO=9;

int PINWin=6, PINWout=4;
int PINGin=7, PINGout=5;

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
  pinMode(PINLEDCI, INPUT);
  pinMode(PINLEDCO, OUTPUT);

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

  if (digitalRead(PINLEDCI)==HIGH){
    changeStatus();
  }
  analogWrite(PINWout, vw);
  analogWrite(PINGout, vg);
}
