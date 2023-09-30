
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define buzzer 0
#include "rfid.h"

bool reset_password(){


  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! card_detected()) {
    return false;
  }

  // Select one of the cards

  
Serial.println(card_UID());

  byte buffer[18];
  byte block;

  Serial.println(F("Type password, ending with #"));
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Create password");
  lcd.setCursor(0,1);
  lcd.print("ending with #");
  read_buffer(buffer,18);

delay(10);
if(!write_block(4,buffer,16)){
  return false;
}

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("saved!");
  success();

  Serial.println(" ");
  end_loop();
  delay(100);
  return true;
}
bool enter_password(){


  //-------------------------------------------

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! card_detected()) {
    return false;
  }

  Serial.println(F("**Card Detected:**"));

  //-------------------------------------------

  print_card_info();

  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));      //uncomment this to see all blocks in hex

  //-------------------------------------------
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter pass");
  lcd.setCursor(0,1);
  lcd.print("ending with #");
 int cursor=0;
  byte buffer[18];
  
delay(10);
if(!read_block(4,buffer,18)){
  return false;
}


 byte pass[18];
read_buffer(pass,18);


    bool correct=true;
    for (uint8_t i = 0; i < 16; i++) {
    if(buffer[i]!=32){
    if((char)buffer[i]!=(char)pass[i]){
    correct=false;
    }
   }
   
  }
  while(!correct){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("wrong pass");
    lcd.setCursor(0,1);
    lcd.print("try again");
   failure();
  byte pass_backup[18];

 read_buffer(pass_backup,18);
     correct=true;
    for (uint8_t i = 0; i < 16; i++) {
    if(buffer[i]!=32){
    if((char)buffer[i]!=(char)pass_backup[i]){
    correct=false;
    }
   }
  }
  
 }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("correct!");
  success();

  //----------------------------------------

  Serial.println(F("\n**End Reading**\n"));

  delay(100); //change value if you want to read cards faster
  
  end_loop();
  return true;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  pinMode(buzzer,OUTPUT); 
rfid_init();     
 lcd.init(); 
 lcd.clear();
 lcd.backlight();
lcd.setCursor(0,0);
lcd.print("1-Reset password");
lcd.setCursor(0,1);
lcd.print("2-Enter password");
while(!Serial.available()){}
delay(3);
char c=Serial.read();
while(c!='1'&&c!='2'){
while(!Serial.available()){}
delay(3);
 c=Serial.read(); 
 }
 if(c=='1'){
 while(!reset_password()){};
 }
 if(c=='2'){
 while(!enter_password()){};
 }
}
void loop() {
  // put your main code here, to run repeatedly:


}
