#ifndef FRUIT_H
#define FRUIT_H

const int screenWidth = getmaxwidth();
const int screenHeight = getmaxheight();
const int fruitWidth = 200;
const int fruitHeight = 50;
const int fruitSpeed = 5;
const int numFruits = 10;

class Fruit {
private:
    int size; //represents the size of the fruit
    int score; //represents the score associated with the fruit
    int x; //store the current position of the fruit on the screen
    int y; //store the current position of the fruit on the screen
    int direction; //store the direction of the fruit on the screen

public:
    Fruit(int s, int sc);
    virtual ~Fruit();
    void move();
    void draw();
    void setX(int newX);
    void setY(int newY);
};

#endif // FRUIT_H
