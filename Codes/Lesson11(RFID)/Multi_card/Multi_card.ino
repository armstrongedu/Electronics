#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
#define buzzer D3
#include "rfid.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600); 
  EEPROM.begin(512);  
  pinMode(buzzer,OUTPUT);                                       
  rfid_init();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("add card");
  reset_EEPROM();
}
void reset_EEPROM(){
  for(int i=0;i<511;i++){
    EEPROM.write(i,'0');
    EEPROM.commit();
  }
  EEPROM.write(511,0x00);
}

void Add_card(byte* buf){
  byte card_no=EEPROM.read(511);
  bool found=false;
  for(int i=0;i<4*card_no;i+=4){
    byte uid[4];
    EEPROM.get(i,uid);
    bool equal=true;
    for(int j=0;j<4;j++){
      if(buf[j]!=uid[j]) equal=false;
    }
    found=found||equal;
  }
  if(!found){
  for(int i=0;i<4;i++){
    EEPROM.write(card_no*4+i,buf[i]);
  }
  EEPROM.commit();
  byte added[4];
  EEPROM.get(card_no*4,added);
  dump_byte_array(added,4);
  Serial.println();
  card_no++;
  EEPROM.write(511,card_no);
  EEPROM.commit();
  Serial.println("just added!");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("just added!");
  just_added();
  return;
 }
 else{
   Serial.println("already found!");
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("already found!");
   already_found();
   return;}
}

void loop() {

	if(!card_detected()){
  return;
}
lcd.clear();
lcd.setCursor(0,0);
lcd.print(card_UID());
Serial.println(card_UID());
Serial.println();
delay(1000);
Add_card(mfrc522.uid.uidByte);
delay(500);

}