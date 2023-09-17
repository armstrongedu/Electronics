#include <IRremote.h> 
#define IRpin 5
int command=0;
void setup() {
// put your setup code here, to run once: 
IrReceiver.begin(IRpin, ENABLE_LED_FEEDBACK);
 Serial.begin(9600);
}
void loop() {
// put your main code here, to run repeatedly:
if (IrReceiver.decode()) {
command = IrReceiver.decodedIRData.command;
IrReceiver.resume();
if (command==69){ 
  Serial.println("1");}
else if(command==70) {
   Serial.println("2");
   }
else if (command==71){
Serial.println("3");
}
else if(command==68) {
   Serial.println("4");
} 
else if(command==64) {
Serial.println("5");
}
else if(command==67){ 
  Serial.println("6");
}
else if(command==7) {
   Serial.println("7");
}
else if(command==21){
  Serial.println("8");
  }
else if(command==9){
  Serial.println("9");
}
else if(command==22) {
  Serial.println("*"); 
  }
else if(command==25) {
  Serial.println("0");
} else if(command==13) {
  Serial.println("#");
}
else if(command==8) {
  Serial.println("left");
} 
else if(command==24) { 
  Serial.println("up");
}
else if (command==90) { 
  Serial.println("right");
} 
else if(command==82) {
Serial.println("down");
}
else if(command==28){
  Serial.println("ok");
}
 }
  }