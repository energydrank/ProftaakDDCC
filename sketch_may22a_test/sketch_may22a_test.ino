
/*
   Author: Doki Doki Coding Club
   Project: Fischer Technik automated warehouse bay
   Date: 22/05/2018

   All rights resevered
*/

//Input/Output Declaration
int switchCantiLeverF = A10;
int switchCantiLeverB = A11;
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
<<<<<<< HEAD
int switchVert = A3;
bool test = false;
int IncomingByte = 0;
int horizontalRack = 4;
int armVertDown = 6;
=======
int armVertDown = 6;

int IncomingByte = 11;
int IncomingByteLastState = 0;

//Variables to read Encoder values

unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev = 0;

unsigned char encoder_AVert;
unsigned char encoder_BVert;
unsigned char encoder_AVert_prev = 0;


bool xZeroPositionSet = false;
//Variables for retrieval process

bool xRetrieval = false;
bool xRetrievalHorizontalConvAlign = true;
bool xRetrievalCantiBAlign = false;
bool xRetrievalVerticalUpAlign = false;
bool xRetrievalCantiFAlign = false;
bool xRetrievalHorizintalRackAlign = false;
bool xRetrievalVerticalDownAlign  = false;
bool xRetrievalCantiFAlign2 = false;
bool xRetrievalCantiBAlign2 = false;
bool xRetrievalHorizontalConveyerAlign = false;
bool xCalculation = false;
bool xOneTimeDelay = false;
bool xOneTimeExecution = false;
bool xConveyerBeltExecution = false;
int iCounterHorizontal = 0;
int iCounterVertical = 0;

int iEncoderCounterHorizontal = 0;
int iEncoderCounterVertical = 0;
int iEncoderCounterVertical2 = 0;
>>>>>>> develop

int iDelayTime = 0;
int aHorizontalArray[] =  {0, 910, 1630, 2350};
int aVerticalArray[] = {0, -100, -530, -1050};

void setup() {
  // put your setup code here, to run once:
<<<<<<< HEAD
  Serial.begin(250000);
  pinMode(SwitchCantiLeverB, INPUT);
=======
  pinMode(horizontalConv, INPUT);
  pinMode(horizontalRack, INPUT);
  pinMode(switchCantiLeverF, INPUT);
  pinMode(switchCantiLeverB, INPUT);
>>>>>>> develop
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
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(Serial.read() + (String)"abhd");

  //  Checks if incomingbyte is set
  if (IncomingByte != -1 && IncomingByte != 0 && IncomingByte != 4) {
    //saves the state of the incoming byte so it can read both values
    if (xCalculation == false)
    {
      IncomingByteLastState = IncomingByte;
      //Takes first number of the incoming byte
      IncomingByte = IncomingByte / 10;
      IncomingByteLastState = (IncomingByteLastState % 10);
      iCounterVertical = aVerticalArray[IncomingByte];
      iCounterHorizontal = aHorizontalArray[IncomingByteLastState];
      xCalculation = true;
    }
    retrievalProcess();

  }
  else if (IncomingByte == 4) {
    zeroPosition();
  }
}

