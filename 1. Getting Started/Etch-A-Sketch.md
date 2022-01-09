# Getting Started

In this tutorial we will build a simple Etch-A-Sketch program that will allow you to create the next Monet, Picasso or Banksy in fashionable, 1-bit graphics.

To fully understand this tutorial, you need to be able to understand basic Arduino syntax and program structure. We advise that the following tutorials are completed before starting this project:

* Arduino Basic’s: Classes
* Arduino Basic’s: Library & Board Setup

The tutorial has been split into multiple steps allowing you to complete each section, verify the code segments you will add and run the program before moving on. Each subsequent section will introduce a new concept and add a little refinement to the program overall.


## Basic Arduino and Arduboy Programs

As you would have learnt when looking at the Arduino itself, all programs have two 'boiler plate' functions named `setup()` and `loop()`.  The `setup()` function is a place where you can add code that needs to be executed once - and only once - and is typically used to initialise variables or other housekeeping.  The `loop()` function on the other-hand, is called continuously and will usually contain the real logic of your program or game.

```cpp
void setup() {
}

void loop() {
}
```


When writing code for the Arduboy, the basic Arduino structure shown above is extended to include the Arduboy2 library.  This library allows the programmer to perform basic functions, such as render text and graphics to the 8BitCADE console and read the current state of its buttons, without needing to understand the detail of this.

The Arduboy2 library has a number of companion libraries that can be used to create sound effects, add additional fonts or provide additional graphics capabilities.  These are beyond the scope of this simple tutorial but as your skills increase and you tackle more advanced tutorials from this site, you will undoubtedly come across them.

To be able to use the Arduboy2 library, we simply add the line `#include <Arduboy2.h>` at the top of the program as shown below.  An `#include` tells the compiler that you are going to use functions in a library that is external to this program.  In addition to the standard libraries, you can also create your own custom libraries and include these the same way.

Once the Arduboy2 library is included, we can create an instance of it using `Arcuboy2 arduboy` so that we can call the functions it contains later.  Finally, we need to initialise the `arduboy` variable using the `begin()` command.  As this command is inside the `setup()` function, it is executed only once and basically sets up the device ready to execute further instructions.	


```cpp
#include <Arduboy2.h>

Arduboy2 arduboy;

void setup() {

    arduboy.begin();

}
```

Now that we have a reference to the Arduboy2 library, we can call its functions to start building our program.  A simple program, as shown below, demonstrates how to clear the screen, print a welcome greeting and then display it all on the screen.  Note how each of these calls are prefixed with `arduboy.` which indicates that each function - `clear`, `print` and `display` - are all part of the Arduboy library.  We access them via our reference to the library named `arduboy`.

```cpp
void loop() {

    arduboy.clear();
    arduboy.print("Hello");
    arduboy.display();

}
```

> Your Turn: <br/>
> Change the greeting to other words if you like.  <br/>
> Add a second `arduboy.print()` line and notice how the two prints are aligned.  Change the first `print()` to `println()` to see how it adds a line break between the words.
> Position the text using `arduboy.setCursor(x,y)` - the screen size is 128 x 64 with (0, 0) being in the top left corner.
