#include <graphics.h>
#include <iostream>
#include <string>

using namespace std;

class Score {
private:
    int max_value;
    int high_score;
    int current_score;
    int deduction_count;
    int marks_gained_count;

public:
    Score();

    int getScore() const;
    int getHighScore() const;
    int getDeductionCount() const;
    int getMarksGainedCount() const;

    void updateScore(int marksGained, int deduction);

    void drawScoreboard() const;
};

Score::Score() {
    max_value = 100;
    high_score = 0;
    current_score = 0;
    deduction_count = 0;
    marks_gained_count = 0;
}

int Score::getScore() const {
    return current_score;
}

int Score::getHighScore() const {
    return high_score;
}

int Score::getDeductionCount() const {
    return deduction_count;
}

int Score::getMarksGainedCount() const {
    return marks_gained_count;
}

void Score::updateScore(int marksGained, int deduction) {
    current_score += marksGained - deduction;

    if (current_score > high_score) {
        high_score = current_score;
    }

    if (deduction > 0) {
        deduction_count++;
    }

    if (marksGained > 0) {
        marks_gained_count++;
    }
}

void Score::drawScoreboard() const {
    
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(5, 5, 220, 80); // Example background rectangle
   
    

    // Convert the score, deduction count, and marks gained count to strings
    std::string scoreText = "Score: " + std::to_string(current_score);
    std::string deductionText = "Deductions: " + std::to_string(deduction_count);
    std::string marksGainedText = "Marks Gained: " + std::to_string(marks_gained_count);

    // Convert the strings to char arrays
    char scoreStr[50];
    char deductionStr[50];
    char marksGainedStr[50];
    strcpy(scoreStr, scoreText.c_str());
    strcpy(deductionStr, deductionText.c_str());
    strcpy(marksGainedStr, marksGainedText.c_str());

    setbkcolor(WHITE);
    setcolor(BLACK); // Set the text color to black
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    // Display the current score, deduction count, and marks gained count
    outtextxy(8, 10, scoreStr);
    outtextxy(8, 30, deductionStr);
    outtextxy(8, 50, marksGainedStr);

    // Close graphics window
    getch();
    closegraph();
}


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
        delay(50);
    }

    // Clear the mouse click event
    clearmouseclick(WM_LBUTTONDOWN);

    // Delay to allow the graphics window to refresh
    delay(200);
}

// Class Character
class Character
{
protected:
    string playerName;
    int positionX;
    int positionY;
    int direction; // New member to store the character's movement direction (-1 for left, 1 for right)

public:
    Character(const std::string &playerName, int playerPositionX, int playerPositionY);
    virtual ~Character() {}
    int getDirection() const
    {
        return direction;
    }
    void setPosition(int x);
    int getPosition() const;
    int getY() const;
    virtual void drawCharacter() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
};

Character::Character(const std::string &playerName, int playerPositionX, int playerPositionY)
    : playerName(playerName), positionX(playerPositionX), positionY(playerPositionY), direction(1) {} // Set default direction to right (1)

void Character::setPosition(int x)
{
    positionX = x;
}

int Character::getPosition() const
{
    return positionX;
}

int Character::getY() const
{
    return positionY;
}

// Class Player1
class Player1 : public Character
{
private:
    int size;
    int score;

public:
    Player1(const std::string &playerName, int playerPositionX, int playerPositionY);

    void drawCharacter() override;
    void moveLeft() override;
    void moveRight() override;
};

Player1::Player1(const std::string &playerName, int playerPositionX, int playerPositionY)
    : Character(playerName, playerPositionX, playerPositionY) {}

void Player1::drawCharacter()
{
    int x = positionX;
    int y = positionY;

    // Draw the character using graphics library or other method
    readimagefile("cat.jpg", x, y, x + 150, y + 150);
}

void Player1::moveLeft()
{
    positionX -= 20 * direction;

    // Reverse direction if the character reaches the left or right edge
    if (positionX <= 0 || positionX + 150 > getmaxwidth())
    {
        direction *= -1;
        if (positionX <= 0)
            positionX = 0;
        else
            positionX = getmaxwidth() - 150;
    }
}

