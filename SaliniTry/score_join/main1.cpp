#include <iostream>
#include <cstdlib>
#include <ctime>
#include <graphics.h>

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

Fruit::Fruit(int s, int sc) : size(s), score(sc) {
    direction = (rand() % 2 == 0) ? 1 : -1; // randomly assign direction
    x = (direction == 1) ? -size : screenWidth + size; // start offscreen based on direction
    y = rand() % (screenHeight / 2); // randomly position in the top half of the screen
}

Fruit::~Fruit() {}

void Fruit::move() {
    x += direction * fruitSpeed;
    if ((direction == 1 && x > screenWidth + size) || (direction == -1 && x < -size)) {
        x = (direction == 1) ? -size : screenWidth + size; // move offscreen when reached the edge
        y = rand() % (screenHeight / 2); // reposition in the top half of the screen
    }
}

void Fruit::setX(int xPos) {
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

class Score {
private:
    int max_value;
    int high_score;
    int current_score;
    int deduction_count;
    int marks_gained_count;
    int health; // New health variable

public:
    Score();

    int getScore() const;
    int getHighScore() const;
    int getDeductionCount() const;
    int getMarksGainedCount() const;
    int getHealth() const; // New health getter

    void updateScore(int marksGained, int deduction);
};

Score::Score() {
    max_value = 100;
    high_score = 0;
    current_score = 0;
    deduction_count = 0;
    marks_gained_count = 0;
    health = 100;
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

int Score::getHealth() const {
    return health;
}

void Score::updateScore(int marksGained, int deduction) {
    marks_gained_count += marksGained;
    deduction_count += deduction;

    if (marks_gained_count > max_value) {
        current_score += max_value;
        marks_gained_count -= max_value;
    }
    else {
        current_score += marksGained;
    }

    if (deduction_count > max_value) {
        current_score -= max_value;
        deduction_count -= max_value;
    }
    else {
        current_score -= deduction;
    }

    if (current_score < 0) {
        current_score = 0;
    }

    if (current_score > high_score) {
        high_score = current_score;
    }

    // Update health based on deduction
    health -= deduction;
    if (health < 0) {
        health = 0;
    }
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

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    initwindow(screenWidth, screenHeight, "Fruit Shooting Game");
    setbkcolor(WHITE);
    cleardevice();

    readimagefile("background.jpeg", 0, 0, screenWidth, screenHeight);
    void* imageBuffer = malloc(imagesize(0, 0, screenWidth, screenHeight));
    getimage(0, 0, screenWidth, screenHeight, imageBuffer);

    Fruit* fruits[numFruits];
    initializeFruits(fruits);

    while (!kbhit()) {
        cleardevice();

        putimage(0, 0, imageBuffer, COPY_PUT);

        for (int i = 0; i < numFruits; i++) {
            fruits[i]->move();
            fruits[i]->draw();
        }

        delay(10);
    }

    deleteFruits(fruits);
    free(imageBuffer);
    closegraph();

    return 0;
}
