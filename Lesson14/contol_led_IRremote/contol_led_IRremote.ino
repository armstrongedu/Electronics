#include <IRremote.h>
# define IRpin 5 
# define led 16
int command=0; 
void setup() {
// put your setup code here, to run once: Serial.begin(9600);
IrReceiver.begin(IRpin, ENABLE_LED_FEEDBACK); 
pinMode(led, OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
if(IrReceiver.decode()){
command=IrReceiver.decodedIRData.command;
IrReceiver.resume();
if(command= 28){
digitalWrite(led,HIGH);
delay(1000);
digitalWrite(led, LOW);
}
delay(1000);
}
}