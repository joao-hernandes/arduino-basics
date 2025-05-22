#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 6, 7, 8, 9);            //Inicializar pinos do LCD (rs, enable, d4, d5, d6, d7)

void setup() {
  lcd.begin(16, 2);                             //Inicializar lcd
  lcd.clear();                                  //Limpar display

  lcd.setCursor(0, 0);                          //Posicionar o cursor
  lcd.print("LCD funcionando!");                //Exibe o texto

  lcd.setCursor(0, 1);                          //Posiciona cursor na segunda linha
  lcd.print("Segunda linha:)");                 //Exibe o texto
}

void loop() {

}
