#include <Arduboy2.h>

Arduboy2 arduboy;

void setup() {

    arduboy.begin();

}

void loop() {

    arduboy.clear();
    arduboy.print("Hello");
    arduboy.display();

}
