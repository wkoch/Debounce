#include <Debounce.h>

// A debounced button that turns a Led on and another off.
// Led1 turns on when the button1 is pressed.
// Led2 turns on when the button1 is not pressed.
// This behaviour will invert if you use INPUT for the button.

byte button1 = 22;
byte led1 = 23;
byte led2 = 25;
Debounce Button1(button1); // A debounced button.

void setup() {
  pinMode(button1, INPUT_PULLUP); // Watch for the PULLUP
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, !Button1.read()); // Negated value, because of the PULLUP:
  digitalWrite(led2, Button1.read()); // Direct value gives inverted results.
}
