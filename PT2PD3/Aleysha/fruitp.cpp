#include <graphics.h>
#include "fruit.h"

Fruit::Fruit(int s, int sc) : size(s), score(sc) {
    direction = (rand() % 2 == 0) ? 1 : -1; // randomly assign direction
    x = (direction == 1) ? -fruitWidth : screenWidth + fruitWidth; // start offscreen based on direction
    y = rand() % (screenHeight / 2); // randomly position in the top half of the screen
    size = 40;
}

Fruit::~Fruit() {}

void Fruit::move() {
    x += direction * fruitSpeed;
    if ((direction == 1 && x > screenWidth + fruitWidth) || (direction == -1 && x < -fruitWidth)) {
        x = (direction == 1) ? -fruitWidth : screenWidth + fruitWidth; // move offscreen when reached the edge
       y = rand() % (screenHeight / 2); // reposition in the top half of the screen
    }
}

void Fruit::draw() {
    // Draw fruit shape using rectangle
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, size, size);
    //rectangle(x - size, y - size, x + size, y + size);
    //floodfill(x, y, YELLOW);
}

void Fruit::setX(int newX) {
    x = newX;
}

void Fruit::setY(int newY) {
    y = newY;
}
