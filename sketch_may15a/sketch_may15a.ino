
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
bool test6 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(horizontalRack, INPUT);
  // put your setup code here, to run once:
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

  if (test == false)
  {
    if  (test2 == false)
    {
      digitalWrite(horizontalRack, HIGH);
      delay(1950);
      digitalWrite(horizontalRack, LOW);

      digitalWrite(armVertDown, HIGH);
      delay(320);
      digitalWrite(armVertDown, LOW);
      test2 = true;
      test5 = true;
      delay(5000);
    }
    if (test5 == true) {
      if  (digitalRead(SwitchCantiLeverF) == LOW)
      {
        digitalWrite(cantiLeverF, HIGH);
      }
      if  (digitalRead(SwitchCantiLeverF) == HIGH)
      {
        digitalWrite(cantiLeverF, LOW);
        test4 = true;
        test5 = false;
      }
    }
    if (test4 == true) {
      if  (digitalRead(switchVert) == LOW)
      {
        digitalWrite(armVertUp, HIGH);
      }
      if (digitalRead(switchVert) == HIGH)
      {
        digitalWrite(armVertUp, LOW);
        digitalWrite(cantiLeverB, HIGH);
        test3 = true;
        test4 = false;
      }
    }
    if  (test3 == true)
    {
      if  (digitalRead(SwitchCantiLeverB) == 1)
      {
        digitalWrite(cantiLeverB, LOW);
        test6 = true;
      }
      if (test6 == true)
      {
        if (digitalRead(switchHorConv) == LOW)
        {
          digitalWrite(horizontalConv, HIGH);
        }
        if (digitalRead(switchHorConv) == HIGH)
        {
          digitalWrite(horizontalConv, LOW);
          test = true;
        }
      }
    }
  }

//        if (test == false) 
//        { 
//        digitalWrite(cantiLeverB, HIGH); 
//        if (digitalRead(SwitchCantiLeverB) == 1) 
//        { 
//          digitalWrite(cantiLeverB, LOW); 
//        } 
//            digitalWrite(cantiLeverF, HIGH); 
//          if  (digitalRead(SwitchCantiLeverF) == 1) 
//          { 
//            digitalWrite(cantiLeverF,LOW); 
//          } 
//            if (digitalRead(switchHorConv) == LOW) 
//            { 
//              digitalWrite(horizontalConv, HIGH); 
//            } 
//            if (digitalRead(switchHorConv) == HIGH) 
//            { 
//              digitalWrite(horizontalConv, LOW); 
//            } 
//        digitalWrite(armVertUp, HIGH); 
//        if (digitalRead(switchVert) == HIGH) 
//        { 
//          digitalWrite(armVertUp, LOW); 
//          test = true; 
//        } 
//        } 
}
