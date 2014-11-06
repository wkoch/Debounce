Debounce
=========

Really small library for Arduino button Debouncing. It's basically the Debounce example found on http://arduino.cc/en/Tutorial/Debounce wrapped as a library.

Really easy to use, with 3 examples included.

**Tested on an Arduino Due only.**

Instructions
============

Include the library in your sketch:

    #include <Debounce.h>

Create a Debounce object for your button:

    Debounce Button(4);

Don't forget to setup the button and led:

    void setup() {
      pinMode(4, INPUT);
      pinMode(13, OUTPUT);
    }

Inside your code, Button.read(); reads your button state and returns HIGH or LOW after debouncing it. When using INPUT for the button the pressed button will return HIGH, it'll return LOW for a pressed button when using INPUT_PULLUP.

This will turn the led on pin 13 ON when the button is pressed and debounced, it stays on until you release the button.

    void loop() {
      digitalWrite(13, Button.read());
    }
