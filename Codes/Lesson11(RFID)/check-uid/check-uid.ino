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
  if(card_UID()=="enter here your specific card UID"){
  success();
  Serial.println("Access granted");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access granted");


  }
  else{
  failure();
  lcd.clear();
  lcd.setCursor(0, 0);
  Serial.println("Access denied");
  lcd.print("Access denied");
}
}