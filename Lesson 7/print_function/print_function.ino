void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void print(){
  Serial.println("This is the code in the function");
}
void loop() {
  // put your main code here, to run repeatedly:
print();
Serial.println("This is code in Loop");
delay(1000);
}
