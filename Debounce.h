/*
  Debounce - v1.2 - May 12, 2021.
  MIT Licensed.
  https://github.com/wkoch/Debounce

  Arduino library for button debouncing.
  Clearly based on the debounce example from the site: http://arduino.cc/en/Tutorial/Debounce
  
  Created by William Koch, improved by the community.
*/

#ifndef Debounce_h
#define Debounce_h

#include "Arduino.h"

class Debounce
{
public:
  // Debounces an input with a 50ms debounce by default.
  // Optional parameters:
  //    - Adjust the delay in milliseconds.
  //    - Pull-Up input.
  // Button pin is required.
  Debounce(byte button, unsigned long delay = 50, boolean pullup = true);

  byte read();          // returns the debounced button state: LOW or HIGH.
  unsigned int count(); // Returns the number of times the button was pressed.
  void resetCount();    // Resets the button count number.

private:
  byte _button, _state, _lastState, _reading;
  unsigned int _count;
  unsigned long _delay, _last;
  boolean _wait;
  boolean _invert;
};

#endif
