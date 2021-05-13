#include <Debounce.h>

// Two debounced buttons that turns two Leds on and off.
// Button1 turns Led1 On when pressed.
// Button2 turns Led2 Off when pressed.

byte button1 = 10;
byte button2 = 11;
byte led1 = 12;
byte led2 = 13;
Debounce Button1(button1); // Button1 debounced, with default 50ms debounce time.
Debounce Button2(button2, 70); // Button2 debounced, with custom debounce time.

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT); // Also works with INPUT_PULLUP
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, Button1.read());
  digitalWrite(led2, !Button2.read());
}
