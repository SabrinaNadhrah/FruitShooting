#include <iostream>
#include <graphics.h>

const int screenWidth = 800;
const int screenHeight = 600;

void drawNewGamePage() {
    setbkcolor(BLACK);
    cleardevice();

    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    setcolor(YELLOW);
    outtextxy(screenWidth / 2 - 180, screenHeight / 2 - 100, "New Game");

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    setcolor(RED);
    outtextxy(screenWidth / 2 - 150, screenHeight / 2 + 50, "Press Enter to Start");
}

int main() {
    initwindow(screenWidth, screenHeight, "New Game Page");

    drawNewGamePage();

    while (true) {
        if (kbhit()) {
            char key = getch();
            if (key == 13) { // Enter key
                break; // Exit the loop and start the game
            }
        }
    }

    closegraph();

    return 0;
}
