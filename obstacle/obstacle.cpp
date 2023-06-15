#include "obstacle.h"
#include <graphics.h>
#include "obstacle.h"

Obstacle::Obstacle(int _color, int _dx, int _dy, int _radius, int _x, int _y)
    : color(_color), dx(_dx), dy(_dy), radius(_radius), x(_x), y(_y) {}

void Obstacle::setMovement(int _dx, int _dy) {
    dx = _dx;
    dy = _dy;
}

void Obstacle::reverseHorizontal() {
    dx = -dx;
}

void Obstacle::draw() const {
    setfillstyle(SOLID_FILL, color);
    setcolor(color);
    fillellipse(x, y, radius, radius);
}

void Obstacle::undraw() const {
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(BLACK);
    fillellipse(x, y, radius, radius);
}

void Obstacle::shift() {
    x += dx;
    y += dy;
}

void Obstacle::move() {
    undraw();
    shift();
    draw();
}

int main() {
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Obstacle Demo");

    Obstacle obstacle1(WHITE, 5, 0, 25, 0, screenHeight / 2);
    Obstacle obstacle2(WHITE, -5, 0, 25, screenWidth, screenHeight / 2);

    while (!kbhit()) {
        obstacle1.move();
        obstacle2.move();
        delay(3);
    }

    closegraph();
    return 0;
}

