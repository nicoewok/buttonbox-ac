#include <Joystick.h>

//Defining row/column pins on your board
#define ROW1 15
#define ROW2 14
#define ROW3 16
#define COL1 6
#define COL2 5
#define COL3 7
#define COL4 4
#define COL5 8


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  13, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  //Initialize pins
  for (int i = 14; i < 17; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i,HIGH);
  }
  for (int i = 5; i < 10; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  Joystick.begin();
}

int rows[] = {ROW1,ROW2,ROW3};
int cols[] = {COL1, COL2, COL3, COL4, COL5 };

void loop() {
  /*Buttons are in following order according to wiring diagramm:
    u1 | d1 | u2 | d2 | u3 | d3 | u4 | d4 | b1 | b2 | u5 | d5 | b3
     0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12
  */
  //Row-wise checking
  for (int i = 0; i < 50; i++)
    Serial.println();
  for (int i = 14; i < 17; i++) {
    digitalWrite(i,LOW);
    for (int j = 5; j < 10; j++) {
      Serial.print("row:"); Serial.print(i); Serial.print(" col:");Serial.print(j); Serial.print(digitalRead(j)); 
      if (digitalRead(j) == LOW) {
        Serial.print("pressed");
        //Jostick.pressButton(btns[i][j]);
      }
      Serial.println();
    }
    digitalWrite(i,HIGH);
  }
/*


  }
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

  Serial.print("ROW1: "); Serial.println(digitalRead(ROW1));
  Serial.print("ROW2: "); Serial.println(digitalRead(ROW2));
  Serial.print("ROW3: "); Serial.println(digitalRead(ROW3));
  Serial.print("COL1: "); Serial.println(digitalRead(COL1));
  Serial.print("COL2: "); Serial.println(digitalRead(COL2));
  Serial.print("COL3: "); Serial.println(digitalRead(COL3));
  Serial.print("COL4: "); Serial.println(digitalRead(COL4));
  Serial.print("SPIN: "); Serial.println(digitalRead(SPIN));
  Serial.print("\n\n\n");
*/

  //send state then clear buttons again
  Joystick.sendState();
  ClearButtons();

  delay(100);
}

void ClearButtons() {
  for (int i = 0; i < 13; ++i) {
    Joystick.releaseButton(i);
  }
}