void setup() 
{
pinMode(D7,OUTPUT);
pinMode(D8,INPUT);
}
void loop(){
if (digitalRead(D8)== HIGH) 
{
  digitalWrite(D7, HIGH);
} 
else
{
  digitalWrite(D7,LOW);
}
}