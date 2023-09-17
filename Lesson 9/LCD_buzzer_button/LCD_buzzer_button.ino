#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int second=0,buzzer_pin=0;
 void play_tone(){
digitalWrite(buzzer_pin,HIGH);
delay(100);
digitalWrite(buzzer_pin,LOW);
 }
void setup() {
// put your setup code here, to run once:
lcd.init();
lcd.clear();
lcd.backlight(); 
pinMode(buzzer_pin,OUTPUT);
lcd.setCursor(0,0);
lcd.print(second);
} 
void loop() {
// put your main code here, to run repeatedly:
if(analogRead(A0)==1024){
play_tone();
second++;
lcd.setCursor(0,0);
lcd.print(second); 
delay(300);
 }
}
