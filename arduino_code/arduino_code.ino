#include <Joystick.h>


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  15, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering



void setup() {
  //Initialize pins

  //Rows as output
  //Rows are pins 14, 15 and 16
  for (int i = 14; i < 17; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i,HIGH);
  }
  //Cols as input to read potential resistance
  //Cols are pins 5, 6, 7, 8 and 9
  for (int i = 5; i < 10; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  Joystick.begin();
}

//To check which buttons are pressed already
bool active[3][5] = {{false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}};

void loop() {

  //Row-wise outputs
  for (int i = 14; i < 17; i++) {
    digitalWrite(i,LOW);
    //Col-wise reading
    for (int j = 5; j < 10; j++) {
      //Press if not already active
      if (digitalRead(j) == LOW) {
          if (!active[i][j]) {
            active[i][j] = true;
            Joystick.pressButton((i-14)*5 + (j-5)); //Buttons are values 0-14 so map occording to rows and cols
          }
          
      } else { //deactivate and release
        active[i][j] = false;
        Joystick.releaseButton((i-14)*5 + (j-5));
      }
    }
    digitalWrite(i,HIGH);
  }

  Joystick.sendState();


  delay(100);
}