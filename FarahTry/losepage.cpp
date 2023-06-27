#include <iostream>
#include <graphics.h>

const int screenWidth = 800;
const int screenHeight = 600;

void drawGameOver() {
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    setcolor(RED);
    outtextxy(screenWidth / 2 - 100, screenHeight / 2 - 50, "Game Over");

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(screenWidth / 2 - 80, screenHeight / 2 + 50, "Play Again");
}

bool isMouseOverPlayAgain(int mx, int my) {
    int playAgainX = screenWidth / 2 - 80;
    int playAgainY = screenHeight / 2 + 50;
    int playAgainWidth = 160;
    int playAgainHeight = 40;

    return (mx >= playAgainX && mx <= playAgainX + playAgainWidth && my >= playAgainY && my <= playAgainY + playAgainHeight);
}

int main() {
    initwindow(screenWidth, screenHeight, "Game Over Page");

    bool playAgain = false;
    while (!playAgain) {
        cleardevice();

        drawGameOver();

        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(100);
        }

        int mx, my;
        getmouseclick(WM_LBUTTONDOWN, mx, my);

        playAgain = isMouseOverPlayAgain(mx, my);
    }

    closegraph();
    return 0;
}
