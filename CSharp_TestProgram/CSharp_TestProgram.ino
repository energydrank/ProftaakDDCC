#include <SPI.h>
#include <Controllino.h>

int SwitchCantiLeverB = A11;
int cantiLeverB = 9;
int cantiLeverF = 8;
int switchHorConv = A0;
int horizontalConv = 5;
int armVertUp = 7;
int switchVert = A3;
bool test = false;
int IncomingByte = 0;
int horizontalRack = 4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(horizontalRack, OUTPUT);
  pinMode(SwitchCantiLeverB, INPUT);
  pinMode(switchHorConv, INPUT);
  pinMode(cantiLeverB, OUTPUT);
  pinMode(cantiLeverF, INPUT);
  pinMode(horizontalConv, OUTPUT);
  pinMode(armVertUp, OUTPUT);
  pinMode(switchVert, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(Serial.read() + (String)"abhd");
  IncomingByte = Serial.read();

//  if (IncomingByte == 4)
//  {
//    if (test == false)
//    {
//      digitalWrite(cantiLeverB, HIGH);
//      if (digitalRead(SwitchCantiLeverB) == 1)
//      {
//        digitalWrite(cantiLeverB, LOW);
//      }
//      if (digitalRead(switchHorConv) == LOW)
//      {
//        digitalWrite(horizontalConv, HIGH);
//      }
//      if (digitalRead(switchHorConv) == HIGH)
//      {
//        digitalWrite(horizontalConv, LOW);
//        if (digitalRead(switchVert) == HIGH) {
//          test = true;
//        }
//      }
//      digitalWrite(armVertUp, HIGH);
//      if (digitalRead(switchVert) == HIGH)
//      {
//        digitalWrite(armVertUp, LOW);
//        if (digitalRead(horizontalConv) == LOW)
//        {
//          test = true;
//        }
//      }
//    }
//  }




  if (IncomingByte == 4)
  {
    if  (test == false)
    {
      digitalWrite(cantiLeverB, HIGH);
      test = true;
    }
  }
}

