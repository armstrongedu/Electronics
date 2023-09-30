#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define buzzer 0
#include "rfid.h"

void setup() {
    Serial.begin(9600); // Initialize serial communications with the PC
    while (!Serial);
    rfid_init();
    pinMode(buzzer,OUTPUT);
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("your balance is");
    lcd.setCursor(0,1);
}

void loop() {
    // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
   if(!card_detected()){
        return;
       }
 
  byte buffer[18];
  if(!read_block(5,buffer,sizeof(buffer))){
    return;
  }
  buffer[0]=buffer[0]-10;
  if(buffer[0]<0 || buffer[0]>100) buffer[0]=100;
  if(!write_block(5,buffer,16)){
    return;
  }
  update_mode(buffer[0]);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("your balance is");
  lcd.setCursor(0,1);
  lcd.print(buffer[0]);
  delay(500);
  end_loop();
}