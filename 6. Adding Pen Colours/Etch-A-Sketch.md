# Adding Pen Colours 

OK, so the screen only has two colours but lets not let that prevent us from adding functionality to our application!

First we need an integer variable to track the current colour which we will (logically) call `colour`.  It is initialised to WHITE to ensure that the player can immediately see what they are drawing on the screen.

```cpp
#include <Arduboy2.h>
Arduboy2 arduboy;

uint8_t colour = WHITE;
```

Pressing the A button will toggle the colour from `BLACK` to `WHITE` and back again.  

```cpp
void loop() {

    ...

    // Change colour with A BUTTON ..

    if (arduboy.justPressed(A_BUTTON)) {
        // Change to the opposite colour.
    }
    ...
```

In this instance, we have used the Arduboy2 `justPressed()` function, rather than the `pressed()` function we used earlier, to ensure that the colour change only occurs when the player clicks the button and does not toggle repeatedly if they hold the button down.  

> Your Turn:<br/>
> When the player presses the A button, the colour variable needs to toggle from `BLACK` to `WHITE` or back again.  Add this logic to the code and run the program to test the functionality.


To indicate which colour has been selected, a simple icon will be displayed on the screen using some more inbuilt Arduboy2 functions, `fillRect()` and `drawRect()`.  It is split out into a separate function, called `renderScreen()`, which we will add to in the next section.


```cpp
void renderScreen() {

    if (colour == BLACK) {
        arduboy.fillRect(101, 2, 11, 11, BLACK); // fill
        arduboy.drawRect(101, 2, 11, 11, WHITE); // outline
        arduboy.drawChar(104, 4, 'B', WHITE, BLACK, 1);
    }
    else {
        arduboy.fillRect(101, 2, 11, 11, WHITE);
        arduboy.drawChar(104, 4, 'W', BLACK, WHITE, 1);
    }

}

```

> Your Turn:<br/>
> Add a call to `renderScreen()` at the start of the `loop()`.  Make sure that this happens after the standard frame logic.

In the next section, we will adda Pen Up and Pen Down function to allow us to move around without leaving a trail.
