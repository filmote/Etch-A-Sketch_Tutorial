# Limiting the Cursor Range

Our second problem with the initial implementation was that the cursor was not constrained to the screen itself.  

If you recall, the screen dimensions are 128 x 64 with the (0,0) point being in the top left hand corner.  You may have noticed that we are drawing a simple rectangle to show the boundaries of the screen which is 1 pixel wide.  Therefore our effective range for the cursor is between 1 and 126 on the X axis and 1 and 62 on the Y axis.

To limit the cursor from moving off the screen in the X axis, we can simply add an additional clause that ensures that the cursor is not already on the range limit, as shown below.  Pressing the left button will decrease the `cursor.x` value until it reaches the value of `1` at which point the test will fail and it can no longer move further.


```cpp
if (arduboy.pressed(LEFT_BUTTON) && cursor.x > 1) {
    cursor.x--;
}
```

The logic for the right limit is similar:

```cpp
if (arduboy.pressed(RIGHT_BUTTON) && cursor.x < 126) {
    cursor.x++;
}
```

Woah! What's that magic number '126'?  In programming, a magic number is one that makes sense at the time of coding but is not obvious to the next person maintaining the code or its meaning not obvious or easily forgotten.  Even though it's more coding, the code below makes it clear to the reader that the `cursor.x` value is constrained by the screen's `width()`.

```cpp
if (arduboy.pressed(RIGHT_BUTTON) && cursor.x < arduboy.width() - 2) {
    cursor.x++;
}
```

Using these constraints, we can ensure the cursor does not leave the screen.

> Your Turn: <br/>
> Add constraints for the cursor's `y` axis.  You can use the code for the `x` axis as a template.
