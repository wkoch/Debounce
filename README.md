# Debounce

Really small Arduino library for button Debouncing. It's basically the Debounce example found on http://arduino.cc/en/Tutorial/Debounce wrapped as a library.

Really easy to use, with 3 examples included.

**Tested on an Arduino Due only.**

## Instructions

Include the library in your sketch:

    #include <Debounce.h>

### Constructor

Use one of this two constructors, the default delay works great and is the recommended constructor.

#### Debounce Button With Default Delay

Create a Debounce object for your button, with a default delay of 50ms:

    Debounce Button(4); // 4 is the pin, could be a variable too.

#### Debounce Button With a Custom Delay

Create a Debounce object for yoiur button, with a custom delay:

    Debounce Button(4, 80); // 4 is the pin, 80 is the delay, in ms.

## Functions

Debounce has only 2 functions.

### read()

Inside your code, **Button.read();** reads your button state and returns HIGH or LOW after debouncing it. When using **INPUT**, the pressed button will return HIGH, it'll return LOW when pressed if you use **INPUT_PULLUP**.

This will turn the led on pin 13 ON when the button is pressed and debounced, it stays on until you release the button.

    void loop() {
      digitalWrite(13, Button.read());
    }

### count()

Returns the counter of changes ocurred, each time you press the button, it will add 1 to the counter, and it will also add 1 to the counter when you release the button.

This will turn the led only when the button has been pressed and released 5 times.

    if (Button.count() == 10) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
