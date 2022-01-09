# Arduboy2 Frames

Let's get really dirty, really quickly .. and talk about frames.  

Although the processor in the 8BitCADE is a very simple one, as you can see it does somethings (like rendering our cursor) really fast and other things quite slowly.  When writing a game or even a simple Etch-A-Sketch program, we need to often slow the program down to a manageable speed.  

Other times we will want the speed to be consistent.  Imagine a space fighting game where sometimes there are dozens of enemy planes on the screen and at other times when you have killed them all off, there are relatively few.  We want the player and enemy's speed to be consistent regardless of the number of objects on the screen and this can be achieved using a set of functions provided by the Arduboy2 library.

The speed that a program runs can be controlled by setting a frame rate.  Without a frame rate, the `loop()` function will start executing immediately after the previous loop has finished.  There is nothing governing the speed and it will run flat out all day.  By specifying a frame rate ` arudboy.setFrameRate(30)` adding the cryptic `if ( !arduboy.nextFrame() ) return;` at the top of the `loop()`, the Arduboy2 library will not execute the code in the loop until it's time to show the next frame.

If you do not specify a frame rate, the Arduboy library will assume a frame rate of 60 frames per second.
 
```cpp
void setup() {

    arduboy.begin();
    arudboy.setFrameRate(30);

}

void loop() {

    if ( !arduboy.nextFrame() ) return;
    arduboy.pollButtons();
    arduboy.clear();

    ... print something or draw graphics.

    arduboy.display();

}
```

In addition to regulating the speed of a program, the inclusion of frames also lets the Arduboy2 library track button presses between frames so it can tell if a button has just been pressed, held down or been released.  The extra line of code `arduboy.pollButtons()` triggers the library to record the current button states and compare it to those captured previously.  We will see this in action in a future section of the tutorial. 

Back to the problem we are trying to solve .. how do we slow the program down to a manageable speed?


> Your Turn: <br/>
> Add the two function Arduboy2 function calls to the program to set the frame rate to (say) 15 fps and enforces this in the `loop()`. <br/>
> Run the program and see the results.  Adjust the value of `15` and observer the results.

So this solves the problem, right?  Well yes and no.  In this simple example where we only have one thing dependant on the frame rate of the application, it works well but it will not work if we want different screen elements to move at different rates.

The Arduboy2 library keeps a running count of the frame it has just rendered in a variable named `frameCount`.  We can use this number and some simple math to allow different actions to happen at different speeds.  The trick to this is the math modulus or mod function, represented using the `%` symbol in Arduino-land, which returns the remainder of a division.  For example, 7 mod 3 returns 1 (as the left-over after two lots of three is one).

```cpp
void loop() {

    if ( !arduboy.nextFrame() ) return;

	if (arduboy.frameCount % 2 == 0) { 
	    .. do something every second frame.
	}

	if (arduboy.frameCount % 3 == 0) { 
	    .. do something every third frame.
	}

	if (arduboy.frameCount % 5 <= 2) { 
	    .. do something every 0, 1 and 2 frame but skip it on frames 3 and 4.
	}

	if (arduboy.frameCount % 32 < 16) { 
	    .. do something for a 16 frame interval then wait 16 frames.  
	    .. This could be used to blink something slowly on the screen.
	}


    arduboy.display();

}
```

Using the `frameCount` and using the modulus function will allow actions to happen on different cycles.

> Your Turn: <br/>
> Return the frame rate back to 60 fps. <br/>
> Change the `loop()` to only detect the button presses every 4th frame.
