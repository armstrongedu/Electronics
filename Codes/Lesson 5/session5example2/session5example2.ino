#define potentiometerPin A0
void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  int analogvalue=analogRead(potentiometerPin); 
  Serial.print("Analog Reading: "); 
  Serial.println(analogvalue);
  if(analogvalue<350)
  {
      Serial.println("State: LOW");
  }
  else if(analogvalue<800)
  {
      Serial.println("State: MEDIUM");
  }
  else
  {
      Serial.println("State: HIGH");
  }
      delay(100);
}
