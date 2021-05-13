#include <Debounce.h>

// A debounced button that turns a Led...
// ...On when pressed once, and Off when pressed the second time.
// Also works with INPUT_PULLUP.

byte button = 10;
byte led = LED_BUILTIN;
Debounce Button(button); // A debounced button that will keep working.
// Use it like this to use INPUT_PULLUP:
  // Debounce Button(button, 50, true);

void setup() {
  pinMode(button, INPUT); // Also works with INPUT_PULLUP
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, Button.count() % 2); // Press and release to switch On, repeat to Switch Off.
}
