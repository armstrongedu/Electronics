#include "colors.h"
void new_password();
void Enter_password();
void reset_password();
bool check_password();
bool create_password();
void initialize_door_lock_system();
void wrong();
void correct();
void new_password(){
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("create 4-digits");
  lcd.setCursor(0,1);
  lcd.print("password#");
  while(!create_password()){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("wrong format!");
    wrong();
  }
}
void Enter_password(){
lcd.clear();  
lcd.setCursor(0,0);
lcd.print("Enter password");
while(!check_password()){
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("wrong password");
  lcd.setCursor(0,1);
  lcd.print("try again");
  wrong();
}
lcd.clear();  
lcd.setCursor(0,0);
lcd.print("correct!");
correct();
}
void reset_password(){
EEPROM.put(0,0);
}
void correct(){
show_levels(13,0,255,0);
digitalWrite(buzzer,HIGH);
delay(1000);
digitalWrite(buzzer,LOW);
clear_face();

}
void wrong(){
show_levels(13,255,0,0);
for(int i=0;i<3;i++){  
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(100);
  }
delay(500);
clear_face();
}
bool check_password(){
  int password;
  EEPROM.get(0,password);
  //Serial.println(password);
  String temp="";
 while(temp.length()<4){
     char c=getKey();
     if(c!='?'){
       temp+=c;
      Serial.print(c);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(temp);
      delay(300);
     }
     delay(10);
 }
 Serial.println();
 for(int i=0;i<4;i++){
  int digit=temp.charAt(i)-'0';
  if(digit<0||digit>9){
    return false;
   }
 }
 return password==temp.toInt();
}
bool create_password(){
 String temp="";

 while(temp.length()<5){
    char c=getKey();
    if(c!='?'){
        temp+=c;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(temp);
        Serial.print(c);
        delay(300);
    }
    delay(10);
 }
  Serial.println();
 if(temp.charAt(4)!='#'){
  return false;
 }
for(int i=0;i<4;i++){
  int digit=temp.charAt(i)-'0';
  if(digit<0||digit>9){
    return false;
   }
 }
 int password=temp.substring(0,4).toInt();
 EEPROM.put(0,password);
 EEPROM.put(4,'1');
 EEPROM.commit();
 lcd.clear();  
 lcd.setCursor(0,0);
 Serial.println("saved!");
 lcd.print("saved!");
 correct();
 return true;
}
void initialize_door_lock_system(){
set();
lcd.setCursor(0,0);
lcd.print("1-new password");
lcd.setCursor(0,1);
lcd.print("2-Enter password");
char c=getKey();
while(c!='1'&&c!='2'){
  c=getKey();
  delay(100);
}
delay(500);
if(c=='1'){
new_password();
}
else{
Enter_password();
  }
}