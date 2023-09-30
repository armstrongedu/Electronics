#include"colors.h"
#define trig 14
#define echo 12
void setup() {
set();
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
}
void loop() {
// put your main code here, to run repeatedly:
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
long duration = pulseIn(echo, HIGH);
 int distance = duration*0.034/2 ;
  if(distance>30){
    show_levels(13,0,255,0);
}
else if (distance<4) {
    show_levels(13,255,0,0);
}
else{
  show_levels(map (distance, 30, 4, 1, 13),map (distance, 30,4,0,255), map(distance, 4, 30,0,255),0);
  }
  Serial.println(distance);
  delay(100);
}