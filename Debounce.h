/*
  Debounce.cpp - v1.0
  Library for button debouncing.
  Clearly based on the debounce example from the site:
  http://arduino.cc/en/Tutorial/Debounce
  Created by William Koch, November 06, 2014.
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
  private:
    byte _button, _state, _lastState, _reading;
    unsigned long _delay, _last;
    boolean _active;
};

#endif
