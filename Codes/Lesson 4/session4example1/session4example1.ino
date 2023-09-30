void setup()
{
pinMode (D0, OUTPUT);
pinMode (D3, OUTPUT);
}
void loop()
{
for (int i=0;i<5;i++) 
{  
   digitalWrite(D0, HIGH); 
   delay (500); 
   digitalWrite(D0, LOW);
   delay(500);
}
for (int i=0;i<5;i++) 
{  
   digitalWrite(D3, HIGH);
   delay (500);
   digitalWrite(D3, LOW);
   delay (500);
}
}