void Player1::moveRight()
{
    positionX += 20 * direction;

    // Reverse direction if the character reaches the left or right edge
    if (positionX <= 0 || positionX + 150 > getmaxwidth())
    {
        direction *= -1;
        if (positionX <= 0)
            positionX = 0;
        else
            positionX = getmaxwidth() - 150;
    }
}

// Class Player2
class Player2 : public Character
{
private:
    int size;
    int health;

public:
    Player2(const std::string &playerName, int playerPositionX, int playerPositionY);

    void drawCharacter() override;
    void moveLeft() override;
    void moveRight() override;
};

Player2::Player2(const std::string &playerName, int playerPositionX, int playerPositionY)
    : Character(playerName, playerPositionX, playerPositionY) {}

void Player2::drawCharacter()
{
    int x = positionX;
    int y = positionY;

    // Draw the character using graphics library or other method
    readimagefile("cat.jpg", x, y, x + 150, y + 150);
}

void Player2::moveLeft()
{
    positionX -= 20 * direction;

    // Reverse direction if the character reaches the left or right edge
    if (positionX <= 0 || positionX + 150 > getmaxwidth())
    {
        direction *= -1;
        if (positionX <= 0)
            positionX = 0;
        else
            positionX = getmaxwidth() - 150;
    }
}

