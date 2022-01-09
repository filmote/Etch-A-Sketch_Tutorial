#include <Arduboy2.h>

Arduboy2 arduboy;
Point cursor;

void setup() {

    arduboy.begin();
    arduboy.clear();

}

void loop() {

    // Highligh the pixel at the cursor ..

    arduboy.drawPixel(cursor.x, cursor.y, WHITE);


    // Control the cursor ..

    if (arduboy.pressed(LEFT_BUTTON)) {
        cursor.x--;
    }

    if (arduboy.pressed(RIGHT_BUTTON)) {
        cursor.x++;
    }

    if (arduboy.pressed(UP_BUTTON)) {
        cursor.y--;
    }

    if (arduboy.pressed(DOWN_BUTTON)) {
        cursor.y++;
    }

    arduboy.display();

}
