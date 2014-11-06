#include <Debounce.h>

// A debounced button that turns a Led on.
// Led turns on when the button is pressed.
// Led turns off when the button is not pressed.
// This behaviour will invert if you use INPUT for the button.

byte button1 = 22;
byte led1 = 23;
Debounce Button1(button1, 10); // A debounced button.

void setup() {
  pinMode(button1, INPUT_PULLUP); // Watch for the PULLUP
  pinMode(led1, OUTPUT);
}

void loop() {
  digitalWrite(led1, !Button1.read()); // Negated value because of the PULLUP.
}
