#include <Arduboy2.h>
Arduboy2 arduboy;

Point cursor;

void setup() {

    arduboy.begin();
    arudboy.setFrameRate(30);

    cursor.y = arduboy.height() / 2;
    cursor.x = arduboy.width() / 2;

    arduboy.clear();
    arduboy.drawRect(0, 0, arduboy.width(), arduboy.height(), WHITE);

}

void loop() {

    if ( !arduboy.nextFrame() ) return;
    arduboy.pollButtons();


    // Highligh the pixel at the cursor ..

    arduboy.drawPixel(cursor.x, cursor.y, WHITE);


    // Control the cursor ..

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

    arduboy.display();

}