void Player2::moveRight()
{
    positionX += 20 * direction;

    // Reverse direction if the character reaches the left or right edge
    if (positionX <= 0 || positionX + 150 > getmaxwidth())
    {
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
const int fruitSpeed = 30;
const int numFruits = 10;

class Fruit
{
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

class SmallFruit : public Fruit
{
public:
    SmallFruit();
    void move() override;
    void draw() override;
};

class MediumFruit : public Fruit
{
public:
    MediumFruit();
    void move() override;
    void draw() override;
};

class BigFruit : public Fruit
{
public:
    BigFruit();
    void move() override;
    void draw() override;
};
// class implementation code fruit
Fruit::Fruit(int s, int sc) : size(s), score(sc)
{
    direction = (rand() % 2 == 0) ? 1 : -1;            // randomly assign direction
    x = (direction == 1) ? -size : screenWidth + size; // start offscreen based on direction
    y = rand() % (screenHeight / 2);                   // randomly position in the top half of the screen
}

Fruit::~Fruit() {}

void Fruit::move()
{
    x += direction * fruitSpeed;
    if ((direction == 1 && x > screenWidth + size) || (direction == -1 && x < -size))
    {
        x = (direction == 1) ? -size : screenWidth + size; // move offscreen when reached the edge
        y = rand() % (screenHeight / 2);                   // reposition in the top half of the screen
    }
}

void Fruit::setX(int xPos)
{
    x = xPos;
}

void Fruit::setY(int yPos)
{
    y = yPos;
}

SmallFruit::SmallFruit() : Fruit(1, 6)
{
    size = 20;
}

void SmallFruit::move()
{
    x += direction * fruitSpeed;
    if ((direction == 1 && x > screenWidth + size) || (direction == -1 && x < -size))
    {
        x = (direction == 1) ? -size : screenWidth + size; // move offscreen when reached the edge
        y = rand() % (screenHeight / 2);                   // reposition in the top half of the screen
    }
}

void SmallFruit::draw()
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, size, size);
}

MediumFruit::MediumFruit() : Fruit(2, 4)
{
    size = 30;
}

void MediumFruit::move()
{
    x += direction * fruitSpeed;
    if ((direction == 1 && x > screenWidth + size) || (direction == -1 && x < -size))
    {
        x = (direction == 1) ? -size : screenWidth + size; // move offscreen when reached the edge
        y = rand() % (screenHeight / 2);                   // reposition in the top half of the screen
    }
}

void MediumFruit::draw()
{
    setcolor(ERANGE);
    setfillstyle(SOLID_FILL, ERANGE);
    fillellipse(x, y, size, size);
}

BigFruit::BigFruit() : Fruit(3, 2)
{
    size = 40;
}

void BigFruit::move()
{
    x += direction * fruitSpeed;
    if ((direction == 1 && x > screenWidth + size) || (direction == -1 && x < -size))
    {
        x = (direction == 1) ? -size : screenWidth + size; // move offscreen when reached the edge
        y = rand() % (screenHeight / 2);                   // reposition in the top half of the screen
    }
}

void BigFruit::draw()
{
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, size, size);
}
void initializeFruits(Fruit *fruits[])
{
    for (int i = 0; i < numFruits; i++)
    {
        int randomSize = rand() % 3 + 1; // Randomly assign size 1, 2, or 3
        switch (randomSize)
        {
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
        fruits[i]->setY(rand() % (screenHeight / 4));         // Random y position within the top half of the screen
    }
}

void deleteFruits(Fruit *fruits[])
{
    for (int i = 0; i < numFruits; i++)
        delete fruits[i];
}
// obstacle class
class Obstacle
{
private:
    std::string obstacleName;
    int positionX;
    int positionY;
    int width;
    int height;

public:
    Obstacle(const std::string &obstacleName, int obstaclePositionX, int obstaclePositionY, int obstacleWidth, int obstacleHeight);
    void drawObstacle() const;
    void undrawObstacle() const;
    void moveLeft();
    void moveRight();
    int getPosition() const;
    void setPosition(int x);
    int getY() const;
};

Obstacle::Obstacle(const std::string &obstacleName, int obstaclePositionX, int obstaclePositionY, int obstacleWidth, int obstacleHeight)
    : obstacleName(obstacleName), positionX(obstaclePositionX), positionY(obstaclePositionY), width(obstacleWidth), height(obstacleHeight) {}

void Obstacle::moveLeft()
{
    positionX -= 10;
}

void Obstacle::moveRight()
{
    positionX += 10;
}

int Obstacle::getPosition() const
{
    return positionX;
}

void Obstacle::setPosition(int x)
{
    positionX = x;
}

int Obstacle::getY() const
{
    return positionY;
}

void Obstacle::drawObstacle() const
{
    int x = positionX;
    int y = positionY;

    readimagefile("obstacle1.jpg", x, y, x + width - 1, y + height - 1);
}

void Obstacle::undrawObstacle() const
{
    int x = positionX;
    int y = positionY;

    setfillstyle(SOLID_FILL, WHITE);
    bar(x, y, x + width, y + height);
}
// Weapon & bullet
const int MAXBULLET = 100;

// Forward declaration of the Weapon class
class Weapon;

class Bullet
{
private:
    int x, y;
    int size;
    int color;
    int speed;
    bool active;
    Weapon *weapon; // Forward declaration allows using the pointer to Weapon

public:
    Bullet(int _x = 0, int _y = 0, int _size = 10, int _color = BLUE, int _speed = 10);

    int getY() const;
    bool getActive() const;
    void setWeapon(Weapon *w);

    void draw() const;
    void undraw() const;
    void move();
    void reset();
};

class Weapon
{
private:
    int x, y;
    int width, height;
    int color;
    Bullet *bullets; // Use the pointer to Bullet
    std::string imagePath;

public:
    Weapon(int _x = 0, int _y = 0, int _width = 150, int _height = 100, int _color = BLACK);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    void shoot();
    void draw() const;
    void undraw() const;
    void move(int dx);
    void doAction();
    int getPosition() const;
    void update();
    void setImagePath(const std::string &path);
};

// Implement the Bullet class methods

Bullet::Bullet(int _x, int _y, int _size, int _color, int _speed)
    : x(_x), y(_y), size(_size), color(_color), speed(_speed), weapon(nullptr), active(false)
{
}

int Bullet::getY() const
{
    return y;
}

bool Bullet::getActive() const
{
    return active;
}

void Bullet::setWeapon(Weapon *w)
{
    weapon = w;
}

void Bullet::draw() const
{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(x, y, size, size);
}

void Bullet::undraw() const
{
    // Optional: Implement undraw functionality if needed
}

void Bullet::move()
{
    if (!active)
        return;
    undraw();
    y -= speed;

    if (y > 0)
        draw();
    else
        active = false;
}

void Bullet::reset()
{
    x = weapon->getX() + weapon->getWidth() / 2;
    y = weapon->getY() - size;
    active = true;
}

// Implement the Weapon class methods

Weapon::Weapon(int _x, int _y, int _width, int _height, int _color)
    : x(_x), y(_y), width(_width), height(_height), color(_color)
{
    bullets = new Bullet[MAXBULLET];
    for (int i = 0; i < MAXBULLET; i++)
    {
        bullets[i].setWeapon(this);
    }
}

int Weapon::getX() const
{
    return x;
}

int Weapon::getY() const
{
    return y;
}

int Weapon::getWidth() const
{
    return width;
}

int Weapon::getHeight() const
{
    return height;
}

void Weapon::shoot()
{
    int foundAt = -1;
    for (int i = 0; i < MAXBULLET; i++)
    {
        if (!bullets[i].getActive())
        {
            foundAt = i;
            break;
        }
    }

    if (foundAt != -1)
    {
        bullets[foundAt].reset();
        bullets[foundAt].draw();
    }
}

void Weapon::draw() const
{
    readimagefile(imagePath.c_str(), x, y, x + width, y + height);
}

void Weapon::undraw() const
{
    // Optional: Implement undraw functionality if needed
}

void Weapon::move(int dx)
{
    undraw();
    x += dx;
    draw();
}

void Weapon::doAction()
{
    for (int i = 0; i < MAXBULLET; i++)
    {
        bullets[i].move();
    }
}

int Weapon::getPosition() const
{
    return x;
}

void Weapon::update()
{
    // Optional: Implement update functionality if needed
}

void Weapon::setImagePath(const std::string &path)
{
    imagePath = path;
}

int chooseWeaponPage()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Choose Weapon");

    // Display the available weapons and let the player choose
    int choice = 1;
    while (choice < 1 || choice > 3)
    {
        cleardevice();
        outtextxy(screenWidth / 2 - 50, screenHeight / 2 - 30, "Choose a Weapon:");
        outtextxy(screenWidth / 2 - 60, screenHeight / 2, "1. Rifle");
        outtextxy(screenWidth / 2 - 60, screenHeight / 2 + 20, "2. Cannon");
        outtextxy(screenWidth / 2 - 60, screenHeight / 2 + 40, "3. Gun");

        char ch = getch();
        if (ch >= '1' && ch <= '3')
        {
            choice = ch - '0';
        }
    }

    closegraph();
    return choice;
}

