#include <iostream>
#include <graphics.h>
using namespace std ;

enum WeaponType {
    RIFLE,
    GUN,
    CANNON
};

WeaponType selectedWeapon = RIFLE;  // Default selected weapon is Rifle
bool startGame = false;  // Flag to indicate if the game should start

void handleClick(int button, int state, int x, int y) {
    if (button == WM_LBUTTONDOWN && state == 0) {
        // Check if the click coordinates fall within the regions of the weapon icons
        if (x >= 100 && x <= 200 && y >= 100 && y <= 200) {
            selectedWeapon = RIFLE;
            cout << "Rifle selected!" << endl;
        } else if (x >= 250 && x <= 350 && y >= 100 && y <= 200) {
            selectedWeapon = GUN;
            cout << "Gun selected!" << endl;
        } else if (x >= 400 && x <= 500 && y >= 100 && y <= 200) {
            selectedWeapon = CANNON;
            cout << "Cannon selected!" << endl;
        } else if (x >= 250 && x <= 350 && y >= 220 && y <= 250) {
            startGame = true;
            cout << "Starting the game!" << endl;
        }
    }
}

int main() {
    int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Weapon Selection");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    // Draw the weapon icons on the screen
    outtextxy(130, 150, "Rifle");
    rectangle(100, 100, 200, 200);

    outtextxy(280, 150, "Gun");
    rectangle(250, 100, 350, 200);

    outtextxy(430, 150, "Cannon");
    rectangle(400, 100, 500, 200);

    // Draw the start button
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(270, 230, "Start");
    rectangle(250, 220, 350, 250);

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            handleClick(WM_LBUTTONDOWN, 0, x, y);
        }

        if (startGame) {
            // Start the game logic here
            cout << "Game started with weapon: ";
            switch (selectedWeapon) {
                case RIFLE:
                    cout << "Rifle" << endl;
                    break;
                case GUN:
                    cout << "Gun" << endl;
                    break;
                case CANNON:
                    cout << "Cannon" << endl;
                    break;
            }
            break;
        }

        delay(100);
    }

    closegraph();

    return 0;
}
