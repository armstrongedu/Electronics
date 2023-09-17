
int pins[5]={D3,D4,D5,D6,D7};

void setup()
{
for(int i=0;i<5;i++){
  pinMode(pins[i],OUTPUT);
  }
}
void loop()
{
for(int i=0;i<5;i++){
    digitalWrite(pins[i], HIGH); 
    delay (500); 
    digitalWrite(pins[i],LOW); 
    delay (500);
  }
}