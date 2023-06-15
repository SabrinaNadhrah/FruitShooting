#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <graphics.h>
#include <cmath>

class Obstacle {
private:
    int color;
    int dx;
    int dy;
    int radius;
    int x;
    int y;

public:
    Obstacle(int _color = WHITE, int _dx = 0, int _dy = 0, int _radius = 0, int _x = 0, int _y = 0);
    void setMovement(int _dx, int _dy);
    void reverseHorizontal();
    void draw() const;
    void undraw() const;
    void shift();
    void move();
};

#endif

