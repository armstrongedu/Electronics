#include <IRremote.h>

#include "colors.h"
#define IRpin 5
int red_number=0,green_number=0,blue_number=0,led_number=16,command=0;
void setup() {
  set();
  IrReceiver.begin(IRpin,ENABLE_LED_FEEDBACK);
  Serial.begin(9600);
}
void show_led(){
  for(int i=0;i<led_number;i++){
    TurnOn_pixel(i,red_number,green_number,blue_number);
  }
  for(int i=led_number;i<NUMPIXELS;i++){
    TurnOn_pixel(i,0,0,0);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
 if(IrReceiver.decode()){
      command = IrReceiver.decodedIRData.command;
      IrReceiver.resume();
      Serial.println(command);
      if(command==69){
        red_number+=30;
        if(red_number>255){
          red_number=255;
        }
        show_led();
      }
      else if(command==70){
        
        green_number+=30;
        if(green_number>255){
          green_number=255;
        }
        show_led();
      }
      else if(command==71){
         blue_number+=30;
        if(blue_number>255){
          blue_number=255;
        }
        show_led();
      }
      else if(command==68){
        red_number-=30;
        if(red_number<0){
          red_number=0;
        }
        show_led();
      }
      else if(command==64){
        green_number-=30;
        if(green_number<0){
          green_number=0;
        }
        show_led();
      }
      else if(command==67){
         blue_number-=30;
        if(blue_number<0){
          blue_number=0;
        }
        show_led();
      }
      else if(command==24){
       led_number++;
       if(led_number>NUMPIXELS){
         led_number=NUMPIXELS;
       }
       show_led();
      }
      else if(command==82){
        led_number--;
        if(led_number<0){
          led_number=0;
        }
      show_led();
      }
      else{
        command=0;
      }
      
      delay(1000);
  }
  
}
