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

    void* background;
    int imageWidth = screenWidth;
    int imageHeight = screenHeight;
    int size = imagesize(0, 0, imageWidth, imageHeight);
    background = new char[size];

    // Load the image from the file and scale it to full screen
    readimagefile("background.jpg", 0, 0, screenWidth, screenHeight);
    getimage(0, 0, imageWidth - 1, imageHeight - 1, background);

    int character2X = screenWidth / 2; // start at the middle of screen
    int character2Y = screenHeight - 230;
    int character1X = screenWidth / 2; // start at the middle of screen
    int character1Y = screenHeight - 230;

    Character character2("Player", character2X, character2Y);
    Character character3("Player2", character1X, character1Y);

    Weapon w1(screenWidth / 2, screenHeight - 100);
    char ch;

    int direction = 1;

    // Create double buffer image
    int bufferWidth = screenWidth + 1;
    int bufferHeight = screenHeight + 1;
    void* buffer = new char[imagesize(0, 0, bufferWidth, bufferHeight)];

    while (true)
    {
        cleardevice();

        // Move the characters
        character2.moveRight();
        character3.moveLeft();

        // Move the weapon
        w1.move(5 * direction);

        // Reverse direction if the weapon reaches the screen boundaries
        if (w1.getPosition() <= 0 || w1.getPosition() >= (screenWidth - 155))
            direction *= -1;

        // Update and draw the bullet
        w1.update();
        w1.draw();

        // Draw on the off-screen buffer
        setactivepage(0);
        setvisualpage(1);

        // Draw the background image
        putimage(0, 0, background, COPY_PUT);

        // Draw the characters
        character2.drawCharacter();
        character3.drawCharacter();

        // Swap the buffers to display the complete frame
        swapbuffers();

        // Handle user input
        if (kbhit())
        {
            ch = getch();

            if (ch == 27)
                break;
            else if (ch == ' ')
                w1.shoot();
        }

        delay(100);
    }

    closegraph();
    delete[] static_cast<char*>(buffer);
    return 0;
}


