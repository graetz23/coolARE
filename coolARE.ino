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

#include "./coolARE.h" // ARE object

// ARE are( 9, 8 ); // baking object with pins clk = 9, and ds = 8; no button
ARE are( 9, 8, 7 ); // baking object with pins clk = 9, ds = 8, and sw = 7

int memento = 0; // remember, remember, the fifth of november .. only for .ino

void setup( void ) {

  are.setup( ); // organize inputs of PINs and init values

  Serial.begin( 57600 ); // let's talk fast to serial monitor
} // setup

void loop( void ) {

 int steps = are.read( ); // if there's action, the value changes ..

 if( steps != memento ) {

   memento = steps; // remember NOT talking to much on serial ..
   Serial.print("Rotary Encoder Position: ");
   Serial.println( steps );

   int direction = are.direction( ); // use this ALWAYS after calling read( )..
   Serial.print("Rotary Encoder Direction: ");
   Serial.println( direction );
 } // if

 if( are.button( ) ) {
   Serial.print("Rotary Encoder Button: ");
   Serial.println( "pressed!" );
 } // if

} // loop
