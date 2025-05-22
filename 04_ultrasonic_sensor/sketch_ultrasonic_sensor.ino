//Utilizar um sensor ultrasonico HC-SR04 para controlar o funcionamento de 3 LEDs

#include <Wire.h>
#include <LiquidCrystal.h>

//LED
const int leds[] = {11, 12, 13};                      //Pinos LEDs
const int numLeds = sizeof(leds) / sizeof(leds[0]);   //Quantidade de LEDs

//Sensor de distância Ultrasônico
const int trigP = 9;                                  //Pino conectado ao TRIG do sensor
const int echoP = 10;                                 //Pino conectado ao ECHO
long duration;                                        //Variavel para armazenar o tempo que levou entre o pulsar do TRIG e a çeitura do ECHO
int  distance = 0;                                    //Variavel para ser armazenado o valor de distancia apos voncersão

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);                  //Declarar pinos do LCD (rs, enable, d4, d5, d6, d7)

void setup() {

  lcd.begin(16, 2);                                   //Inicializa o LCD
  lcd.print("Distancia");                             //Escreve o texto

  for(int i = 0; i < numLeds; i++){                   //Inicializa os pinos de cada LED como saida
    pinMode(leds[i], OUTPUT);
  }
  pinMode(trigP, OUTPUT);                             //Inicializa o pino TRIG como saida
  pinMode(echoP, INPUT);                              //Inicializa o pino echo como entrada
}

void loop() {
//Rotina de funcionamento de sensor
  delayMicroseconds(2);                               //Delay para começar a leitura do sensor
  digitalWrite(trigP, HIGH);                          //Envia o pulso
  delayMicroseconds(10);
  digitalWrite(trigP, LOW);                           //Desliga o pulso

  duration = pulseIn(echoP, HIGH);                    //Ativa o pino echo para fazer a leitura e armazena na variavel de duração
  distance = duration*0.034/2;                        //Calculo de distância

//Exibição do valor lido
  lcd.setCursor(0, 1);                                //Move o cursor para o inicio do LCD
  lcd.print("Dist: ");                                //Exibe o texto
  lcd.print(distance);                                //Exibe o valor armazenado na variavel "distancia"
  lcd.print("  cm  ");

//Rotina de controle dos LEDs
  for(int i = 0; i < numLeds; i++){                   //Desligar todos os LEDs
    digitalWrite(leds[i], LOW);
  }

//Ligar LED específico para cada distância
  if (distance <= 30) {
    digitalWrite(leds[0], HIGH);
  }
  else if (distance > 30 && distance < 60) {
    digitalWrite(leds[1], HIGH);
  }
  else if (distance >= 60) {
    digitalWrite(leds[2], HIGH);
  }

  delay(1000);                                        //Delay entre cada leitura
}
