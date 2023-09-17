#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define buzzer D3
#include "rfid.h"
void setup() {
  Serial.begin(9600);        
  rfid_init();
  pinMode(buzzer,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
    while(!Serial){};
  Serial.println("Add card to write personal data on");
  lcd.setCursor(0,0);
  lcd.print("put a card");
}

void loop() {

 if(!card_detected()){
   return;
 }
 
  Serial.println(card_UID());
  byte buffer[18];
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Type Family name");
  lcd.setCursor(0,1);
  lcd.print("ending with #");
Serial.println("Type Family name, ending with #");

read_buffer(buffer,18);
delay(10);
if(!write_block(1,buffer,16)){
  return;
}


  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Type First name");
  lcd.setCursor(0,1);
  lcd.print("ending with #");
Serial.println("Type First name, ending with #");

read_buffer(buffer,18);

delay(10);
if(!write_block(2,buffer,16)){
  return;
}


  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("saved!");
  saved();
  Serial.println(" ");
  end_loop();

}
