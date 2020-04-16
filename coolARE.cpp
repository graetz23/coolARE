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

#include "./coolARE.h" // class header file

/**************************************80**************************************/

// Constructor
ARE::ARE( int pin_clk, int pin_ds, int pin_sw ) {
  _pin_clk = pin_clk;
  _pin_ds = pin_ds;
  _pin_sw = pin_sw;
} // ARE

// Destructor
ARE::~ARE( void ) {
} // ARE

void ARE::setup( void ) {
  pinMode( _pin_clk, INPUT );
  pinMode( _pin_ds, INPUT );
  if( _pin_sw != -1 )
    pinMode( _pin_sw, INPUT );
  _ds = digitalRead( _pin_clk ); // read ahead crossed ..
  _pos = 0; // init ahead
} // ARE::setup

/**************************************80**************************************/

int // reads the steps; .., -2, 1, 0, 1, 2, ..; inits by 0
ARE::read( ) {
  _clk = digitalRead( _pin_clk );
  if( _clk != _ds ) {
    if( digitalRead( _pin_ds ) != _clk ) {
      _direction = true; // clockwise
      _pos++;
    } else {
      _direction = false; // counter
      _pos--;
    } // if
  } // if
  _ds = _clk;
  return _pos;
} // ARE::read

bool // reads directions and returns 1 for clockwise and -1 for counterwise
ARE::direction( void ) {
  return _direction;
} // ARE::readButton

bool // reads button pressed or not; use pull up resistor (e.g. 4k7) on VCC
ARE::button( void ) {
  bool isPressed = false;
  if( _pin_sw != -1 )
    if(  digitalRead( _pin_sw ) == LOW )
      isPressed = true;
  return isPressed;
} // ARE::readButton

/**************************************80**************************************/
