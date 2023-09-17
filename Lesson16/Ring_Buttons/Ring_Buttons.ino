#include "colors.h"
#define red 13
#define green 15
#define blue A0
int red_number=0, green_number=0, blue_number=0;
void setup() {
set();
pinMode(red, INPUT);
pinMode(green, INPUT);
pinMode(blue, INPUT);
}
void loop() { 
  if(digitalRead(red)){ 
    red_number+=30; 
    if (red_number>255){
       red_number=0; }
delay(50);
} 
if(digitalRead(green)) {
   green_number+=30; 
   if(green_number>255){
      green_number=0; }
delay(50);
} 
if(analogRead(blue)==1024){
  blue_number+=30;
   if (blue_number>255){
      blue_number=0;
} 
delay(50);
}
show_levels(13,red_number,green_number,blue_number);
}