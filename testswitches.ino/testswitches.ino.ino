#include <SPI.h>
#include <Controllino.h>

int SwitchCantiLeverF = A10;
int SwitchCantiLeverB = A11;
int switchHorConv = A0;
int switchVert = A3;
int cantiLeverB = 9;
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
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//  if (digitalRead(SwitchCantiLeverF) == HIGH)
//  {
//    Serial.println("Switch cantilever front werkt");
//  }
//
//    if (digitalRead(SwitchCantiLeverB) == HIGH)
//  {
//    Serial.println("Switch cantilever back werkt");
//  }
//
//    if (digitalRead(switchHorConv) == HIGH)
//  {
//    Serial.println("Switch horizontal axis werkt");
//  }
//
//  if (digitalRead(switchVert) == HIGH)
//  {
//    Serial.println("Switch vertical axis werkt");
//  }

  if (digitalRead(SwitchCantiLeverF) == LOW)
  {
    digitalWrite(cantiLeverF, HIGH); 
  }
  if (digitalRead(SwitchCantiLeverF) == HIGH)
  {
    digitalWrite(cantiLeverF, LOW); 
  }


//  if (digitalRead(switchHorConv) == LOW)
//  {
//    digitalWrite(horizontalConv, HIGH); 
//  }
//  if (digitalRead(switchHorConv) == HIGH)
//  {
//    digitalWrite(horizontalConv, LOW); 
//  }


//   if (digitalRead(lightBarrierInside) == LOW)
//  {
//    digitalWrite(convBeltF,HIGH);
//    
//  }
//     if (digitalRead(lightBarrierOutside) == LOW)
//  {
//    digitalWrite(convBeltF,LOW);
//  }

  
//
//     if (digitalRead(lightBarrierInside) == HIGH)
//  {
//    digitalWrite(convBeltB,HIGH);
//    
//  }
//     if (digitalRead(lightBarrierOutside) == HIGH)
//  {
//    digitalWrite(convBeltB,LOW);
//  }


//  Serial.println(digitalRead(encoderHorImp2));
//    digitalRead(encoderHorImp2);
//  Serial.println(encoderHorImp2);
//    digitalRead(encoderHorImp3);
//  Serial.println(encoderHorImp3);
//    digitalRead(encoderHorImp4);
//  Serial.println(encoderHorImp4);
//if (test == false)
//{
//  digitalWrite(horizontalRack,HIGH);
//  delay(1950);
//  digitalWrite(horizontalRack,LOW);
//  test = true;
//  Serial.println(digitalRead(encoderHorImp2));
//}
//
//if  (test == false){
//  if (digitalRead(switchVert) == LOW)
//  {
//    digitalWrite(armVertUp, HIGH); 
//  }
//  if (digitalRead(switchVert) == HIGH)
//  {
//    digitalWrite(armVertUp, LOW);
//    digitalWrite(armVertDown,HIGH);
//    delay(200);
//    digitalWrite(armVertDown,LOW);
//    test = true;
//  }
//}



  
  
}
