# Debounce

Really small Arduino library for button Debouncing. It's basically the Debounce example found on http://arduino.cc/en/Tutorial/Debounce wrapped as a library.

Really easy to use, with examples included.

**Tested on an Arduino Due only.**

## Instructions

Include the library in your sketch:

    #include <Debounce.h>

### Constructor

Use one of this constructors, the default delay works great and is the recommended constructor.

#### Debounce Button With Default Delay

Create a Debounce object for your button, with a default delay of 50ms:

    Debounce Button(4); // 4 is the pin, could be a variable too.

#### Debounce Button With a Custom Delay

Create a Debounce object for your button, with a custom delay:

    Debounce Button(4, 80); // 4 is the pin, 80 is the delay, in ms.

#### Debounce Button With a Custom Delay and INPUT_PULLUP

Create a Debounce object for your button, with a custom delay and INPUT_PULLUP:

    Debounce Button(4, 80, true); // 4 is the pin, 80 is the delay in ms, true for INPUT_PULLUP.

**Note**: This constructor will change the button input pin to INPUT_PULLUP.

## Functions

Debounce has only a few easy to use functions.

### read()

Inside your code, **Button.read();** reads your button state and returns HIGH or LOW after debouncing it. It should always return HIGH when the button is pressed, and LOW otherwise.

This will turn the led on pin 13 ON when the button is pressed and debounced, it stays on until you release the button.

    void loop() {
      digitalWrite(13, Button.read());
    }

### count()

Returns the counter of changes ocurred to the button. The counter will increase by 1 each time you press the button for longer than the debounce time. It will also increase by 1 when you release the button after it was debounced.

This will turn the led only when the button has been pressed and released 5 times. Turns Off after another 5 press-and-releases.

    if (Button.count() == 10) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
    
### resetCount()

Resets the counter for the button changes.
