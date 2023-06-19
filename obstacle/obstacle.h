#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <string>
#include <graphics.h>

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

#endif // OBSTACLE_H
