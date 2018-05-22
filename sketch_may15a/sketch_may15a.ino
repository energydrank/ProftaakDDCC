
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
int encoderVertImp1 = A8;
int encoderVertImp2 = A9;
int armVertUp = 7;
int armVertDown = 6;

unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev = 0;

unsigned char encoder_AVert;
unsigned char encoder_BVert;
unsigned char encoder_AVert_prev = 0;

int counter = 0;
int counterVert = 0;

bool test = false;
bool test2 = true;
bool test3 = false;
bool test4 = false;
bool test5 = false;
bool test6 = false;
bool test7 = false;

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
  Serial.begin(250000);
  Serial.println("boe");

}

void loop() {


  //
  //        if (test == false)
  //                {
  //                digitalWrite(cantiLeverB, HIGH);
  //                if (digitalRead(SwitchCantiLeverB) == 1)
  //                {
  //                  digitalWrite(cantiLeverB, LOW);
  //                }
  //                    if (digitalRead(switchHorConv) == LOW)
  //                    {
  //                      digitalWrite(horizontalConv, HIGH);
  //                    }
  //                    if (digitalRead(switchHorConv) == HIGH)
  //                    {
  //                      digitalWrite(horizontalConv, LOW);
  //                      if (digitalRead(switchVert) == HIGH){
  //                        test = true;
  //                      }
  //                    }
  //                digitalWrite(armVertUp, HIGH);
  //                if (digitalRead(switchVert) == HIGH)
  //                {
  //                  digitalWrite(armVertUp, LOW);
  //                  if (digitalRead(horizontalConv) == LOW)
  //                  {
  //                    test = true;
  //                  }
  //                }
  //                }

  // get the current elapsed time
  // Other processing can be done here

//  if (test == false)
//  {
//    if  (test2 == true)
//    {
//      digitalWrite(horizontalRack, HIGH);
//      encoder_A = digitalRead(encoderHorImp2);    // Read encoder pins
//      encoder_B = digitalRead(encoderHorImp1);
//      if ((!encoder_A) && (encoder_A_prev)) {
//        // A has gone from high to low
//        if (counter >= 110)
//        {
//          digitalWrite(horizontalRack, LOW);
//          test2 = false;
//          test7 = true;
//        }
//        if (encoder_B) {
//          counter++;
//          Serial.println(counter);
//        }
//        else {
//          counter--;
//          Serial.println(counter);
//        }
//
//      }
//      encoder_A_prev = encoder_A;     // Store value of A for next time
//    }
//  }
//  if (test7 == true) {
//    digitalWrite(armVertDown, HIGH);
//    encoder_AVert = digitalRead(encoderVertImp2);    // Read encoder pins
//    encoder_BVert = digitalRead(encoderVertImp2);
//    if ((!encoder_AVert) && (encoder_AVert_prev)) {
//      // A has gone from high to low
//      if (counterVert >= 20)
//      {
//        digitalWrite(armVertDown, LOW);
//        test7 = false;
//        test5 = true;
//      }
//      if (encoder_BVert) {
//        counterVert++;
//        Serial.println(counterVert);
//      }
//      else {
//        counterVert--;
//        Serial.println(counterVert);
//      }
//
//    }
//    encoder_AVert_prev = encoder_AVert;     // Store value of A for next time
//  }
//  if (test5 == true) {
//    if  (digitalRead(SwitchCantiLeverF) == LOW)
//    {
//      digitalWrite(cantiLeverF, HIGH);
//    }
//    if  (digitalRead(SwitchCantiLeverF) == HIGH)
//    {
//      digitalWrite(cantiLeverF, LOW);
//      test4 = true;
//      test5 = false;
//    }
//  }
//  if (test4 == true) {
//    if  (digitalRead(switchVert) == LOW)
//    {
//      digitalWrite(armVertUp, HIGH);
//    }
//    if (digitalRead(switchVert) == HIGH)
//    {
//      digitalWrite(armVertUp, LOW);
//      digitalWrite(cantiLeverB, HIGH);
//      test3 = true;
//      test4 = false;
//    }
//  }
//  if  (test3 == true)
//  {
//    if  (digitalRead(SwitchCantiLeverB) == 1)
//    {
//      digitalWrite(cantiLeverB, LOW);
//      test6 = true;
//    }
//    if (test6 == true)
//    {
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
//}
//

