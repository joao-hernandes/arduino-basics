//Controle de posição de um servo motor através de um botão utilizando a biblioteca Servo.h

#include <Servo.h>

Servo myServo;                                            //Declaração do servo

const int button = 2;                                     //Pino conectado o botão
bool buttonState = HIGH;                                  //Estado inicial do botão
bool lastButtonState = HIGH;                              //Ultimo estado que o botão esteve
unsigned long lastDebounceTime = 0;                       //Tempo desde a ultima vez que foi realizado o debounce do botão
const unsigned long debounceDelay = 50;                   //Valor fixo para esperar antes de ler o botão

bool servoDirection = false;                              //false = 0°, true = 180°

void setup() {
  pinMode(button, INPUT_PULLUP);                          //Declarar o pino do botão como entrada ativando o pullup resistor
  myServo.attach(9);                                      //Declarar o pino em que o servo motor esta conectado
  myServo.write(0);                                       //Inicia em 0°
}

void loop() {
  int reading = digitalRead(button);                      //Variavel que armazena o estado atual do botão

  if (reading != lastButtonState) {                       //Caso o valor lido na variavel "reading" for diferente do ultimo estado do botão, ouve uma mudança de estado
    lastDebounceTime = millis();                          //A variavel do tempo do ultimo debounce armazena o tempo atual do código
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {    //Compara se o tempo entre a mudança de estado é maior que o valor fixo para realizar a leitura
    if (reading == LOW && buttonState == HIGH) {          //Botão foi pressionado
      servoDirection = !servoDirection;                   //Inverte a diração do motor
      myServo.write(servoDirection ? 180 : 0);            //Seleciona a posiçaõ do servo baseado na direção
    }
    buttonState = reading;                                //Armazena o estado atual do botão
  }

  lastButtonState = reading;                              //Armazena o ultimo estado do botão
}
