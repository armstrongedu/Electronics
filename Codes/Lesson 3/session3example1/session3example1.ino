
int buttonState = 0;      // Variable to store the button state
int lastButtonState = 0;  // Variable to store the previous button state
int ledState = LOW;       // Initial LED state

void setup() {
  pinMode(D8,INPUT);   // Pin for the button
  pinMode(D3, OUTPUT);  // Pin for the LED
}

void loop() {
  buttonState = digitalRead(D8);  // Read the current button state
  
  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) 
    {
      if (ledState==LOW)
      {
        ledState=HIGH;
        digitalWrite(D3, ledState);
      }
      else 
      {
        ledState=LOW;
        digitalWrite(D3, ledState);
      }
    }
  }
  
  // Store the current button state for comparison
  lastButtonState = buttonState;
}
