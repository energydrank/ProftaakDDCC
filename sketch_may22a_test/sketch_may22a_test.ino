#include <SPI.h>
#include <Controllino.h>

int SwitchCantiLeverB = A11;
int cantiLeverB = 9;
int switchHorConv = A0;
int horizontalConv = 5;
int armVertUp = 7;
int switchVert = A3;
bool test = false;
int IncomingByte = 0;
int horizontalRack = 4;
int armVertDown = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  pinMode(SwitchCantiLeverB, INPUT);
  pinMode(switchHorConv, INPUT);
  pinMode(cantiLeverB, OUTPUT);
  pinMode(horizontalConv, OUTPUT);
  pinMode(armVertUp, OUTPUT);
  pinMode(switchVert, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(Serial.read() + (String)"abhd");
  IncomingByte = Serial.read();

  if (IncomingByte == 4)
  {
    if (test == false)
    {
      digitalWrite(cantiLeverB, HIGH);
      if (digitalRead(SwitchCantiLeverB) == HIGH)
      {
        digitalWrite(cantiLeverB, LOW);
      }
      digitalWrite(horizontalConv, HIGH);
      if (digitalRead(switchHorConv) == HIGH)
      {
        digitalWrite(horizontalConv, LOW);
      }
      digitalWrite(armVertUp, HIGH);
      if (digitalRead(switchVert) == HIGH)
      {
        digitalWrite(armVertUp, LOW);
        test = true;
        IncomingByte = 0;
      }
    }
  }

//    digitalWrite(horizontalRack, HIGH);
}
