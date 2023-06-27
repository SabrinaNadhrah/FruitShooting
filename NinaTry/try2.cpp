#include <graphics.h>
#include <iostream>
#include <string>

using namespace std;

// Display Menu
void displayMenu()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    // Initialize graphics mode
    initwindow(screenWidth, screenHeight);

    // Display menu implementation
    // Set background color
    setbkcolor(BLACK);

    // Clear the screen
    cleardevice();

    // Set text properties
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);

    // Display title
    outtextxy(screenWidth / 2 - 240, screenHeight / 2 - 100, "Welcome to Fruit Shooting");

    // Set text properties for instructions
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);

    // Display instructions
    outtextxy(screenWidth / 2 - 100, screenHeight / 2 + 50, "Click to Start");

    // Wait for mouse click
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(100);
    }

    // Clear the mouse click event
    clearmouseclick(WM_LBUTTONDOWN);

    // Delay to allow the graphics window to refresh
    delay(200);
}

void WeaponPage()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    // Initialize graphics mode
    initwindow(screenWidth, screenHeight);

    setbkcolor(BLACK);
    cleardevice();

    int option = 0;
    int mouseX, mouseY;

    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            mouseX = mousex();
            mouseY = mousey();

            if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 - 50 && mouseY <= screenHeight / 2 + 50)
            {
                option = 1; // 1 player selected
                break;
            }
            else if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 + 100 && mouseY <= screenHeight / 2 + 200)
            {
                option = 2; // 2 players selected
                break;
            }
            else if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 + 250 && mouseY <= screenHeight / 2 + 350)
            {
                option = 3; // Cannon selected
                break;
            }
        }

        setcolor(WHITE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 3);
        outtextxy(screenWidth / 2 - 80, screenHeight / 2 - 50, "Choose Your Weapon!");
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        // Draw 1 player button with Rifle image
        readimagefile("rifflee.jpg", screenWidth / 2 - 100, screenHeight / 2 - 30, screenWidth / 2 + 100, screenHeight / 2 + 30);
        outtextxy(screenWidth / 2 - 30, screenHeight / 2 + 60, "Rifle");

        // Draw 2 players button with Gun image
        readimagefile("gunn.jpg", screenWidth / 2 - 100, screenHeight / 2 + 70, screenWidth / 2 + 100, screenHeight / 2 + 170);
        outtextxy(screenWidth / 2 - 30, screenHeight / 2 + 200, "Gun");

        // Draw cannon button with Cannon image
        readimagefile("cannonn.jpg", screenWidth / 2 - 100, screenHeight / 2 + 220, screenWidth / 2 + 100, screenHeight / 2 + 320);
        outtextxy(screenWidth / 2 - 30, screenHeight / 2 + 350, "Cannon");

        delay(100);
    }

    // Clear the screen
    cleardevice();

    // Display the selected option
    string weapon;
    if (option == 1)
        weapon = "Rifle";
    else if (option == 2)
        weapon = "Gun";
    else if (option == 3)
        weapon = "Cannon";

    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    const char* weaponText = ("Weapon Selected: " + weapon).c_str();
    outtextxy(screenWidth / 2 - 80, screenHeight / 2, weaponText);

    delay(2000);

    // Close the graphics window
    closegraph();
}

int main()
{
    displayMenu();
    WeaponPage();

    return 0;
}
