#include <graphics.h>
#include <string>
#include "Character.h"
#include "ImpleCharacter.cpp"
#include "weapon.cpp"
#include "weapon.h"
#include "bullet.h"
#include "bullet.cpp"


using namespace std;

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    
    initwindow(screenWidth, screenHeight, "Fruit Shooting Character part");
    setbkcolor(WHITE); // Set the background color to white

    void* background;
    int imageWidth = screenWidth;
    int imageHeight = screenHeight;
    int size = imagesize(0, 0, imageWidth, imageHeight);
    background = new char[size];

    

    int character2X = screenWidth / 2 + 100;// start at the middle of screen
    int character2Y = screenHeight - 230; 

    Character character2("Player", character2X, character2Y);

    Weapon w1(screenWidth/2, screenHeight-100);
	char ch;


    int direction = 1 ;
    while (!kbhit())
    {
        setactivepage(1);
        cleardevice();

        
        // Update character 2 position
        character2.moveRight();
        if (character2.getPosition() >= screenWidth)
            character2.setPosition(0);

        // Draw character 2 at the updated position
        character2.drawCharacter();

        setvisualpage(1);

        
        // Move the weapon
        w1.move(5 * direction);

        // Reverse direction if the weapon reaches the screen boundaries
        if (w1.getPosition() <= 0 || w1.getPosition() >= (screenWidth - 155) )
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

        delay(40);
    }

    closegraph();
    return 0;
}
