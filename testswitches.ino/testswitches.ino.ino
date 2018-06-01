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
bool test2 = false;
bool test3 = false;
bool test4 = false;
bool test5 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(horizontalRack, OUTPUT);
  pinMode(SwitchCantiLeverF, INPUT);
  pinMode(SwitchCantiLeverB, INPUT);
  pinMode(switchHorConv, INPUT);
  pinMode(switchVert, INPUT);
  pinMode(cantiLeverB, OUTPUT);
  pinMode(lightBarrierInside, INPUT);
  pinMode(lightBarrierOutside, INPUT);
  pinMode(convBeltF, OUTPUT);
  pinMode(convBeltB, OUTPUT);
  pinMode(encoderHorImp1, INPUT);
  pinMode(armVertUp, OUTPUT);
  pinMode(armVertDown, OUTPUT);
  pinMode(cantiLeverF, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  Serial.println(digitalRead(SwitchCantiLeverB));
  Serial.println(digitalRead(SwitchCantiLeverF));
  Serial.print("CantileverF = ");
  Serial.println(digitalRead(cantiLeverF));

  //  if (test == false)
  //  {
  //    if  (test2 == false)
  //    {
  //      digitalWrite(horizontalRack, HIGH);
  //      delay(2000);
  //      digitalWrite(horizontalRack, LOW);
  //
  //      digitalWrite(armVertDown, HIGH);
  //      delay(320);
  //      digitalWrite(armVertDown, LOW);
  //      test2 = true;
  //      test5 = true;
  //    }
  //    if (test5 == true) {
  //      if  (digitalRead(SwitchCantiLeverF) == LOW)
  //      {
  //        digitalWrite(cantiLeverF, HIGH);
  //      }
  //      if  (digitalRead(SwitchCantiLeverF) == HIGH)
  //      {
  //        digitalWrite(cantiLeverF, LOW);
  //        test4 = true;
  //        test5 = false;
  //      }
  //    }
  //    if (test4 == true) {
  //      if  (digitalRead(switchVert) == LOW)
  //      {
  //        digitalWrite(armVertUp, HIGH);
  //      }
  //      if (digitalRead(switchVert) == HIGH)
  //      {
  //        digitalWrite(armVertUp, LOW);
  //        digitalWrite(cantiLeverB, HIGH);
  //        test3 = true;
  //        test4 = false;
  //      }
  //    }
  //    if  (test3 == true)
  //    {
  //      if  (digitalRead(SwitchCantiLeverB) == 1)
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
  //        test = true;
  //      }
  //    }
  //  }




  //  if (test == false)
  //  {
  //    digitalWrite(cantiLeverF, HIGH);
  //    if (digitalRead(SwitchCantiLeverF) == 1)
  //    {
  //      digitalWrite(cantiLeverF, LOW);
  //      test = true;
  //    }
  //
  //  }
  //
  //        if (test == false)
  //        {
  //              if (digitalRead(SwitchCantiLeverB) == 0)
  //              {
  //                digitalWrite(cantiLeverB, HIGH);
  //              }
  //              if (digitalRead(SwitchCantiLeverB) == 1)
  //              {
  //                digitalWrite(cantiLeverB, LOW);
  //                test = true;
  //              }
  //
  //        }













//  if (test == false)
//  {
//    digitalWrite(cantiLeverB, HIGH);
//    if (digitalRead(SwitchCantiLeverB) == 1)
//    {
//      digitalWrite(cantiLeverB, LOW);
//    }
//    if (digitalRead(switchHorConv) == LOW)
//    {
//      digitalWrite(horizontalConv, HIGH);
//    }
//    if (digitalRead(switchHorConv) == HIGH)
//    {
//      digitalWrite(horizontalConv, LOW);
//    }
//    digitalWrite(armVertUp, HIGH);
//    if (digitalRead(switchVert) == HIGH)
//    {
//      digitalWrite(armVertUp, LOW);
//      test = true;
//    }
//  }

//
//  if (test == false)
//  {
//    digitalWrite(armVertUp, HIGH);
//    if (digitalRead(switchVert) == HIGH)
//    {
//      digitalWrite(armVertUp, LOW);
//      test = true;
//    }
//  }

















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
  //
  //  if (digitalRead(switchHorConv) == LOW)
  //  {
  //    digitalWrite(horizontalConv, HIGH);
  //  }
  //  if (digitalRead(switchHorConv) == HIGH)
  //  {
  //    digitalWrite(horizontalConv, LOW);
  //  }





  if (digitalRead(lightBarrierInside) == LOW)
  {
    digitalWrite(convBeltF, HIGH);

  }
  if (digitalRead(lightBarrierOutside) == LOW)
  {
    digitalWrite(convBeltF, LOW);
  }


  //
  //       if (digitalRead(lightBarrierInside) == HIGH)
  //    {
  //      digitalWrite(convBeltB,HIGH);
  //
  //    }
  //       if (digitalRead(lightBarrierOutside) == HIGH)
  //    {
  //      digitalWrite(convBeltB,LOW);
  //    }


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
