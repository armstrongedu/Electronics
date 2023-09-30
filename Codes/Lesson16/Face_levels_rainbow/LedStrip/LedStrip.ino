#include "colors.h"
void setup() {
  set();
}
void loop() {
  for(int i=1;i<=13;i++){
    show_levels(i,255,0,0);
    delay(500);
  }
  delay(1000);
  clear_face();
  delay(1000);
  show_rainbow('c',5);
  clear_face();
  delay(1000);
  show_rainbow('a',5);
  clear_face();
}
