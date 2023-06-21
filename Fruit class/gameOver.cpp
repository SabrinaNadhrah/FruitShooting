#include <iostream>
#include <cstdlib>
#include <ctime>
#include <graphics.h>

const int screenWidth = 800;
const int screenHeight = 600;
const int fruitWidth = 200;
const int fruitHeight = 50;
const int fruitSpeed = 5;
const int numFruits = 10;
const int numBombs = 3;

class Fruit {
protected:
    int size;
    int score;
    int x;
    int y;
    int direction;
    int bombHits;

public:
    Fruit(int s, int sc) : size(s), score(sc), bombHits(0) {
        direction = (rand() % 2 == 0) ? 1 : -1; // randomly assign direction
        x = (direction == 1) ? -fruitWidth : screenWidth + fruitWidth; // start offscreen based on direction
        y = rand() % (screenHeight / 2); // randomly position in the top half of the screen
    }

    virtual ~Fruit() {}

    void move() {
        x += direction * fruitSpeed;
        if ((direction == 1 && x > screenWidth + fruitWidth) || (direction == -1 && x < -fruitWidth)) {
            x = (direction == 1) ? -fruitWidth : screenWidth + fruitWidth; // move offscreen when reached the edge
            y = rand() % (screenHeight / 2); // reposition in the top half of the screen
        }
    }

    void draw() {
        // Draw fruit shape using rectangle
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        rectangle(x - size, y - size, x + size, y + size);
        floodfill(x, y, YELLOW);
    }

    bool checkCollision(int bombX, int bombY, int bombWidth, int bombHeight) {
        if (x - size < bombX + bombWidth && x + size > bombX && y - size < bombY + bombHeight && y + size > bombY) {
            bombHits++;
            return true;
        }
        return false;
    }

    bool isGameOver() {
        return bombHits >= numBombs;
    }

    void setX(int xPos){
        x = xPos;
    }
    void setY(int yPos){
        y = yPos;
    }

    int getScore(){
        return score;
    }
};

void initializeFruits(Fruit* fruits[]) {
    for (int i = 0; i < numFruits; i++) {
        int randomSize = rand() % 3 + 1; // Randomly assign size 1, 2, or 3
        int randomScore = (4 - randomSize) * 2; // Calculate score based on size
        fruits[i] = new Fruit(randomSize, randomScore);
        fruits[i]->setX(rand() % (screenWidth - fruitWidth)); // Random x position
        fruits[i]->setY(rand() % (screenHeight / 2)); // Random y position within the top half of the screen
    }
}

void deleteFruits(Fruit* fruits[]) {
    for (int i = 0; i < numFruits; i++)
        delete fruits[i];
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    initwindow(screenWidth, screenHeight, "Fruit Shooting Game");
    setbkcolor(WHITE);
    cleardevice();

    // Load background image
    readimagefile("background.jpg", 0, 0, screenWidth, screenHeight);

    Fruit* fruits[numFruits];
    initializeFruits(fruits);

    int bombX = screenWidth / 2;
    int bombY = screenHeight - 50;
    int bombWidth = 50;
    int bombHeight = 50;
    int score = 0;

    while (!kbhit()) {
        cleardevice();

        // Draw background image
        //putimage(0, 0, &background);

        // Draw bomb
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        rectangle(bombX, bombY, bombX + bombWidth, bombY + bombHeight);
        floodfill(bombX + bombWidth / 2, bombY + bombHeight / 2, RED);

        for (int i = 0; i < numFruits; i++) {
            fruits[i]->move();
            fruits[i]->draw();

            if (fruits[i]->checkCollision(bombX, bombY, bombWidth, bombHeight)) {
                score += fruits[i]->getScore();
            }

            if (fruits[i]->isGameOver()) {
                // Game over condition
                outtextxy(screenWidth / 2 - 50, screenHeight / 2, "Game Over");
                getch();
                closegraph();
                return 0;
            }
        }

        delay(10);
    }

    deleteFruits(fruits);
    closegraph();

    return 0;
}
