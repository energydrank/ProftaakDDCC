#include <SPI.h>
#include <Controllino.h>

int SwitchCantiLeverF = A10;
int SwitchCantiLeverB = A11;
int switchHorConv = A0;
int switchVert = A3;
int cantiLeverB = 9;
int cantiLeverF = 8;
int horizontalConv = 5;
int horizontalRack = 4;
int lightBarrierInside = A1;
int lightBarrierOutside = A2;
int convBeltF = 2;
int convBeltB = 3;
int encoderHorImp1 = A6;
int encoderHorImp2 = A7;
int encoderHorImp3 = A8;
int encoderHorImp4 = A9;
int armVertUp = 7;
int armVertDown = 6;

bool test = false;


void setup() {
  // put your setup code here, to run once:
pinMode(horizontalRack,INPUT);
  // put your setup code here, to run once:
  pinMode(SwitchCantiLeverF,INPUT);
  pinMode(SwitchCantiLeverB,INPUT);
  pinMode(switchHorConv,INPUT);
  pinMode(switchVert,INPUT);
  pinMode(cantiLeverB, OUTPUT);
  pinMode(lightBarrierInside,INPUT);
  pinMode(lightBarrierOutside,INPUT);
  pinMode(convBeltF,OUTPUT);
  pinMode(convBeltB,OUTPUT);
  pinMode(encoderHorImp1,INPUT);
  pinMode(armVertUp,OUTPUT);
  pinMode(armVertDown,OUTPUT);
  pinMode(cantiLeverF,OUTPUT);
  Serial.begin(9600);
}

void loop() {


//Serial.println(digitalRead(SwitchCantiLeverB));
Serial.println(digitalRead(SwitchCantiLeverF));
  
if (test == false)
{  
  digitalWrite(horizontalRack,HIGH);
  delay(1950);
  digitalWrite(horizontalRack,LOW);
    digitalWrite(cantiLeverF, HIGH);
  if  (digitalRead(SwitchCantiLeverF) == 1)
  {
    digitalWrite(cantiLeverF,LOW);
  }
  
  if  (digitalRead(switchVert) == LOW)
  {
    digitalWrite(armVertUp,HIGH);
  }
  else if (digitalRead(switchVert) == HIGH)
  {
    digitalWrite(armVertUp, LOW);
  }
  test = true;
}

}
