#include <Joystick.h>

#define PINS 14

// Joystick_ Joystick(0x03, 0x04, 4, false, false, false, false, true, true, false, false, true, false, false, false );
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
  1, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  true, true,          // rudder or throttle AKA 2nd Joystick
  false, false, false);  // No accelerator, brake, or steering

class CButton {
  public:
  int pin = NULL;
  int lastState = 0;
  
  CButton(int p) {
    pin = p;
  }
};

CButton Buttons[PINS] ={0,1,2,3,4,5,6,7,8,9,10,16,14,15};

void setup() {
  Joystick.begin();

  for(int i=0 ; i<PINS ;i++) {
    pinMode(Buttons[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  Joystick.setXAxis(analogRead(A0));
  Joystick.setYAxis(analogRead(A1));
  Joystick.setThrottle(analogRead(A2));
  Joystick.setRudder(analogRead(A3));

  for (int i = 0; i < PINS; i++) {
    int currentState = !digitalRead(Buttons[i].pin);
    
    if (currentState != Buttons[i].lastState) {
      Joystick.setButton(i, currentState);
      Buttons[i].lastState = currentState;
    }
  }  

  delay(10);
}