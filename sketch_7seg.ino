const int buttonPin = 2;
const int segPinE = 3;
const int segPinD = 4;
const int segPinC = 5;
const int segPinG = 8;
const int segPinF = 9;
const int segPinA = 11;
const int segPinB = 10;

int buttonState = 0;
int contador = 0;

void setup() {
  pinMode(segPinA, OUTPUT);
  pinMode(segPinB, OUTPUT);
  pinMode(segPinC, OUTPUT);
  pinMode(segPinD, OUTPUT);
  pinMode(segPinE, OUTPUT);
  pinMode(segPinF, OUTPUT);
  pinMode(segPinG, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH){
    contador++;
    delay(500);
  }

  switch(contador){
    case 0:
      digitalWrite(segPinA,HIGH);
      digitalWrite(segPinB,HIGH);
      digitalWrite(segPinC,HIGH);
      digitalWrite(segPinD,HIGH);
      digitalWrite(segPinE,HIGH);
      digitalWrite(segPinF,HIGH);
      digitalWrite(segPinG,LOW);
    break;

    case 1:
      digitalWrite(segPinA,LOW);
      digitalWrite(segPinB,HIGH);
      digitalWrite(segPinC,HIGH);
      digitalWrite(segPinD,LOW);
      digitalWrite(segPinE,LOW);
      digitalWrite(segPinF,LOW);
      digitalWrite(segPinG,LOW);
    break;

    case 2:
      digitalWrite(segPinA,HIGH);
      digitalWrite(segPinB,HIGH);
      digitalWrite(segPinC,LOW);
      digitalWrite(segPinD,HIGH);
      digitalWrite(segPinE,HIGH);
      digitalWrite(segPinF,LOW);
      digitalWrite(segPinG,HIGH);
    break;

    case 3:
      digitalWrite(segPinA,HIGH);
      digitalWrite(segPinB,HIGH);
      digitalWrite(segPinC,HIGH);
      digitalWrite(segPinD,HIGH);
      digitalWrite(segPinE,LOW);
      digitalWrite(segPinF,LOW);
      digitalWrite(segPinG,HIGH);
    break;

    case 4:
      digitalWrite(segPinA,LOW);
      digitalWrite(segPinB,HIGH);
      digitalWrite(segPinC,HIGH);
      digitalWrite(segPinD,LOW);
      digitalWrite(segPinE,LOW);
      digitalWrite(segPinF,HIGH);
      digitalWrite(segPinG,HIGH);
    break;

    case 5:
      digitalWrite(segPinA,HIGH);
      digitalWrite(segPinB,LOW);
      digitalWrite(segPinC,HIGH);
      digitalWrite(segPinD,HIGH);
      digitalWrite(segPinE,LOW);
      digitalWrite(segPinF,HIGH);
      digitalWrite(segPinG,HIGH);
    break;

    case 6:
      digitalWrite(segPinA,HIGH);
      digitalWrite(segPinB,LOW);
      digitalWrite(segPinC,HIGH);
      digitalWrite(segPinD,HIGH);
      digitalWrite(segPinE,HIGH);
      digitalWrite(segPinF,HIGH);
      digitalWrite(segPinG,HIGH);
    break;

    case 7:
      digitalWrite(segPinA,HIGH);
      digitalWrite(segPinB,HIGH);
      digitalWrite(segPinC,HIGH);
      digitalWrite(segPinD,LOW);
      digitalWrite(segPinE,LOW);
      digitalWrite(segPinF,LOW);
      digitalWrite(segPinG,LOW);
    break;

    case 8:
      digitalWrite(segPinA,HIGH);
      digitalWrite(segPinB,HIGH);
      digitalWrite(segPinC,HIGH);
      digitalWrite(segPinD,HIGH);
      digitalWrite(segPinE,HIGH);
      digitalWrite(segPinF,HIGH);
      digitalWrite(segPinG,HIGH);
    break;

    case 9:
      digitalWrite(segPinA,HIGH);
      digitalWrite(segPinB,HIGH);
      digitalWrite(segPinC,HIGH);
      digitalWrite(segPinD,HIGH);
      digitalWrite(segPinE,LOW);
      digitalWrite(segPinF,HIGH);
      digitalWrite(segPinG,HIGH);
    break;

    case 10:
      contador=0;
    break;
  }
}
