#include <LiquidCrystal_I2C.h>
#define buzzer D3
#include "rfid.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  rfid_init();
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  if(!card_detected()){
  return;
}
  Serial.println(F("Card Detected:"));
  lcd.setCursor(0, 0);
  lcd.print("Card Detected:");
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(card_UID());
  Serial.print(card_UID()); 
  delay(800);
}