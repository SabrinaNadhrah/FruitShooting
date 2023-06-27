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
    outtextxy(screenWidth / 2 - 240, screenHeight / 2 - 100, "Welcome to Aim and Fire!");

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

void WeaponPage(){

    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    
    setbkcolor(BLACK);
    cleardevice();

    int option = 0;
    int mouseX, mouseY;

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            mouseX = mousex();
            mouseY = mousey();

            if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 - 50 && mouseY <= screenHeight / 2 + 50) {
                option = 1; // 1 player selected
                break;
            } else if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 + 100 && mouseY <= screenHeight / 2 + 200) {
                option = 2; // 2 players selected
                break;
            } else if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 + 250 && mouseY <= screenHeight / 2 + 350) {
                option = 3; // Cannon selected
                break;
            }
        }

        setcolor(WHITE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 3);
        outtextxy(screenWidth / 2 - 80, screenHeight / 2 - 100, "Choose Your Weapon!");
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        // Draw 1 player button with Rifle image
        readimagefile("riffle.jpg", screenWidth / 2 - 100, screenHeight / 2 - 50, screenWidth / 2 + 100, screenHeight / 2 + 50);
        outtextxy(screenWidth / 2 - 30, screenHeight / 2 + 60, "Rifle");

        // Draw 2 players button with Gun image
        readimagefile("gunn.jpg", screenWidth / 2 - 100, screenHeight / 2 + 100, screenWidth / 2 + 100, screenHeight / 2 + 200);
        outtextxy(screenWidth / 2 - 25, screenHeight / 2 + 210, "Gun");

        // Draw Cannon button with Cannon image
        readimagefile("cannon.jpg", screenWidth / 2 - 100, screenHeight / 2 + 250, screenWidth / 2 + 100, screenHeight / 2 + 350);
        outtextxy(screenWidth / 2 - 40, screenHeight / 2 + 360, "Cannon");

        if (option != 0)
            break;
        //delay(100);
    }
     // Clear the screen
    cleardevice();

    // Display the selected option
    /*string weapon;
    if (option == 1)
        weapon = "Rifle";
    else if (option == 2)
        weapon = "Gun";
    else if (option == 3)
        weapon = "Cannon";

    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(screenWidth / 2 - 100, screenHeight / 2 - 50, "You chose:");
    //outtextxy(screenWidth / 2 - 80, screenHeight / 2 + 50, weapon);*/

    // Wait for a key press
    while (!kbhit())
    {
        delay(100);
    }

    /*closegraph();

    // Use the selected option here
    if (option == 1) {
        std::cout << "Rifle selected" << std::endl;
        // Add code for 1 player game with Rifle
    } else if (option == 2) {
        std::cout << "Gun selected" << std::endl;
        // Add code for 2 player game with Gun
    } else if (option == 3) {
        std::cout << "Cannon selected" << std::endl;
        // Add code for Cannon game
    }*/

}
// Class Character
class Character {
protected:
    string playerName;
    int positionX;
    int positionY;
    int direction;  // New member to store the character's movement direction (-1 for left, 1 for right)

public:
    Character(const std::string& playerName, int playerPositionX, int playerPositionY);
    virtual ~Character() {}
    int getDirection() const {
        return direction;
    }
    void setPosition(int x);
    int getPosition() const;
    int getY() const;
    virtual void drawCharacter() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
};

Character::Character(const std::string& playerName, int playerPositionX, int playerPositionY)
    : playerName(playerName), positionX(playerPositionX), positionY(playerPositionY), direction(1) {}  // Set default direction to right (1)

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
    positionX -= 20 * direction;

    // Reverse direction if the character reaches the left or right edge
    if (positionX <= 0 || positionX + 150 > getmaxwidth()) {
        direction *= -1;
        if (positionX <= 0)
            positionX = 0;
        else
            positionX = getmaxwidth() - 150;
    }
}

void Player1::moveRight() {
    positionX += 20 * direction;

    // Reverse direction if the character reaches the left or right edge
    if (positionX <= 0 || positionX + 150 > getmaxwidth()) {
        direction *= -1;
        if (positionX <= 0)
            positionX = 0;
        else
            positionX = getmaxwidth() - 150;
    }
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
    positionX -= 20 * direction;

    // Reverse direction if the character reaches the left or right edge
    if (positionX <= 0 || positionX + 150 > getmaxwidth()) {
        direction *= -1;
        if (positionX <= 0)
            positionX = 0;
        else
            positionX = getmaxwidth() - 150;
    }
}

