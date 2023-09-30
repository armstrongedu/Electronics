int buzzer_pin=0;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzer_pin,OUTPUT);
}
void play_tone(){
  digitalWrite(buzzer_pin,HIGH);
  delay(300);
  digitalWrite(buzzer_pin,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
delay(3000);
play_tone();
}
