#include "obstacle.h"
#include <graphics.h>

Obstacle::Obstacle(const std::string& obstacleName, int obstaclePositionX, int obstaclePositionY, int obstacleWidth, int obstacleHeight)
    : obstacleName(obstacleName), positionX(obstaclePositionX), positionY(obstaclePositionY), width(obstacleWidth), height(obstacleHeight) {}

void Obstacle::moveLeft() {
    positionX -= 5;
}

void Obstacle::moveRight() {
    positionX += 5;
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
