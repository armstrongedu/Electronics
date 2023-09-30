#include <IRremote.h>
#define IRpin 5
#define led1 16
#define led2 0
#define led3 2
#define led4 14
#define led5 12
#define led6 13
#define led7 15
int command=0;
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IrReceiver.begin(IRpin,ENABLE_LED_FEEDBACK);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 if(IrReceiver.decode()){
      command = IrReceiver.decodedIRData.command;
      IrReceiver.resume();
 if(command==69){
        digitalWrite(led1,HIGH);
        delay(1000);
        digitalWrite(led1,LOW);
 }
 else if(command==70){
        digitalWrite(led2,HIGH);
        delay(1000);
        digitalWrite(led2,LOW);
 }
 else if(command==71){
        digitalWrite(led3,HIGH);
        delay(1000);
        digitalWrite(led3,LOW);
 }
 else if(command==68){
        digitalWrite(led4,HIGH);
        delay(1000);
        digitalWrite(led4,LOW);
 }
 else if(command==64){
        digitalWrite(led5,HIGH);
        delay(1000);
        digitalWrite(led5,LOW);
 }
 else if(command==67){
        digitalWrite(led6,HIGH);
        delay(1000);
        digitalWrite(led6,LOW);
 }
 else if(command==7){
        digitalWrite(led7,HIGH);
        delay(1000);
        digitalWrite(led7,LOW);
 }
 delay(2000);
 }
 else{
 command=0;
  }  
   
}
