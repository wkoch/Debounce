/*
  Debounce - v1.1 - November 19, 2014.
  Arduino library for button debouncing.
  Clearly based on the debounce example from the site:
  http://arduino.cc/en/Tutorial/Debounce
  Created by William Koch.
  Released into the public domain.
*/

#include "Debounce.h"

// Debounces an input pin.
// 50ms as default debounce delay.
Debounce::Debounce(byte button, boolean invert, boolean pullup)
{
  pinMode(button, pullup ? INPUT_PULLUP : INPUT);
  _button = button;
  _delay = 50; // default delay.
  _state = _lastState = _reading = (invert ^ digitalRead(_button));
  _last = millis();
  _count = 0;
  _invert = invert;
}

// Debounces an input pin.
// Adjustable debounce delay.
Debounce::Debounce(byte button, unsigned long delay, boolean invert, boolean pullup)
{
  pinMode(button, pullup ? INPUT_PULLUP : INPUT);
  _button = button;
  _delay = delay; // user defined delay.
  _state = _lastState = _reading = (invert ^ digitalRead(_button));
  _last = millis();
  _count = 0;
  _invert = invert;
}

byte Debounce::read()
{
  _reading = _invert ^ digitalRead(_button); // get current button state.
  if (_reading != _lastState)
  {                   // detect edge: current vs last state:
    _last = millis(); // store millis if change was detected.
    _wait = true;     // Just to avoid calling millis() unnecessarily.
  }

  if (_wait && (millis() - _last) > _delay)
  { // after the delay has passed:
    if (_reading != _state)
    {                    // if the change wasn't stored yet:
      _count++;          // Stores each change.
      _state = _reading; // store the button state change.
      _wait = false;
    }
  }
  _lastState = _reading;
  return _state;
}

// Returns the number of times the button was pressed.
unsigned int Debounce::count()
{
  Debounce::read();
  return _count / 2; // Counts only a full press + release.
}

void Debounce::resetCount()
{
  _count = 0;
  return;
}
