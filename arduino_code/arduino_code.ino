#include <Joystick.h>

//Defining row/column pins on your board
#define ROW1 1
#define ROW2 1
#define ROW3 1
#define COL1 1
#define COL2 1
#define COL3 1
#define COL4 1
#define SPIN 1


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  13, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  //Initialize pins
  pinMode(ROW1, INPUT_PULLUP);
  pinMode(ROW2, INPUT_PULLUP);
  pinMode(ROW3, INPUT_PULLUP);
  pinMode(COL1, INPUT_PULLUP);
  pinMode(COL2, INPUT_PULLUP);
  pinMode(COL3, INPUT_PULLUP);
  pinMode(COL4, INPUT_PULLUP);
  pinMode(SPIN, INPUT_PULLUP);
  Joystick.begin(false);
}


void loop() {
  /*Buttons are in following order according to wiring diagramm:
    u1 | d1 | u2 | d2 | u3 | d3 | u4 | d4 | b1 | b2 | u5 | d5 | b3
     0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12
  */
  //Row-wise checking
  if (digitalRead(ROW1) == LOW) {
    if (digitalRead(COL1) == LOW) {
      Joystick.pressButton(0);
    } else if (digitalRead(COL2) == LOW) {
      Joystick.pressButton(2);
    } else if (digitalRead(COL3) == LOW) {
      Joystick.pressButton(4);
    } else if (digitalRead(COL4) == LOW) {
      Joystick.pressButton(6);
    }
  } else if (digitalRead(ROW2) == LOW) {
    if (digitalRead(COL1) == LOW) {
      Joystick.pressButton(1);
    } else if (digitalRead(COL2) == LOW) {
      Joystick.pressButton(3);
    } else if (digitalRead(COL3) == LOW) {
      Joystick.pressButton(5);
    } else if (digitalRead(COL4) == LOW) {
      Joystick.pressButton(7);
    }
  } else if (digitalRead(ROW3) == LOW) {
    if (digitalRead(COL1) == LOW) {
      Joystick.pressButton(9);
    } else if (digitalRead(COL2) == LOW) {
      //not possible
    } else if (digitalRead(COL3) == LOW) {
      Joystick.pressButton(10);
    } else if (digitalRead(COL4) == LOW) {
      Joystick.pressButton(12);
    }
  }
  //checking special pin
  else if (digitalRead(SPIN) == LOW) {
    if (digitalRead(ROW2) == LOW) {
      Joystick.pressButton(8);
    } else if (digitalRead(COL3) == LOW) {
      Joystick.pressButton(11);
    }
  }

  //send state then clear buttons again
  Joystick.sendState();
  ClearButtons();

  delay(1000);
}

void ClearButtons() {
  for (int i = 0; i < 13; ++i) {
    Joystick.releaseButton(i);
  }
}