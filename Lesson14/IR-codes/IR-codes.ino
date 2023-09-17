#include <IRremote.h>
#define IRpin 5
int command = 0;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
IrReceiver.begin(IRpin, ENABLE_LED_FEEDBACK); 
}
void loop() {
if (IrReceiver.decode()) {
command = IrReceiver.decodedIRData.command;
IrReceiver.resume();
Serial.println(command);
}
}