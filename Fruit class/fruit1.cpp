#include "fruit1.h"
#include <graphics.h>


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
