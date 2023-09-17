void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUILTIN_LED,OUTPUT);
}
bool sound_detected(){
   int lower=1024,upper=0;
  for(int i=0;i<50;i++){
    int value=analogRead(A0);
    lower=min(lower,value);
    upper=max(upper,value);
    delay(1);
  }
 return upper-lower>20;
}
void loop() {
  // put your main code here, to run repeatedly:
if(sound_detected()){
  digitalWrite(BUILTIN_LED,LOW);
  delay(300);
}
else{
  digitalWrite(BUILTIN_LED,HIGH);
  delay(300);
 }
}
