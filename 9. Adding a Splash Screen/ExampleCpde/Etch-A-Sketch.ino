#include <Arduboy2.h>
Arduboy2 arduboy;

uint8_t colour = WHITE;
bool drawState = true;
Point cursor;
Point prevCursor;
uint8_t prevCursorColour = BLACK;

void reset() {

    arduboy.clear();
    arduboy.setCursor(34, 27);
    arduboy.print("RESET");
    arduboy.display();
    delay(1000);
    arduboy.clear();

    cursor.x = arduboy.width() / 2;
    cursor.y = arduboy.height() / 2;

    colour = true;
    drawState = true;
    prevCursorColour = BLACK;

}

void renderScreen() {

    arduboy.drawRect(0, 0, arduboy.width(), arduboy.height(), WHITE);

    if (colour == BLACK) {
        arduboy.fillRect(101, 2, 11, 11, BLACK); // fill
        arduboy.drawRect(101, 2, 11, 11, WHITE); // outline
        arduboy.drawChar(104, 4, 'B', WHITE, BLACK, 1);
    }
    else {
        arduboy.fillRect(101, 2, 11, 11, WHITE);
        arduboy.drawChar(104, 4, 'W', BLACK, WHITE, 1);
    }

    if (!drawState) {
        arduboy.fillRect(114, 2, 11, 11, BLACK); // fill
        arduboy.drawRect(114, 2, 11, 11, WHITE); // outline
        arduboy.drawChar(117, 4, 'U', WHITE, BLACK, 1);
    }
    else {
        arduboy.fillRect(114, 2, 11, 11, WHITE);
        arduboy.drawChar(117, 4, 'D', BLACK, WHITE, 1);
    }

}

void setup() {

    arduboy.begin();

    cursor.y = arduboy.height() / 2;
    cursor.x = arduboy.width() / 2;

    prevCursor.x = cursor.x;
    prevCursor.y = cursor.y;
    prevCursorColour = BLACK;

    arduboy.clear();

}

void loop() {

    if ( !arduboy.nextFrame() ) return;
    arduboy.pollButtons();

    renderScreen();


    // Flash the cursor ..

    uint8_t cursorColor = WHITE;

    if (arduboy.frameCount % 16 < 8) {
        cursorColor = BLACK;
    }

    arduboy.drawPixel(cursor.x, cursor.y, cursorColor);


    // Change colour with A BUTTON ..

    if (arduboy.justPressed(A_BUTTON)) {
        if (colour == WHITE) {
            colour = BLACK;
        }
        else {
            colour = WHITE;
        }
    }


    // Change drawing state with B BUTTON ..

    if (arduboy.justPressed(B_BUTTON)) {
        drawState = !drawState;
    }


    // Reset the screen if both the A and B button pressed ..

    if (arduboy.pressed(A_BUTTON) && arduboy.pressed(B_BUTTON)) {
        reset();
    }


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

            if (drawState) {
                arduboy.drawPixel(prevCursor.x, prevCursor.y, colour);
            }
            else {
                arduboy.drawPixel(prevCursor.x, prevCursor.y, prevCursorColour);
            }

            prevCursor.x = cursor.x;
            prevCursor.y = cursor.y;
            prevCursorColour = arduboy.getPixel(prevCursor.x, prevCursor.y);
            
        }

    }

    arduboy.display();

}