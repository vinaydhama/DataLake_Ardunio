/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Updated by Jason A. Cox, February 18, 2023.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DataLakeIRHelper.h"

Morse::DataLakeIRHelper(int pin)
{
  _pin = pin;
}