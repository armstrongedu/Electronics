#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
EEPROM.begin(4);
Serial.begin(9600);
int value=1234;
EEPROM.put(0,value);
EEPROM.commit();
}

void loop() {
  // put your main code here, to run repeatedly:
int answer;
EEPROM.get(0,answer);
Serial.println(answer);
delay(100);
}