//aleysha
/*class Score{
    protected:
        int sc;
        Character *character;

    public:
        Score() : sc(0), character(nullptr) {}
       // Score(int initialSc, Character *character) : character(initialSc), character(character) {}
        Character *getCharacter() const {return character;}
        void hitSmallFruit() {sc += 6; }
        void hitMedFruit() { sc += 4; }
        void hitBigFruit() { sc += 2; }
        void hitObstacle() { sc -= 5; }
        void setSc(int s){sc = s;}
        int getSc() const {return sc; }
};
//aleysha
void displayDashboard(int score, int timeRemaining){
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    setcolor(BLACK);

    string playerScore = "Score: " + to_string(score);
    char scoreStr[playerScore.length() + 1];
    strcpy(scoreStr, playerScore.c_str());

    string timeStr = "Time: " + to_string(timeRemaining) + " s";
    char timeRemainingStr[timeStr.length() + 1];
    strcpy(timeRemainingStr, timeStr.c_str());

    //int leftX = 10;
    int centerX = getmaxx() / 2 - textwidth(scoreStr) / 2;
    int rightX = getmaxx() - textwidth(timeRemainingStr) - 10;

    outtextxy(centerX, 10, scoreStr);
    outtextxy(rightX, 10, timeRemainingStr);
}*/

