#include <Arduboy2.h>
Arduboy2 arduboy;

Point cursor;
Point prevCursor;

void setup() {

    arduboy.begin();

    cursor.y = arduboy.height() / 2;
    cursor.x = arduboy.width() / 2;

    prevCursor.x = cursor.x;
    prevCursor.y = cursor.y;

    arduboy.clear();
    arduboy.drawRect(0, 0, arduboy.width(), arduboy.height(), WHITE);

}

void loop() {

    if ( !arduboy.nextFrame() ) return;
    arduboy.pollButtons();


    // Flash the cursor ..

    uint8_t cursorColor = WHITE;

    if (arduboy.frameCount % 16 < 8) {
        cursorColor = BLACK;
    }

    arduboy.drawPixel(cursor.x, cursor.y, cursorColor);


    // Control the cursor ..

    if (arduboy.frameCount % 4 == 0) {

        if (arduboy.pressed(LEFT_BUTTON) && cursor.x > 1) {
            cursor.x--;
        }

        if (arduboy.pressed(RIGHT_BUTTON) && cursor.x < arduboy.width() - 2) {
            cursor.x++;
        }

        if (arduboy.pressed(UP_BUTTON) && cursor.y > 1) {
            cursor.y--;
        }

        if (arduboy.pressed(DOWN_BUTTON) && cursor.y < arduboy.height() - 2) {
            cursor.y++;
        }

    }

    arduboy.display();

}
