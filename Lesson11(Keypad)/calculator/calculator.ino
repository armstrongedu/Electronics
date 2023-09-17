#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "format.h"

void setup() {
  // put your setup code here, to run once:
  lcd.init(); 
  lcd.clear();
  lcd.backlight();
  }

void loop() {
  // put your main code here, to run repeatedly:

     char c=getKey();
     if(c!='?'){

        key_pressed(c);
    }
   delay(100);
}
