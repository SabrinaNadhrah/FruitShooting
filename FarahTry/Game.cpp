#include <graphics.h>
#include <iostream>
#include <string>

using namespace std;

// Display Menu
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
}

// Class Character
class Character {
protected:
    string playerName;
    int positionX;
    int positionY;

public:
    Character(const std::string& playerName, int playerPositionX, int playerPositionY);
    virtual ~Character() {}

    void setPosition(int x);
    int getPosition() const;
    int getY() const;
    virtual void drawCharacter() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
};

Character::Character(const std::string& playerName, int playerPositionX, int playerPositionY)
    : playerName(playerName), positionX(playerPositionX), positionY(playerPositionY) {}

void Character::setPosition(int x) {
    positionX = x;
}

int Character::getPosition() const {
    return positionX;
}

int Character::getY() const {
    return positionY;
}

// Class Player1
class Player1 : public Character {
private:
    int size;
    int score;

public:
    Player1(const std::string& playerName, int playerPositionX, int playerPositionY);

    void drawCharacter() override;
    void moveLeft() override;
    void moveRight() override;
};

Player1::Player1(const std::string& playerName, int playerPositionX, int playerPositionY)
    : Character(playerName, playerPositionX, playerPositionY) {}

void Player1::drawCharacter() {
    int x = positionX;
    int y = positionY;

    // Draw the character using graphics library or other method
    readimagefile("cat.jpg", x, y, x + 150, y + 150);
}

void Player1::moveLeft() {
    positionX -= 5;
}

void Player1::moveRight() {
    positionX += 5;
}

// Class Player2
class Player2 : public Character {
private:
    int size;
    int health;

public:
    Player2(const std::string& playerName, int playerPositionX, int playerPositionY);

    void drawCharacter() override;
    void moveLeft() override;
    void moveRight() override;
};

Player2::Player2(const std::string& playerName, int playerPositionX, int playerPositionY)
    : Character(playerName, playerPositionX, playerPositionY) {}

void Player2::drawCharacter() {
    int x = positionX;
    int y = positionY;

    // Draw the character using graphics library or other method
    readimagefile("cat.jpg", x, y, x + 150, y + 150);
}

void Player2::moveLeft() {
    positionX -= 5;
}

void Player2::moveRight() {
    positionX += 5;
}

// Function to select game mode
int selectMode()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    // Clear the screen
    cleardevice();

    // Display mode selection menu
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(screenWidth / 2 - 200, screenHeight / 2 - 100, "Select Game Mode");

    // Display mode options
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(screenWidth / 2 - 100, screenHeight / 2, "1. Single Player");
    outtextxy(screenWidth / 2 - 100, screenHeight / 2 + 50, "2. Two Players");

    // Wait for user input
    int mode = 0;
    while (mode != 1 && mode != 2)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(100);
        }

        // Get mouse click coordinates
        int mouseX, mouseY;
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);

        // Check if the first option was clicked
        if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 && mouseY <= screenHeight / 2 + 20)
        {
            mode = 1;
        }
        // Check if the second option was clicked
        else if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 + 50 && mouseY <= screenHeight / 2 + 70)
        {
            mode = 2;
        }

        // Clear the mouse click event
        clearmouseclick(WM_LBUTTONDOWN);
    }

    return mode;
}

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Game Start");

    displayMenu();

    int gameMode = selectMode();

    if (gameMode == 1)
    {
        // Single Player Mode
        // Create and control one character (Player1)
        Player1 player1("Player 1", screenWidth / 2, screenHeight - 100);

        // Game loop
        while (!kbhit())
        {
            // Clear the screen
            cleardevice();

            // Update and draw the character
            player1.moveLeft(); // Example movement
            player1.drawCharacter();

            // Delay for smooth animation
            delay(100);
        }
    }
    else if (gameMode == 2)
    {
        // Two Players Mode
        // Create and control two characters (Player1 and Player2)
        Player1 player1("Player 1", screenWidth / 2 - 100, screenHeight - 100);
        Player2 player2("Player 2", screenWidth / 2 + 100, screenHeight - 100);

        // Game loop
        while (!kbhit())
        {
            // Clear the screen
            cleardevice();

            // Update and draw the characters
            player1.moveLeft(); // Example movement
            player1.drawCharacter();

            player2.moveRight(); // Example movement
            player2.drawCharacter();

            // Delay for smooth animation
            delay(100);
        }
    }

    closegraph();
    return 0;
}
