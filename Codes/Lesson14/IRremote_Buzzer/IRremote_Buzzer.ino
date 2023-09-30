#include <IRremote.h>
#define IRpin 5 
#define buzzer_pin 0
int command=0;
void setup() {
// put your setup code here, to run once:
IrReceiver.begin(IRpin, ENABLE_LED_FEEDBACK); 
pinMode(buzzer_pin,OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
if(IrReceiver.decode()){
command = IrReceiver.decodedIRData.command; 
IrReceiver.resume();
if(command==28){
digitalWrite(buzzer_pin,HIGH);
 delay(500);
digitalWrite(buzzer_pin, LOW);
}
delay(1000);
 }
}