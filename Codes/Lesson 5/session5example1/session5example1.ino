#define potentiometerPin A0 
void setup()
{
  Serial.begin(9600);
}
void loop()
{
   int analogValue=analogRead(potentiometerPin);
   Serial.print("Analog Reading: ");
   Serial.println(analogValue);
   delay(100);
}

