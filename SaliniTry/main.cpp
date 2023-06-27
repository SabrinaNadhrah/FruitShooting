#include <graphics.h>
#include "weapon.cpp"
#include "weapon.h"
#include "bullet.h"
#include "bullet.cpp"

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Fruit Shooting");
    setbkcolor(WHITE) ;

	Weapon w1(screenWidth/2, screenHeight-100);
	char ch;

    int direction = 1 ;

	w1.draw();

	while (true)
	{
		delay(40);

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
	}

	return 0;
}
