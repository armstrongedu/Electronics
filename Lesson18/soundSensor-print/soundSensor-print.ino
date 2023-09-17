void setup() {

 Serial.begin(9600);
 
}
bool sound_detected(){
int lower=1024,upper=0;
for (int i=0;i<30;i++){
int value=analogRead(A0);
lower=min (lower, value);
upper=max(upper, value);
delay(1);
   }
return upper-lower>20; 
 }  
void loop() {
// put your main code here, to run repeatedly:
if(sound_detected()) { 
  Serial.println("detected!"); 
  }
delay(300);
}
