/*
  Debounce - v1.1 - November 19, 2014.
  Arduino library for button debouncing.
  Clearly based on the debounce example from the site:
  http://arduino.cc/en/Tutorial/Debounce
  Created by William Koch.
  Released into the public domain.
*/

#ifndef Debounce_h
#define Debounce_h

#include "Arduino.h"

class Debounce {
  public:
    // Debounces an input pin.
    // 50ms as default debounce delay.
    Debounce(byte button);

    // Debounces an input pin.
    // Adjustable debounce delay.
    Debounce(byte button, unsigned long delay);

    byte read(); // returns the debounced button state: LOW or HIGH.
    unsigned int count(); // Returns the number of times the button was pressed.
  private:
    byte _button, _state, _lastState, _reading;
    unsigned int _count;
    unsigned long _delay, _last;
    boolean _wait;
};

#endif
