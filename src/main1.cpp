#include<Arduino.h>
#include<SoftwareSerial.h>

//#define SETUP
#define FINAL
//#define KEYBOARD
#define MASTER
//#define SLAVE

#ifdef MASTER
#warning MASTER defined
#elif defined(SLAVE)
#warning SLAVE defined
#endif

SoftwareSerial blue(8,9);

enum STATUS {BLUET, CABLE};

int PINLEDCI=2;
int PINLEDCO=3;

int PINWin=6, PINWinState=LOW;
int PINGin=7, PINGinState=LOW;
int PINWout=4, PINWoutState=LOW;
int PINGout=5, PINGoutState=LOW;

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

#ifdef FINAL
void setup() {
	Serial.begin(9600);
  pinMode(PINLEDCI, INPUT);
  pinMode(PINLEDCO, OUTPUT);

  pinMode(PINWin, INPUT);
  pinMode(PINGin, INPUT);
  
  blue.begin(9600);

  Serial.println("Board ready");
}

void loop() {
  digitalWrite(PINWout, digitalRead(PINWin));
  digitalWrite(PINGout, digitalRead(PINGin));
//#ifdef MASTER
//  if (digitalRead(PINWIn)==HIGH){
//    stat=HIGH;
//    Serial.println("Pressed");
//    blue.write('1');
//  }
//  if (digitalRead(PINLEDCI)==LOW && stat==HIGH){
//    Serial.println("Released");
//    stat=LOW;
//    blue.write('0');
//  }
//#elif defined(SLAVE)
//  if (blue.available()){
//    Serial.println("Receiving");
//    char slaveStat=blue.read();
//    Serial.write(slaveStat);
//    switch(slaveStat){
//      case '1':{
//        digitalWrite(PINLEDCO, HIGH);
//        break;
//      }
//      case '0':{
//        digitalWrite(PINLEDCO, LOW);
//        break;
//      }
//    }
//  }
//#endif
}

#else 

#ifdef SETUP
void setup(){
  //slave: 98D3,31,F5C54A
  //master: 98D3,31,F995CA
  Serial.begin(9600);
  blue.begin(9600);
  Serial.println("Status: ");
  blue.write("AT\r\n");
  //delay(100);
  //Serial.println("Address: ");
  //blue.write("AT+ADDR?\r\n");
  //delay(100);
  //Serial.println("Setting name to \"enricoKeyboard\": ");
  //blue.write("AT+NAME=enricoKeyboard\r\n");
  //delay(100);
  //Serial.println("Setting device to master: ");
  //blue.write("AT+ROLE=0\r\n");
  //blue.write("AT+\r\n");
  //blue.write("AT+\r\n");
}


void loop(){
  if(blue.available()){
    Serial.write(blue.read());
  }
  if(Serial.available()){
    blue.write(Serial.read());
  }

}
#else

#ifdef KEYBOARD
#include<Keyboard.h>

int buttonPIN=10;
int counter=0;
int state=LOW;

void setup(){
  pinMode(buttonPIN, INPUT);
  Keyboard.begin();
  state=digitalRead(buttonPIN);
}

void loop(){
  if(digitalRead(buttonPIN)==HIGH){
    Keyboard.print("ò");
    state=digitalRead(buttonPIN);
    delay(200);
  }
}

#endif //KEYBOARD
#endif //SETUP
#endif