void zeroPosition() {

  //  resets ever axis' position to 0
  if (digitalRead(switchCantiLeverB) == HIGH)
  {
    digitalWrite(cantiLeverB, LOW);
    if (digitalRead(switchHorConv) == HIGH)
    {
<<<<<<< HEAD
      digitalWrite(cantiLeverB, HIGH);
      if (digitalRead(SwitchCantiLeverB) == HIGH)
=======
      digitalWrite(horizontalConv, LOW);
      if (digitalRead(switchVert) == HIGH)
>>>>>>> develop
      {
        digitalWrite(armVertUp, LOW);
        if (digitalRead(switchHorConv) == HIGH && digitalRead(switchVert) == HIGH && digitalRead(switchCantiLeverB) == HIGH)
        {
          digitalWrite(armVertUp, LOW);
          digitalWrite(horizontalConv, LOW);
          digitalWrite(cantiLeverB, LOW);
          xCalculation = false;
          IncomingByte = 0;
          IncomingByteLastState = 0;
          xRetrievalCantiBAlign2 = false;
          xRetrievalVerticalDownAlign = true;
        }
      }
<<<<<<< HEAD
      digitalWrite(horizontalConv, HIGH);
      if (digitalRead(switchHorConv) == HIGH)
=======
      else
      {
        digitalWrite(armVertUp, HIGH);
      }
    }
    else
    {
      digitalWrite(horizontalConv, HIGH);
    }
  }
  else {
    digitalWrite(cantiLeverB, HIGH);
  }
}
void returnProcess()
{

}
void retrievalProcess() {
  if  (xRetrievalHorizontalConvAlign == true)
  {
    digitalWrite(horizontalRack, HIGH);
    encoder_A = digitalRead(encoderHorImp2);
    encoder_B = digitalRead(encoderHorImp1);
    if ((!encoder_A) && (encoder_A_prev)) {
      if (iEncoderCounterHorizontal >= iCounterHorizontal)
>>>>>>> develop
      {
        digitalWrite(horizontalRack, LOW);
        xRetrievalHorizontalConvAlign = false;
        xRetrievalVerticalDownAlign  = true;
        iEncoderCounterHorizontal = 0;
      }
      if (encoder_B) {
        iEncoderCounterHorizontal++;
      }
      else {
        iEncoderCounterHorizontal--;
      }
    }
    encoder_A_prev = encoder_A;
  }
  if (xRetrievalVerticalDownAlign  == true) {
    digitalWrite(armVertDown, HIGH);
    encoder_AVert = digitalRead(encoderVertImp2);
    encoder_BVert = digitalRead(encoderVertImp1);
    if ((!encoder_AVert) && (encoder_AVert_prev)) {
      if (iEncoderCounterVertical <= iCounterVertical)
      {
        digitalWrite(armVertDown, LOW);
        xRetrievalVerticalDownAlign  = false;
        xRetrievalCantiFAlign = true;
        encoder_AVert_prev = encoder_AVert;
      }
      if (encoder_BVert) {
        iEncoderCounterVertical++;
      }
      else {
        iEncoderCounterVertical--;
      }
    }
    encoder_AVert_prev = encoder_AVert;
  }
  if (xRetrievalCantiFAlign == true) {
    if  (digitalRead(switchCantiLeverF) == LOW)
    {
      digitalWrite(cantiLeverF, HIGH);
    }
    if  (digitalRead(switchCantiLeverF) == HIGH)
    {
      digitalWrite(cantiLeverF, LOW);
      xRetrievalVerticalUpAlign = true;
      xRetrievalCantiFAlign = false;
      iCounterVertical = iCounterVertical + 100;
    }
  }
  if (xRetrievalVerticalUpAlign == true) {
    digitalWrite(armVertUp, HIGH);
    encoder_AVert = digitalRead(encoderVertImp2);
    encoder_BVert = digitalRead(encoderVertImp1);
    if ((!encoder_AVert) && (encoder_AVert_prev)) {
      if (iEncoderCounterVertical >= iCounterVertical)
      {
        digitalWrite(armVertUp, LOW);
        xRetrievalVerticalUpAlign  = false;
        xRetrievalCantiBAlign = true;
        encoder_AVert_prev = encoder_AVert;
      }
      if (encoder_BVert) {
        iEncoderCounterVertical++;
      }
      else {
        iEncoderCounterVertical--;
      }
    }
    encoder_AVert_prev = encoder_AVert;
  }
  if  (xRetrievalCantiBAlign == true)
  {
    if  (digitalRead(switchCantiLeverB) == 1)
    {
      digitalWrite(cantiLeverB, LOW);
      xRetrievalHorizintalRackAlign = true;
      xRetrievalCantiBAlign = false;
    }
    else
    {
      digitalWrite(cantiLeverB, true);
    }
  }
  if (xRetrievalHorizintalRackAlign == true)
  {
    if (digitalRead(switchHorConv) == HIGH)
    {
      digitalWrite(horizontalConv, LOW);
      xRetrievalHorizintalRackAlign = false;
      xRetrievalCantiFAlign2 = true;
    }
    else
    {
      digitalWrite(horizontalConv, HIGH);
    }
  }
  if  (xRetrievalCantiFAlign2 == true)
  {
    if (IncomingByte == 1 )
    {
      if (xOneTimeExecution == false)
      {
        digitalWrite(armVertDown, HIGH);
        delay(500);
        digitalWrite(armVertDown, LOW);
        xOneTimeExecution = true;
      }
      if  (digitalRead(switchCantiLeverF) == HIGH)
      {
        digitalWrite(cantiLeverF, LOW);
        digitalWrite(armVertDown, HIGH);
        delay(1500);
        digitalWrite(armVertDown, LOW);
        xRetrievalCantiFAlign2 = false;
        xRetrievalCantiBAlign2 = true;
      }
      else if  (digitalRead(switchCantiLeverF) == LOW)
      {
        digitalWrite(cantiLeverF, HIGH);
      }
    }
    else if (IncomingByte == 2 )
    {
      if  (digitalRead(switchCantiLeverF) == HIGH)
      {
        digitalWrite(cantiLeverF, LOW);
        digitalWrite(armVertDown, HIGH);
        delay(1100);
        digitalWrite(armVertDown, LOW);
        xRetrievalCantiFAlign2 = false;
        xRetrievalCantiBAlign2 = true;
      }
      else if  (digitalRead(switchCantiLeverF) == LOW)
      {
        digitalWrite(cantiLeverF, HIGH);
      }
    }
    else if (IncomingByte == 3 )
    {
      if (xOneTimeExecution == false)
      {
        digitalWrite(armVertUp, HIGH);
        delay(400);
        digitalWrite(armVertUp, LOW);
        xOneTimeExecution = true;
      }
      if  (digitalRead(switchCantiLeverF) == HIGH)
      {
        digitalWrite(cantiLeverF, LOW);
        digitalWrite(armVertDown, HIGH);
        delay(500);
        digitalWrite(armVertDown, LOW);
        xRetrievalCantiFAlign2 = false;
        xRetrievalCantiBAlign2 = true;
      }
      else if  (digitalRead(switchCantiLeverF) == LOW)
      {
        digitalWrite(cantiLeverF, HIGH);
      }
    }
  }
  if  (xRetrievalCantiBAlign2 == true)
  {
    if  (digitalRead(switchCantiLeverB) == LOW)
    {
      digitalWrite(cantiLeverB, HIGH);
    }
    if  (digitalRead(switchCantiLeverB) == HIGH)
    {
      digitalWrite(cantiLeverB, LOW);
      xRetrievalCantiBAlign2 = false;
      xConveyerBeltExecution = true;
    }
  }
<<<<<<< HEAD

//    digitalWrite(horizontalRack, HIGH);
}
=======
  if (xConveyerBeltExecution == true)
  {
    if (digitalRead(lightBarrierInside) == LOW)
    {
      digitalWrite(convBeltF, HIGH);
    }
    if (digitalRead(lightBarrierOutside) == LOW)
    {
      digitalWrite(convBeltF, LOW);
      zeroPosition();
      xConveyerBeltExecution = false;
    }
  }
}

>>>>>>> develop