void Player2::moveRight() {
    positionX += 20 * direction;

    // Reverse direction if the character reaches the left or right edge
    if (positionX <= 0 || positionX + 150 > getmaxwidth()) {
        direction *= -1;
        if (positionX <= 0)
            positionX = 0;
        else
            positionX = getmaxwidth() - 150;
    }
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
// fruit
const int screenWidth = getmaxwidth();
const int screenHeight = getmaxheight();
const int fruitWidth = 200;
const int fruitHeight = 50;
const int fruitSpeed = 5;
const int numFruits = 10;

class Fruit {
protected:
    int size;
    int score;
    int x;
    int y;
    int direction;

public:
    Fruit(int s, int sc);
    virtual ~Fruit();

 
    virtual void move();
    virtual void draw() = 0;
    void setX(int xPos);
    void setY(int yPos);
};

class SmallFruit : public Fruit {
public:
    SmallFruit();
    void move() override;
    void draw() override;
};

class MediumFruit : public Fruit {
public:
    MediumFruit();
    void move() override;
    void draw() override;
};

class BigFruit : public Fruit {
public:
    BigFruit();
    void move() override;
    void draw() override;
};
// class implementation code fruit
Fruit::Fruit(int s, int sc) : size(s), score(sc) {
     direction = (rand() % 2 == 0) ? 1 : -1; // randomly assign direction
        x = (direction == 1) ? -size : screenWidth + size; // start offscreen based on direction
        y = rand() % (screenHeight / 2); // randomly position in the top half of the screen
}

Fruit::~Fruit() {}

void Fruit::move()
{
    x += direction * fruitSpeed;
        if ((direction == 1 && x > screenWidth + size) || (direction == -1 && x < -size)) {
            x = (direction == 1) ? -size : screenWidth + size; // move offscreen when reached the edge
            y = rand() % (screenHeight / 2); // reposition in the top half of the screen
        }
}

void Fruit::setX(int xPos)
{
    x = xPos;
}

void Fruit::setY(int yPos) {
    y = yPos;
}

SmallFruit::SmallFruit() : Fruit(1, 6) {
    size = 20;
}

void SmallFruit::move() {
    x += direction * fruitSpeed;
        if ((direction == 1 && x > screenWidth + size) || (direction == -1 && x < -size)) {
            x = (direction == 1) ? -size : screenWidth + size; // move offscreen when reached the edge
            y = rand() % (screenHeight / 2); // reposition in the top half of the screen
        }
}

void SmallFruit::draw() {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, size, size);
}

MediumFruit::MediumFruit() : Fruit(2, 4) {
    size = 30;
}

void MediumFruit::move() {
    x += direction * fruitSpeed;
        if ((direction == 1 && x > screenWidth + size) || (direction == -1 && x < -size)) {
            x = (direction == 1) ? -size : screenWidth + size; // move offscreen when reached the edge
            y = rand() % (screenHeight / 2); // reposition in the top half of the screen
        }
}

void MediumFruit::draw() {
    setcolor(ERANGE);
    setfillstyle(SOLID_FILL, ERANGE);
    fillellipse(x, y, size, size);
}

BigFruit::BigFruit() : Fruit(3, 2) {
    size = 40;
}

void BigFruit::move() {
    x += direction * fruitSpeed;
        if ((direction == 1 && x > screenWidth + size) || (direction == -1 && x < -size)) {
            x = (direction == 1) ? -size : screenWidth + size; // move offscreen when reached the edge
            y = rand() % (screenHeight / 2); // reposition in the top half of the screen
        }
}

void BigFruit::draw() {
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, size, size);
}
void initializeFruits(Fruit* fruits[]) {
    for (int i = 0; i < numFruits; i++) {
        int randomSize = rand() % 3 + 1; // Randomly assign size 1, 2, or 3
        switch (randomSize) {
            case 1:
                fruits[i] = new SmallFruit();
                break;
            case 2:
                fruits[i] = new MediumFruit();
                break;
            case 3:
                fruits[i] = new BigFruit();
                break;
        }
        
        fruits[i]->setX(rand() % (screenWidth - fruitWidth)); // Random x position
        fruits[i]->setY(rand() % (screenHeight / 4)); // Random y position within the top half of the screen
    }
}

void deleteFruits(Fruit* fruits[]) {
    for (int i = 0; i < numFruits; i++)
        delete fruits[i];
}
//obstacle class
class Obstacle {
private:
    std::string obstacleName;
    int positionX;
    int positionY;
    int width;
    int height;

public:
    Obstacle(const std::string& obstacleName, int obstaclePositionX, int obstaclePositionY, int obstacleWidth, int obstacleHeight);
    void drawObstacle() const;
    void undrawObstacle() const;
    void moveLeft();
    void moveRight();
    int getPosition() const;
    void setPosition(int x);
    int getY() const;
};

Obstacle::Obstacle(const std::string& obstacleName, int obstaclePositionX, int obstaclePositionY, int obstacleWidth, int obstacleHeight)
    : obstacleName(obstacleName), positionX(obstaclePositionX), positionY(obstaclePositionY), width(obstacleWidth), height(obstacleHeight) {}

void Obstacle::moveLeft() {
    positionX -= 10;
}

void Obstacle::moveRight() {
    positionX += 10;
}

int Obstacle::getPosition() const {
    return positionX;
}

void Obstacle::setPosition(int x) {
    positionX = x;
}

