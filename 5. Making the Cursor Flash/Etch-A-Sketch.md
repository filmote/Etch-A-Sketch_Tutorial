# Making the Cursor Flash

Once you start drawing anything elaborate with the program, a number of limitations present themselves very quickly.  One of these is how to determine where the cursor actually is and making it flash would certainly help!

To do this, we need to make the cursor blink using the `frameCount` and `modulus` trick introduced a couple of sections ago.  We also need to know when the player has actually moved the cursor so that we can highlight the pixel they have just moved from, leaving a trail of white pixels behind the cursor.  To track the movement of the cursor between button presses, we can create a second `Point` variable, named `prevCursor`, as shown below.

```cpp
#include <Arduboy2.h>
Arduboy2 arduboy;

Point cursor;
Point prevCursor;
...
```

In the `setup()` function, we also need to initialise the `prevCursor` variable so that it has the same starting position as the real cursor.  Previously we ensured the `cursor` was positioned in the middle of the screen, so we can repeat the logic for the `prevCursor` or simply copy the `x` and `y` values from the `cursor` to the `prevCursor` structs, as shown below.

```cpp
void setup() {

    ...

    cursor.y = arduboy.height() / 2;
    cursor.x = arduboy.width() / 2;

    prevCursor.x = cursor.x;
    prevCursor.y = cursor.y;

    ...

}
```

As mentioned, making the cursor flash is imply now that we know about the `frameCount` and `modulus` trick.  We can render the cursor at the top of the `loop()` in either black or white for eight frames each using the code below.

```cpp
void loop() {

    ...


    // Flash the cursor ..

    uint8_t cursorColor = WHITE;

    if (arduboy.frameCount % 16 < 8) {
        cursorColor = BLACK;
    }

    arduboy.drawPixel(cursor.x, cursor.y, cursorColor);
    
    ...
```

After a player presses a button and moves the cursor, we need to draw a pixel at the last know location of the cursor, `prevCursor`, before updating the `x` and `y` values of `prevCursor` with those of the new position of `cursor`.

> Your Turn:<br/>
> Immediately after the button press logic, test to see if the cursor has been moved by comparing old and new `x` and `y` values.  If so, draw a pixel in the old position and then update the `x` and `y` values of the `prevCursor` with the new cursor position.
