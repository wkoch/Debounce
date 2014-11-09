#include <Debounce.h>

// Two debounced buttons that turns two Led on and off.
// Button1 turns Led1 on when pressed.
// Button2 turns Led2 off when pressed.
// This behaviour will invert if you use INPUT for the button.

byte button1 = 22;
byte button2 = 24;
byte led1 = 23;
byte led2 = 25;
Debounce Button1(button1); // Button1 debounced, default 50ms delay.
Debounce Button2(button2, 70); // Button2 debounced, custom 70ms delay.

void setup() {
  pinMode(button1, INPUT_PULLUP); // Watch for the PULLUP
  pinMode(button2, INPUT_PULLUP); // Watch for the PULLUP
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, !Button1.read()); // Negated value because of the PULLUP.
  digitalWrite(led2, Button2.count() % 2);// On/Off each press.
}
