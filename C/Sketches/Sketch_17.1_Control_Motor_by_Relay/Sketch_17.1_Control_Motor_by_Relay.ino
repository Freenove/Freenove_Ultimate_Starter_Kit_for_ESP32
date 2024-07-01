/**********************************************************************
  Filename    : Control Motor by Relay
  Description : Use relay to control motor.
  Auther      : www.freenove.com
  Modification: 2024/06/19
**********************************************************************/
int relayPin = 13;          // the number of the relay pin
int buttonPin = 15;         // the number of the push button pin

int buttonState = HIGH;     // Record button state, and initial the state to high level
int relayState = LOW;       // Record relay state, and initial the state to low level
int lastButtonState = HIGH; // Record the button state of last detection
long lastChangeTime = 0;    // Record the time point for button state change

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);           // Set push button pin into input mode
  pinMode(relayPin, OUTPUT);                  // Set relay pin into output mode
  digitalWrite(relayPin, relayState);         // Set the initial state of relay into "off"
}
void loop() {
  int nowButtonState = digitalRead(buttonPin);// Read current state of button pin
  // If button pin state has changed, record the time point
  if (nowButtonState != lastButtonState) {
    lastChangeTime = millis();
  }
  // If button state changes, and stays stable for a while, then it should have skipped the bounce area
  if (millis() - lastChangeTime > 10) {
    if (buttonState != nowButtonState) {    // Confirm button state has changed
      buttonState = nowButtonState;
      if (buttonState == LOW) {             // Low level indicates the button is pressed
        relayState = !relayState;           // Reverse relay state
        digitalWrite(relayPin, relayState); // Update relay state
      }
    }
  }
  lastButtonState = nowButtonState; // Save the state of last button
}
