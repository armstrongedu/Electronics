int potPin = A0;    // Pin for the potentiometer
int led1Pin= D0;
int led2Pin= D3;
int led3Pin= D4;
int led4Pin= D5;
int led5Pin= D6;
int led6Pin= D7;
int led7Pin= D8;


void setup() 
{
  pinMode(potPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(led6Pin, OUTPUT);
  pinMode(led7Pin, OUTPUT);
}
void loop() 
{
  int potValue = analogRead(potPin);
  int numLedsOn = 0;
  
  if (potValue > 0 && potValue <= 128) {
    digitalWrite(led1Pin,LOW);
    digitalWrite(led2Pin,LOW);
    digitalWrite(led3Pin,LOW);
    digitalWrite(led4Pin,LOW);
    digitalWrite(led5Pin,LOW);
    digitalWrite(led6Pin,LOW);
    digitalWrite(led7Pin,LOW);
  } else if (potValue > 128 && potValue <= 256) {
    digitalWrite(led1Pin,HIGH);
  } else if (potValue > 256 && potValue <= 384) {
    digitalWrite(led2Pin,HIGH);
  } else if (potValue > 384 && potValue <= 512) {
    digitalWrite(led3Pin,HIGH);  
  } else if (potValue > 512 && potValue <= 640) {
    digitalWrite(led4Pin,HIGH);
  } else if (potValue > 640 && potValue <= 768) {
    digitalWrite(led5Pin,HIGH);
  } else if (potValue > 768 && potValue <= 896) {
    digitalWrite(led6Pin,HIGH);
  } else if (potValue > 896 && potValue <= 1024) {
    digitalWrite(led7Pin,HIGH);
  }
}