int main()
{   
    int page = 0;
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Game Start");
    readimagefile("background.jpg", 0, 0, screenWidth, screenHeight);

    // Start Page
    displayMenu();
    // select gamemode
    int gameMode = selectMode();
    // Weapon page
    int choice = 1;
    // choice = chooseWeaponPage();

    // start weapon
    Weapon w1(screenWidth / 2, screenHeight - 230);
    Weapon w2(screenWidth / 2, screenHeight - 230);

    std::string weaponImagePath;
    if (choice == 1)
    {
        // Rifle
        weaponImagePath = "riffle.jpg";
    }
    else if (choice == 2)
    {
        // Cannon
        weaponImagePath = "cannon.jpg";
    }
    else if (choice == 3)
    {
        // Gun
        weaponImagePath = "gunn.jpg";
    }
    w1.setImagePath(weaponImagePath);
    w2.setImagePath(weaponImagePath);

    char ch;

    int direction = 1;
    // end weapon

    Fruit *fruits[numFruits];
    initializeFruits(fruits);
    // start boom
    int obstacleWidth = 100;  // Adjust with the actual width of your obstacle image
    int obstacleHeight = 100; // Adjust with the actual height of your obstacle image

    int obstacle1X = screenWidth / 2 - obstacleWidth / 2; // start at the middle of the screen
    int obstacle1Y = screenHeight / 2 - obstacleHeight / 2;

    int obstacle2X = screenWidth / 2 - obstacleWidth / 2;         // start at the middle of the screen
    int obstacle2Y = screenHeight / 2 - obstacleHeight / 2 - 100; // adjust the obstacle's Y position above the first obstacle

    Obstacle obstacle1("Obstacle1", obstacle1X, obstacle1Y, obstacleWidth, obstacleHeight);
    Obstacle obstacle2("Obstacle2", obstacle2X, obstacle2Y, obstacleWidth, obstacleHeight);
    // end boom

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
            //double buffering
            setactivepage(page);           
            setvisualpage(1-page);

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

            for (int i = 0; i < numFruits; i++)
            {
                fruits[i]->move();
                fruits[i]->draw();
            }

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

            // Redraw the weapon
            w1.update();
            w1.draw();

            // Update the character's position based on the direction
            player1.setPosition(player1.getPosition() + 5 * direction);

            /*
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
                        } */

            // Draw the character
            player1.drawCharacter();            
            
            page = 1 - page;
            // Delay for smooth animation
            delay(100);
                Score score;

    // Update the score with example values
    score.updateScore(10, 0); // Marks gained: 10, Deduction: 0
    score.updateScore(0, 4); // Marks gained: 0, Deduction: 4
    score.updateScore(8, 2); // Marks gained: 8, Deduction: 2

    // Display the scoreboard
    score.drawScoreboard();

    // Access and display the current score, high score, deduction count, and marks gained count
    std::cout << "Current Score: " << score.getScore() << std::endl;
    std::cout << "High Score: " << score.getHighScore() << std::endl;
    std::cout << "Deduction Count: " << score.getDeductionCount() << std::endl;
    std::cout << "Marks Gained Count: " << score.getMarksGainedCount() << std::endl;

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
        int page2 = 0;
        while (true)
        {
            // Clear the screen
            //double buffering
            
            setactivepage(page2);           
            setvisualpage(1-page2);

            readimagefile("background.jpg", 0, 0, screenWidth, screenHeight);
            for (int i = 0; i < numFruits; i++)
            {
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
            w2.move(-10 * direction);

            // Reverse direction if the weapon reaches the screen boundaries
            if (w2.getPosition() <= 0 || w2.getPosition() >= (screenWidth - 155))
                direction *= -1;

            w2.doAction();

            if (kbhit())
            {
                ch = getch();

                if (ch == 27)
                    break;
                else if (ch == ' ')
                    w1.shoot();
            }

            // Redraw the weapon
            w2.update();
            w2.draw();

            player2.moveRight();
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

            // Redraw the weapon
            w1.update();
            w1.draw();
            // Draw the characters
            player1.drawCharacter();
            player2.drawCharacter();

            page2 = 1 - page2;

            // Delay for smooth animation
            delay(100);
                Score score;

    // Update the score with example values
    score.updateScore(10, 0); // Marks gained: 10, Deduction: 0
    score.updateScore(0, 4); // Marks gained: 0, Deduction: 4
    score.updateScore(8, 2); // Marks gained: 8, Deduction: 2

    // Display the scoreboard
    score.drawScoreboard();

    // Access and display the current score, high score, deduction count, and marks gained count
    std::cout << "Current Score: " << score.getScore() << std::endl;
    std::cout << "High Score: " << score.getHighScore() << std::endl;
    std::cout << "Deduction Count: " << score.getDeductionCount() << std::endl;
    std::cout << "Marks Gained Count: " << score.getMarksGainedCount() << std::endl;

        }
    }
    

    closegraph();
    return 0;
}
