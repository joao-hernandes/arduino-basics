//Ler um potênciometro de 10k ohm através do pino analógico, fazer a conversão e exibir o valor de resistência utilizando o Serial Monitor

const int sensorPin = A0;                   //Pino conectado no potenciometro
int valorDigital = 0;                       //Variavel para armazenar o valor digital lido
float resistencia = 0;                      //Variavel para armazenar resistencia equivalente

void setup() {
  Serial.begin(9600);                       //Iniciar comunicação serial
}

void loop() {
  valorDigital = analogRead(sensorPin);     //Ler pino analogico
  resistencia = valorDigital * 9.76;        //Range do pino analogico vai de 0 a 1023, o potenciometro é de 10k, cada valor analogico é equivalente a 10k/1024 de resistencia
  Serial.print("Resistencia: ");            //Exibe o texto no Serial Monitor
  Serial.println(resistencia);              //Exibe o valor convertido da resistência
  delay(1000);                              //Delay entre leituras
}
