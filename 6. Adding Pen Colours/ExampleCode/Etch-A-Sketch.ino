#include <Arduboy2.h>
Arduboy2 arduboy;

uint8_t colour = WHITE;
Point cursor;
Point prevCursor;

void renderScreen() {

    if (colour == BLACK) {
        arduboy.fillRect(101, 2, 11, 11, BLACK); // fill
        arduboy.drawRect(101, 2, 11, 11, WHITE); // outline
        arduboy.drawChar(104, 4, 'B', WHITE, BLACK, 1);
    }
    else {
        arduboy.fillRect(101, 2, 11, 11, WHITE);
        arduboy.drawChar(104, 4, 'W', BLACK, WHITE, 1);
    }

}

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

        if (cursor.x != prevCursor.x || cursor.y != prevCursor.y) {

            arduboy.drawPixel(prevCursor.x, prevCursor.y, colour);

            prevCursor.x = cursor.x;
            prevCursor.y = cursor.y;
            
        }

    }

    arduboy.display();

}
