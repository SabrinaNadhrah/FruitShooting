#include <graphics.h>

void displayMenu()
{
    int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
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

    // Close the graphics window
    closegraph();
}
int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Game Start");

    displayMenu();
    return 0;
}
