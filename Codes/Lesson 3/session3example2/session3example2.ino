int buttonState = LOW;         // Current button state
int lastButtonState = LOW;     // Previous button state
int ledIndex = 1;         // Index of the active LED

void setup() {
  pinMode(D8, INPUT);
  pinMode(D0, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

void loop() {
  buttonState = digitalRead(D8);
  
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      digitalWrite(D0, LOW);
      digitalWrite(D3, LOW);
      digitalWrite(D4, LOW);
      
      if (ledIndex == 1) {
        digitalWrite(D0, HIGH);
      } else if (ledIndex == 2) {
        digitalWrite(D3, HIGH);
      } else if (ledIndex == 3) {
        digitalWrite(D4, HIGH);
      }
      
      ledIndex++;
      if (ledIndex > 3) {
        ledIndex = 1;
      }
    }
    lastButtonState = buttonState;
  }
}




