#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define buzzer 0
#include "rfid.h"

//**//
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  rfid_init();
  lcd.init();
  lcd.backlight();
  lcd.clear(); 
   while(!Serial){};
  Serial.println("Add card to read personal data from");
  lcd.setCursor(0,0);
  lcd.print("put a card");
}

//**//
void loop() {



  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
if(!card_detected()){
  return;
}
  Serial.println("Card Detected:");



 Serial.println(card_UID());

  //-------------------------------------------



  byte buffer1[18];
  String buffer=" ";



  //------------------------------------------- GET FIRST NAME

  delay(10);
  if(!read_block(2,buffer1,18)){
    return;
  }
  for (uint8_t i = 0; i < 16; i++)
  {
    if (buffer1[i] != 32)
    {
      buffer.concat((char)buffer1[i]);
    }
  }

 Serial.print(" ");
 buffer.concat(' ');
  //PRINT FIRST NAME

 

  //---------------------------------------- GET LAST NAME

  byte buffer2[18];

  delay(10);
  if(!read_block(1,buffer2,18)){
    return;
  }
   for (uint8_t i = 0; i < 16; i++)
  {
    if (buffer2[i] != 32)
    {
      buffer.concat((char)buffer2[i]);
    }
  }


  Serial.println();

  //----------------------------------------
  buffer.trim();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("welcome");
  lcd.setCursor(0,1);
  lcd.print(buffer);
  Serial.println("Name: ");
  Serial.println(buffer);
  welcome();
  Serial.println("\nEnd Reading\n");

  delay(800); //change value if you want to read cards faster

  end_loop();
}