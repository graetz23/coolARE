/**
 * coolARE - cool arduino rotary encoder library for type KY-040 with button.
 *
 * coolARE is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2020 Christian (graetz23@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * Christian
 * graetz23@gmail.com
 * created 20200416
 * version 20200416
 *
 */

/**************************************80**************************************/

#ifndef __coolARE_h__
#define __coolARE_h__

/**************************************80**************************************/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/**************************************80**************************************/

class ARE {

 public:

  ARE( int pin_clk, int pin_ds, int pin_sw = -1 ); // constructor
  virtual ~ARE( void ); // destructor

  void setup( void ); // setup PINS; calls this method in arudino's setup method

  int read( void ); // reads the steps; .., -2, 1, 0, 1, 2, ..; inits by 0

  bool direction( void ); // reads directions and returns 1 for clockwise and -1 for counterwise

  bool button( void ); // reads button pressed or not; use pull up resistor (e.g. 4k7) on VCC

 private:

  int _clk;    // switch between A to C
  int _ds;     // switch between B to C
  boolean _sw; // state of the button

  int _pin_clk; // pin number for clk wire
  int _pin_ds;  // pin number for ds wire
  int _pin_sw;  // pin number for button wire

  int _pos = 0; // internal position; .., -2, 1, 0, 1, 2, ..
  boolean _direction; // TRUE clockwise and FALSE counterwise

}; // ARE

#endif // __coolARE_h__
