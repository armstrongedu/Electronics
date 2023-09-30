#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int second = 30,minute=8,hour=12;
int set_button=13,inc_button=15,dec_button=A0,time_slot=1;
long current=0;
void updateScreen(){
    lcd.setCursor(0, 0);
    if(second < 10){
      lcd.print("0");
    }
    lcd.print(second);
    lcd.print(":");
    
    if(minute < 10){
      lcd.print("0");
    }
    lcd.print(minute);
    lcd.print(":");
    
    if(hour < 10){
      lcd.print("0");
    }
    lcd.print(hour);
  }
void overflow(){
    if(second == 60){
      second = 0;
      minute++;
    }
    if(minute == 60){
      minute = 0;
      hour++;
    }
    if(hour == 24){
      hour = 0;
    }
}
void underflow(){
  if(second==-1){
     second=59;
     minute--;
 }
 if(minute==-1){
   minute=59;
   hour--;
 }
 if(hour==-1){
   hour=0;
 } 
}
void inc(){   
    second++;
    overflow();
    updateScreen(); 
}
void set(){
  while(time_slot<4){
    yield();
    if(time_slot==1){
     if(digitalRead(inc_button)){
       second++;
       overflow();
       delay(300);
     }
      if(analogRead(dec_button)==1024){
       second--;
       underflow();
       delay(300);
     } 
     lcd.setCursor(0,1);
     lcd.print("__      ");
  }
    else if(time_slot==2){
     if(digitalRead(inc_button)){
       minute++;
       overflow();
       delay(300);
     }
      if(analogRead(dec_button)==1024){
       minute--;
       underflow();
       delay(300); 
     } 
     lcd.setCursor(0,1);
     lcd.print("   __   ");
  }
    else if(time_slot==3){
     if(digitalRead(inc_button)){
       hour++;
       overflow();
       delay(300);
     }
      if(analogRead(dec_button)==1024){
       hour--;
       underflow();
       delay(300);
     } 
     lcd.setCursor(0,1);
     lcd.print("      __");
  }   
    updateScreen();
    if(digitalRead(set_button)){
    time_slot++;
    delay(300);
    }
  }
   lcd.setCursor(0,1);
   lcd.print("        ");
}
void setup() {
lcd.init(); 
lcd.clear();
lcd.backlight();
pinMode(set_button,INPUT);
pinMode(inc_button,INPUT);
}
void loop() {
   if(millis()-current>1000){
     current=millis();
     inc();
   }      
   if(digitalRead(set_button)){
     delay(300);
     set();
     time_slot=1;
   }
}
