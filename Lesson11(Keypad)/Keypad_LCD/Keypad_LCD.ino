#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#include "KeyChar.h"
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0,0);
}
void loop()
{
  char c=getKey();
  if(c!='?'){
  lcd.setCursor(0,0);
  lcd.print(c);
  }
  delay(100);
}
