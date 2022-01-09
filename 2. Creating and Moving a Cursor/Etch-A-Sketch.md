# Creating and Moving a Cursor

In this section, we will add a simple cursor and move it around the screen leaving a trail in white behind it.

The location of our cursor needs to be tracked in both the `x` and `y` coordinates.  The Arduboy2 library provides a simple structure called a `Point` that allows us to do just that.  If you are unfamiliar with structures, you can consider them to be multiple variables wrapped together to make coding simpler and easier to read.  The `Point` structure is simply defined as:

```cpp
struct Point {
    int16_t x;
    int16_t y;
};
```

As you can see a `Point` has two variables that can be used to store the coordinates of something - in our case the cursor the player will be moving around the screen.  Using this structure, we can create a variable (or instance) of this type and manipulate the `x` and `y` values independently.

```cpp
Point cursor;

cursor.x = 23;
cursor.y = 40;

cursor.x = cursor.x + 2;
```

Now that we have a cursor, we can draw a white pixel at the coordinates it nominates.  The Arduboy2 library contains a function `drawPixel()` that accepts three parameters - the x and y position of the pixel and its colour.  The library also exposes two colour constants, `BLACK` and `WHITE`.

```cpp
arduboy.drawPixel(cursor.x, cursor.y, WHITE);
```
You can run the program now and you should see a single, white dot in the top left corner of the screen.  In the Arduboy2 library, the location (0,0) is the top left corner of the screen whereas (127, 63) is the bottom right corner.

Your turn:  

Update the `setup()` to position the cursor in the centre of the screen when the program starts.  The Arduboy2 libary provides both `width()` and `height()` functions that will give you the screens **full** dimensions.

   
We can move the cursor based on the player pressing a button using a built-in Arduboy2 function named `pressed()` that indicates that a button has been pressed or held down.  For interests sake, there are a number of other functions that indicate when a button has just been pressed or released however we do not need these for this tutorial.

To detect that the user has pressed the left button on the D-Pad, we can use the code shown below.  Once pressed, the `x` value of our `cursor` is decreased by one.

```cpp
if (arduboy.pressed(LEFT_BUTTON)) {
    cursor.x--;
}
```    

Likewise a press of the right button will increase the `x` value.

```cpp
if (arduboy.pressed(RIGHT_BUTTON)) {
    cursor.x++;
}
```    

> Your Turn:<br/>  
> Update the `loop()` to handle the player pressing the up or down button.  Obviously, these should alter the `y` value of the `cursor`.<br/>
> Once you have completed the task, run the program again and use the D-Pad to move around the screen.  <br/>

What did you notice?  Right, it's almost impossible to control and the cursor leaves the screen!  We will address these two issues in the next two sections.
