#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int seconds=0;
void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Armstrong");
}
