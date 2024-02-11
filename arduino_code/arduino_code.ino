#include <Joystick.h>

//Buttons
#define button1 4
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
  Joystick.begin(false);
}


void loop() {
  //check if up

  Joystick.sendState();//send state 1st before we clear the button states
  ClearButtons();
  

  Serial.print("button1 state:");
  Serial.println(digitalRead(button1));

  delay(1000);
}

void ClearButtons()
{
  Joystick.releaseButton(0);
  Joystick.releaseButton(1);
  Joystick.releaseButton(2);
  Joystick.releaseButton(3);
}