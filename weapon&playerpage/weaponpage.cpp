#include <graphics.h>
#include <iostream>

int main() {
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Choose Your Weapon!");
    setbkcolor(BLACK);
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
            } else if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 + 250 && mouseY <= screenHeight / 2 + 350) {
                option = 3; // Cannon selected
                break;
            }
        }

        setcolor(WHITE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 3);
        outtextxy(screenWidth / 2 - 80, screenHeight / 2 - 100, "Choose Your Weapon!");
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        // Draw 1 player button with Rifle image
        readimagefile("rifflee.jpg", screenWidth / 2 - 100, screenHeight / 2 - 50, screenWidth / 2 + 100, screenHeight / 2 + 50);
        outtextxy(screenWidth / 2 - 30, screenHeight / 2 + 60, "Rifle");

        // Draw 2 players button with Gun image
        readimagefile("gunn.jpg", screenWidth / 2 - 100, screenHeight / 2 + 100, screenWidth / 2 + 100, screenHeight / 2 + 200);
        outtextxy(screenWidth / 2 - 25, screenHeight / 2 + 210, "Gun");

        // Draw Cannon button with Cannon image
        readimagefile("cannon.jpg", screenWidth / 2 - 100, screenHeight / 2 + 250, screenWidth / 2 + 100, screenHeight / 2 + 350);
        outtextxy(screenWidth / 2 - 40, screenHeight / 2 + 360, "Cannon");

        delay(100);
    }

    closegraph();

    // Use the selected option here
    if (option == 1) {
        std::cout << "Rifle selected" << std::endl;
        // Add code for 1 player game with Rifle
    } else if (option == 2) {
        std::cout << "Gun selected" << std::endl;
        // Add code for 2 player game with Gun
    } else if (option == 3) {
        std::cout << "Cannon selected" << std::endl;
        // Add code for Cannon game
    }

    return 0;
}
