#include <LiquidCrystal_I2C.h>
#define trig 14
#define echo 12
LiquidCrystal_I2C lcd(0x27, 16, 2);
int previous=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
  lcd.init(); 
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
}
int getDistance(){ 
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}
void loop() {
  // put your main code here, to run repeatedly:
int current=getDistance();
if(abs(previous-current)>3){
  previous=current;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(current);
  Serial.println(current);
}
delay(50);
}
