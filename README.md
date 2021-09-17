## The cool Arduino Rotary Encoder library

### Introduction ###

The cool arduino rotary encoder (coolARE) library is implemented for rotary encoders of type KY-040 including a switch button.

### Implementation ###

The implementation follows an absoulte minimum.

### Usage ###

Do the follwing:

**Bake an object:**
```C++
ARE are( 9, 8, 7 ); // bakes an object; select CLK = PIN 9, DS = PIN 8, and SW = PIN 7
```
**or without using the button:**
```C++
ARE are( 9, 8 ); // bakes an object; select CLK = PIN 9, and DS = PIN 8
```
**call in arduino's setup method:**
```C++
are.setup( ); // inits pins and member variables
```
**read the steps up and down in arduino's loop method:**
```C++
int steps = are.read( ); // .., -2, -1, 0, 1, 2, ..; inits with 0
```
**read the direction:**
```C++
// this method only works when the are.read( ) is called somewhere!
bool clockwise = are.direction( ); // TRUE clockwise, and FALSE counterwise ..
```
**read the button:**
```C++
// this method works independently!
bool isPressed = are.button( ); // TRUE when button is pressed, else always false
```
That's all and _far_ enough.

See the [coolARE.ino](https://github.com/graetz23/coolARE/blob/master/coolARE.ino) for a _glued_ example, try running it in [arduino IDE](https://www.arduino.cc/en/main/software). Press _CTRL+SHFT+m_ for the serial monitor; default are 57600 baud to choose. The rotary encoder starts talking to you.

### Releases

There are [stable releases available](https://github.com/graetz23/coolARE/releases) by cloning or downloading and unzipping. Just put all files in the same directory or the [coolARE.h](https://github.com/graetz23/coolARE/blob/master/coolARE.h) and the [coolARE.cpp](https://github.com/graetz23/coolARE/blob/master/coolARE.cpp) to your project directory. There's noo need to include a library in [arduino IDE](https://www.arduino.cc/en/main/software) or to do something else.

### Remarks

Everything was coded using:

  - [**Rotary Encoders**](https://en.wikipedia.org/wiki/Rotary_encoder) of type KY-040,
  - [**arduino Makefile**](https://github.com/sudar/Arduino-Makefile) for automated building,
  - [**atom**](https://atom.io/) editor,
  - [**Gnome**](https://www.gnome.org/) as window manager,
  - and [**debian**](https://www.debian.org/) GNU/Linux.

have fun :-)

## Change Log

**20200416**
  - release of [version 1](https://github.com/graetz23/coolARE/releases),
  - debugged, working well,
  - set up of classes,
  - set up of repository.
