#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
#include "KeyChar.h"
#define buzzer D3
LiquidCrystal_I2C lcd(0x27,16,2);
#include "password.h"
void setup() {
  // put your setup code here, to run once:
EEPROM.begin(4);
lcd.init();
lcd.backlight();
pinMode(buzzer,OUTPUT);
initialize_door_lock_system();
}
void loop() {

}
