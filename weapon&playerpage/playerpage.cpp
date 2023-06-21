#include <graphics.h>
#include <iostream>

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    initwindow(screenWidth, screenHeight, "Player Option");
    setbkcolor(WHITE);
    cleardevice();

    int option = 0;
    int mouseX, mouseY;

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            mouseX = mousex();
            mouseY = mousey();

            if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 - 50 && mouseY <= screenHeight / 2 + 50) {
                option = 1; // 1 player selected
                break;
            } else if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 + 100 && mouseY <= screenHeight / 2 + 200) {
                option = 2; // 2 players selected
                break;
            }
        }

        setcolor(BLACK);
        settextstyle(BOLD_FONT, HORIZ_DIR, 3);
        outtextxy(screenWidth / 2 - 80, screenHeight / 2 - 100, "Player Option");
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        // Draw 1 player button
        rectangle(screenWidth / 2 - 100, screenHeight / 2 - 50, screenWidth / 2 + 100, screenHeight / 2 + 50);
        floodfill(screenWidth / 2, screenHeight / 2, BLACK);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(screenWidth / 2 - 45, screenHeight / 2 - 10, "1 Player");

        // Draw 2 players button
        rectangle(screenWidth / 2 - 100, screenHeight / 2 + 100, screenWidth / 2 + 100, screenHeight / 2 + 200);
        floodfill(screenWidth / 2, screenHeight / 2 + 150, BLACK);
        outtextxy(screenWidth / 2 - 45, screenHeight / 2 + 140, "2 Players");

        delay(100);
    }

    closegraph();

    // Use the selected option here
    if (option == 1) {
        std::cout << "1 player selected" << std::endl;
        // Add code for 1 player game
    } else if (option == 2) {
        std::cout << "2 players selected" << std::endl;
        // Add code for 2 player game
    }

    return 0;
}
