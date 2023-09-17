 #define buzzer 0
 bool sound_detected(){
   int lower=1024,upper=0;
  for(int i=0;i<30;i++){
    int value=analogRead(A0);
    lower=min(lower,value);
    upper=max(upper,value);
    delay(1);
  }
 return upper-lower>20;
}
void setup() {
  // put your setup code here, to run once:
 pinMode(buzzer,OUTPUT);

 do{
   digitalWrite(buzzer,HIGH);
   }while(sound_detected());
   
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(buzzer,LOW);
 
}
