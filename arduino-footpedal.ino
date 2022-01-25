#include "Keyboard.h"

const int BUTTON_PIN_LEFT = 7;
const int BUTTON_PIN_RIGHT = 4;

int previousButtonStateLeft = LOW;
int previousButtonStateRight = LOW;

void setup() {
  pinMode(BUTTON_PIN_LEFT, INPUT);
  pinMode(BUTTON_PIN_RIGHT, INPUT);
  Keyboard.begin();
}

void loop() {
  int buttonStateLeft = digitalRead(BUTTON_PIN_LEFT);
  if ((buttonStateLeft != previousButtonStateLeft) && (buttonStateLeft == HIGH)) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_F12);
    Keyboard.releaseAll();
    Serial.println("Left");
    delay(200);
  }
  previousButtonStateLeft = buttonStateLeft;

  int buttonStateRight = digitalRead(BUTTON_PIN_RIGHT);
  if ((buttonStateRight != previousButtonStateRight) && (buttonStateRight == HIGH)) {
    Keyboard.press(KEY_ESC);
    Keyboard.releaseAll();
    Serial.println("Right");
    delay(200);
  }
  previousButtonStateRight = buttonStateRight;

}
