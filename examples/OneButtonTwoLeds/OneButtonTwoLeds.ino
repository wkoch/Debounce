#include <Debounce.h>

// A debounced button that turns a Led on and another off.
// Uses INPUT_PULLUP for the pin and button.
// Led1 turns on when the button1 is pressed.
// Led2 turns on when the button1 is not pressed.

byte button1 = 10;
byte led1 = 12;
byte led2 = LED_BUILTIN;
Debounce Button1(button1, 50, true); // true = Inverted reading to adjust to INPUT_PULLUP.

void setup() {
  pinMode(button1, INPUT_PULLUP); // Also works with INPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, Button1.read());
  digitalWrite(led2, !Button1.read()); // Negated to be the inverse of the first Led.
}
