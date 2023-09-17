int led1pin = D3; // Pin for LED 1:
int led2pin = D4; // Pin for LED 2
int potPin =A0; // Pin for the potentiometer

void setup() 
{
  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
 // No need to set up the potentiometer pin; it is an input by default
}
void loop()
{ 
  // Read the potentiometer value (e to 1023)
  int potValue=analogRead(potPin);
  //Map the potentiometer value to the LED brightness range (0 to 255)
  int brightness = map(potValue, 0, 1023, 0, 255);
  // Get the LED brightness using the PWM technique
  analogWrite(led1pin, brightness);
  analogWrite(led2pin, brightness);
}


