# Adding a Reset Button

How do you clear the screen after creating a mess?

In this section, we will add a clear screen function that will be invoked by pressing the A and B buttons simultaneously.  When invoked, the function will simply clear the screen and display the word 'reset' for a second before clearing the screen a second time. The code is shown below and it uses a number of Arduboy2 functions which are pretty self-explanatory.  

The line `delay(1000)` causes the code to pause for one thousand milliseconds (a full second) before proceeding. 


```cpp
void reset() {

    arduboy.clear();
    arduboy.setCursor(34, 27);
    arduboy.setTextSize(2);
    arduboy.print("RESET");
    arduboy.display();
    delay(1000);
    arduboy.clear();

}
```

> Your Turn: <br/>
> In addition to clearing the screen, the `reset()` function should reset the cursor to the centre of the screen and return the `colour`, `prevCursorColour` and `drawState` back to their default values.  Add this logic into the bottom of the function.

To invoke the function, we need to add a test to see if both the A and B buttons are being pressed together.  For this, we cannot use the `justPressed()` function as the likelihood of the player clicking both buttons simultaneously **in the same frame** is very unlikely.

> Your Turn: <br/>
> Add logic to detect whether both the A and B buttons are pressed immediately under the existing code that detects the B button.  If both are pressed then call the `reset()` function.  

In the next section, we will add a simple splash screen to complete the program and give it some polish.