int Obstacle::getY() const {
    return positionY;
}

void Obstacle::drawObstacle() const {
    int x = positionX;
    int y = positionY;


    readimagefile("obstacle1.jpg", x, y, x + width - 1, y + height - 1);
}


void Obstacle::undrawObstacle() const {
    int x = positionX;
    int y = positionY;

    setfillstyle(SOLID_FILL, WHITE);
    bar(x, y, x + width, y + height);
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "");
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Game Start");
    readimagefile("background.jpg", 0, 0, screenWidth, screenHeight);
    
    //Start Page
    displayMenu();
    //Weapon page
    WeaponPage(); //belum link


    Fruit* fruits[numFruits];
    initializeFruits(fruits);
//start boom
int obstacleWidth = 100; // Adjust with the actual width of your obstacle image
    int obstacleHeight = 100; // Adjust with the actual height of your obstacle image

    int obstacle1X = screenWidth / 2 - obstacleWidth / 2; // start at the middle of the screen
    int obstacle1Y = screenHeight / 2 - obstacleHeight / 2;

    int obstacle2X = screenWidth / 2 - obstacleWidth / 2; // start at the middle of the screen
    int obstacle2Y = screenHeight / 2 - obstacleHeight / 2 - 100; // adjust the obstacle's Y position above the first obstacle

    Obstacle obstacle1("Obstacle1", obstacle1X, obstacle1Y, obstacleWidth, obstacleHeight);
    Obstacle obstacle2("Obstacle2", obstacle2X, obstacle2Y, obstacleWidth, obstacleHeight);
//end boom
    int gameMode = selectMode();

    if (gameMode == 1)
    {
        // Single Player Mode
// Create and control one character (Player1)
Player1 player1("Player 1", screenWidth / 2, screenHeight - 100);

// Set initial direction to right
int direction = 1;

// Game loop
while (true)
{
    // Clear the screen
    cleardevice();
    setactivepage;
    readimagefile("background.jpg", 0, 0, screenWidth, screenHeight);
    // Move and draw the obstacles
    obstacle1.undrawObstacle();
    obstacle1.moveRight();
    if (obstacle1.getPosition() >= screenWidth - obstacleWidth)
        obstacle1.setPosition(0);
    obstacle1.drawObstacle();

    obstacle2.undrawObstacle();
    obstacle2.moveLeft();
    if (obstacle2.getPosition() <= 0)
        obstacle2.setPosition(screenWidth - obstacleWidth);
    obstacle2.drawObstacle();

    for (int i = 0; i < numFruits; i++) {
            fruits[i]->move();
            fruits[i]->draw();
        }
    
    
    // Update the character's position based on the direction
    player1.setPosition(player1.getPosition() + 5 * direction);

    // Check if the character reaches the screen boundaries
    if (player1.getPosition() < 0)
    {
        // Change direction to right if character reaches the left edge
        direction = 1;
        player1.setPosition(0); // Set character position to the left edge
    }
    else if (player1.getPosition() + 150 > screenWidth)
    {
        // Change direction to left if character reaches the right edge
        direction = -1;
        player1.setPosition(screenWidth - 150); // Set character position to the right edge
    }
     

    // Draw the character
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
// Game loop
while (true)
{
    // Clear the screen
    cleardevice();
    readimagefile("background.jpg", 0, 0, screenWidth, screenHeight);
    for (int i = 0; i < numFruits; i++) {
            fruits[i]->move();
            fruits[i]->draw();
        }

    // Move and draw the obstacles
    obstacle1.undrawObstacle();
    obstacle1.moveRight();
    if (obstacle1.getPosition() >= screenWidth - obstacleWidth)
        obstacle1.setPosition(0);
    obstacle1.drawObstacle();

    obstacle2.undrawObstacle();
    obstacle2.moveLeft();
    if (obstacle2.getPosition() <= 0)
        obstacle2.setPosition(screenWidth - obstacleWidth);
    obstacle2.drawObstacle();
    // Update the characters' positions
    player1.moveLeft();
    player2.moveRight();

    // Check if Player1 reaches the left or right edge
if (player1.getPosition() <= 0)
{
    player1.moveRight();  // Reverse direction
    player1.setPosition(0);  // Set character position to the left edge
}
else if (player1.getPosition() + 150 > screenWidth)
{
    player1.moveLeft();  // Reverse direction
    player1.setPosition(screenWidth - 150);  // Set character position to the right edge
}


// Check if Player2 reaches the left or right edge
if (player2.getPosition() <=0)
{
    player2.moveRight();  // Reverse direction
    player2.setPosition(0);  // Set character position to the left edge
}
else if (player2.getPosition() + 150 > screenWidth)
{
    player2.moveLeft();  // Reverse direction
    player2.setPosition(screenWidth - 150);  // Set character position to the right edge
}

    // Draw the characters
    player1.drawCharacter();
    player2.drawCharacter();

    // Delay for smooth animation
    delay(100);
}


    }

    closegraph();
    return 0;
}
