//Utilizar um LDR em um circuito divisor de tensão para controlar um LED

const int ledPin = 5;                   //Pino onde o LED esta conectado
const int ldrPin = A5;                  //Pino analogico conectado o LDR

void setup() {
  pinMode(ledPin, OUTPUT);              //Inicializar pino do LED com saida
}

void loop() {
  int ldrValor = analogRead(ldrPin);    //Leitura do pino analogico do LDR, valor varia de 0 a 1023

  if(ldrValor < 310){                   //Caso o valor da leitura do LDR for menor que 310,
    digitalWrite(ledPin, HIGH);         //acende o LED
  }
  else{
    digitalWrite(ledPin, LOW);          //Maior que 310, manem o LED apagado
  }
  delay(100);                           //Delay entre cada leitura
}
