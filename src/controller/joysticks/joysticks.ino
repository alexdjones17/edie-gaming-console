#include <Joystick.h>

// Joystick_ Joystick(0x03, 0x04, 4, false, false, false, false, true, true, false, false, true, false, false, false );
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
  1, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  true, true,          // rudder or throttle AKA 2nd Joystick
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  Joystick.begin();
}

void loop() {
  Joystick.setXAxis(analogRead(A0));
  Joystick.setYAxis(analogRead(A1));
  Joystick.setThrottle(analogRead(A2));
  Joystick.setRudder(analogRead(A3));
  delay(10);
}