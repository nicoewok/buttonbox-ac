#include <Joystick.h>

//Buttons
#define button1 15
#define button2 9
#define switcher 10


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  5, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  // Initialize Button Pins
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP); 
  pinMode(switcher, INPUT_PULLUP); 
  Joystick.begin(false);
}


void loop() {
  //check if up
  if (digitalRead(switcher) == LOW) {
    if (digitalRead(button1) == LOW) {
      Joystick.pressButton(0);
    } else if (digitalRead(button2) == LOW) {
      Joystick.pressButton(1);
    }
  } else {
    if (digitalRead(button1) == LOW) {
      Joystick.pressButton(2);
    } else if (digitalRead(button2) == LOW) {
      Joystick.pressButton(3);
    }

  }

  Joystick.sendState();//send state 1st before we clear the button states
  ClearButtons();
  
  
  Serial.print("switcher state:");
  Serial.println(digitalRead(switcher));

  Serial.print("button1 state:");
  Serial.println(digitalRead(button1));

  Serial.print("button2 state:");
  Serial.println(digitalRead(button2));

  delay(1000);
}

void ClearButtons()
{
  Joystick.releaseButton(0);
  Joystick.releaseButton(1);
  Joystick.releaseButton(2);
  Joystick.releaseButton(3);
}