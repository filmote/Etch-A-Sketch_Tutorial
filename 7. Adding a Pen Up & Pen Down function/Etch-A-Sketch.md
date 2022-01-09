# Adding a Pen Up & Pen Down Function

If you have ever used a real Etch-A-Sketch to draw anything complex, you will know that different elements of the picture need to be joined by a line as there is no ability to move the cursor without leaving a trace.  In our electronic version, we do not have the same limitations of the old mechanical one and we can add this feature!

Adding a 'pen up' mode complicates the logic we had when the player moves the cursor.  Previously, we could simply draw a pixel in the previous cursor position as we were always leaving a trail.  With the introduction of the 'pen up' state, we need to restore the pixel in the `prevCursor` location to whatever value it originally had before we moved on to it.  In this way we can move the cursor around the screen in 'pen up' state without destroying any artwork we cross.

To do so, we need to add a couple of new variables to track the pen's state `drawState` and the original pixel colour at the cursor's position.  This will be called `prevCursorColour` and is initialised to `BLACK` as the entire screen is initially black.

```cpp
#include <Arduboy2.h>
Arduboy2 arduboy;

uint8_t colour = WHITE;
bool drawState = true;
uint8_t prevCursorColour = BLACK;
```


Pressing the B button will toggle the drawing state between pen down `false` and pen up `true`.  Like the code for changing the pen colour added previously, this uses the `justPressed()` function to ensure that holding the button down doesn't cause the mode to toggle multiple times.

```cpp
void loop() {

    ...

    // Change drawing state with B BUTTON ..

    if (arduboy.justPressed(B_BUTTON)) {
        drawState = !drawState;
    }
    ...
```

When rendering the pixel after a cursor position change, we now need to consider what draw state we are in to determine whether to overwrite or restore the pixel.  If the `drawState` is `true` - indicating that the pen is down and we are simply overwriting pixels, then the screen can be updated with whatever pen colour we currently using.  

If the `drawState` is `false` - indicating that the pen is up, the pixel is restored to its original colour using the value stored in `prevCursorColour`.
 

```cpp
if (cursor.x != prevCursor.x || cursor.y != prevCursor.y) {

    if (drawState) {
        arduboy.drawPixel(prevCursor.x, prevCursor.y, colour);
    }
    else {
        arduboy.drawPixel(prevCursor.x, prevCursor.y, prevCursorColour);
    }

    prevCursor.x = cursor.x;
    prevCursor.y = cursor.y;
    prevCursorColour = arduboy.getPixel(prevCursor.x, prevCursor.y);
    
}
```

After the pixel is drawn, the `prevCursor` struct is updated with the coordinates from the current cursor location.  Additionally, the colour of the pixel at the cursor location is retrieved and stored in `prevCursorColour` ready for the next movement.

> Your Turn: <br/>
> We need an indicator that tells us whether the pen is up or down.  Copy the logic of the pen colour indicator to do so.  The coordinates of the indicator square should be (114,2) with the letters U and D (for Up and Down) at positions (117,4).

In the next section, we will add the electronic equivalent of shaking the Etch-A-Sketch (a reset button).
