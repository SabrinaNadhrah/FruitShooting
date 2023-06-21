#include <graphics.h>
#include <string>
#include "Character.h"
#include "ImpleCharacter.cpp"
#include "weapon.cpp"
#include "weapon.h"
#include "bullet.h"
#include "bullet.cpp"

using namespace std;

void displayMenu()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Game Start");

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

    // Close the graphics window
    closegraph();
}

int main()
{
    displayMenu();

    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Fruit Shooting Character part");
    setbkcolor(WHITE); // Set the background color to white

    void *background;
    int imageWidth = screenWidth;
    int imageHeight = screenHeight;
    int size = imagesize(0, 0, imageWidth, imageHeight);
    background = new char[size];

    int character2X = screenWidth / 2; // start at the middle of screen
    int character2Y = screenHeight - 230;
    int character1X = screenWidth / 2; // start at the middle of screen
    int character1Y = screenHeight - 230;

    Character character2("Player", character2X, character2Y);
    Character character3("Player2", character1X, character1Y);

    Weapon w1(screenWidth / 2, screenHeight - 100);
    char ch;

    int direction = 1;

    while (true)
    {
        delay(40);
        setactivepage(1);
        cleardevice();
        character3.moveLeft();
        // Update character 2 position
        character2.moveRight();
        if (character2.getPosition() == screenWidth)
            character2.moveLeft();
       

        // Draw character 2 at the updated position
        character2.drawCharacter();
        character3.drawCharacter();
        setvisualpage(1);

        // Move the weapon
        w1.move(5* direction);

        // Reverse direction if the weapon reaches the screen boundaries
        if (w1.getPosition() <= 0 || w1.getPosition() >= (screenWidth - 155))
            direction *= -1;

        w1.doAction();

        if (kbhit())
        {

            ch = getch();

            if (ch == 27)
                break;
            else if (ch == ' ')
                w1.shoot();
        }

        // Redraw the weapon
        cleardevice();
        w1.update();
        w1.draw();
    }

    closegraph();
    return 0;
}
