#include <graphics.h>
#include <string>
#include "Character.h"
#include "ImpleCharacter.cpp"


using namespace std;

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    
    initwindow(screenWidth, screenHeight, "Fruit Shooting Character part");

    void* background;
    int imageWidth = screenWidth;
    int imageHeight = screenHeight;
    int size = imagesize(0, 0, imageWidth, imageHeight);
    background = new char[size];

    // Load the image from the file and scale it to full screen
    string imageFile = "forest.jpg";
    readimagefile(imageFile.c_str(), 0, 0, screenWidth, screenHeight);
    getimage(0, 0, imageWidth - 1, imageHeight - 1, background);

    int character2X = screenWidth / 2 + 100;// start at the middle of screen
    int character2Y = screenHeight - 230; 

    Character character2("Player", character2X, character2Y);

    while (!kbhit())
    {
        setactivepage(1);
        //cleardevice();

        // Draw background
        putimage(0, 0, background, COPY_PUT);

        // Update character 2 position
        character2.moveRight();
        if (character2.getPosition() >= screenWidth)
            character2.setPosition(0);

        // Draw character 2 at the updated position
        character2.drawCharacter();

        setvisualpage(1);

        delay(50);
    }

    closegraph();
    return 0;
}
