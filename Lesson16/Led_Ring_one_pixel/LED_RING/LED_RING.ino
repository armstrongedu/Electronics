#include "colors.h"
void setup() {
set();
}
void loop() {
for(int i=0;i<24;i++){
  TurnOn_pixel(i,255,0,0);
  delay(500);
  TurnOn_pixel(i,0,0,0);
 }
}