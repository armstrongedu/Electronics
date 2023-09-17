#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int second=0;
void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
pinMode(13,INPUT);
lcd.setCursor(0,0);
lcd.print(second);
}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(13)){
  second++;
  lcd.setCursor(0,0);
  lcd.print(second);
  delay(50);
}
}
