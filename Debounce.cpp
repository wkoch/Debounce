/*
  Debounce.cpp - v1.0
  Library for button debouncing.
  Clearly based on the debounce example from the site:
  http://arduino.cc/en/Tutorial/Debounce
  Created by William Koch, November 06, 2014.
  Released into the public domain.
*/

#include "Debounce.h"

// Debounces an input pin.
// 50ms as default debounce delay.
Debounce::Debounce(byte button) {
  _button = button;
  _delay = 50; // default delay.
  _state = _lastState = _reading = digitalRead(_button);
}

// Debounces an input pin.
// Adjustable debounce delay.
Debounce::Debounce(byte button, unsigned long delay) {
  _button = button;
  _delay = delay; // user defined delay.
  _state = _lastState = _reading = digitalRead(_button);
}

byte Debounce::read() {
  _reading = digitalRead(_button); // get current button state.
  if (_reading != _lastState) { // detect edge: current state vs last state:
    _last = millis(); // store millis if change was detected.
  }

  if ((millis() - _last) > _delay) { // after the delay has passed:
    if (_reading != _state) { // if the change wasn't stored yet:
      _state = _reading; // store the button state change.
    }
  }
  if (_state == _reading) { // while state is stable:
    return _state; // return the state value: LOW or HIGH as byte.
  }
}
