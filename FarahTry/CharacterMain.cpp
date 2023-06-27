#include <graphics.h>
#include "Character.h"
#include "Weapon.h"

class Player1 : public Character {
public:
    Player1(const std::string& playerName, int playerPositionX, int playerPositionY)
        : Character(playerName, playerPositionX, playerPositionY) {}

    void drawCharacter() override {
        int x = positionX;
        int y = positionY;

        // Draw the character using graphics library or other method
        readimagefile("cat.jpg", x, y, x + 150, y + 150);
    }

    void moveLeft() override {
        positionX -= 5;
    }

    void moveRight() override {
        positionX += 5;
    }
};

class Player2 : public Character {
public:
    Player2(const std::string& playerName, int playerPositionX, int playerPositionY)
        : Character(playerName, playerPositionX, playerPositionY) {}

    void drawCharacter() override {
        int x = positionX;
        int y = positionY;

        // Draw the character using graphics library or other method
        readimagefile("cat.jpg", x, y, x + 150, y + 150);
    }

    void moveLeft() override {
        positionX -= 5;
    }

    void moveRight() override {
        positionX += 5;
    }
};

void displayMenu()
{
    // Display menu implementation
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

    int character2X = screenWidth / 2; // start at the middle of the screen
    int character2Y = screenHeight - 230;
    int character1X = screenWidth / 2; // start at the middle of the screen
    int character1Y = screenHeight - 230;

    Player1 player1("Player1", character2X, character2Y);
    Player2 player2("Player2", character1X, character1Y);

    Weapon w1(screenWidth / 2, screenHeight - 100);
    char ch;

    int direction = 1;

    while (true)
    {
        delay(40);
        setactivepage(1);
        cleardevice();

        // Update player 1 position
        if (player1.getPosition() >= screenWidth)
            player1.moveLeft();
        else
            player1.moveRight();

        // Update player 2 position
        if (player2.getPosition() <= 0)
            player2.moveRight();
        else
            player2.moveLeft();

        // Draw player 1 at the updated position
        player1.drawCharacter();

        // Draw player 2 at the updated position
        player2.drawCharacter();

        setvisualpage(1);

        // Move the weapon
        w1.move(5 * direction);

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
        setactivepage(1);

        // Redraw the weapon
        cleardevice();
        w1.update();
        w1.draw();
    }

    closegraph();
    return 0;
}

       
