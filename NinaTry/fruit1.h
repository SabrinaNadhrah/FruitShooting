#ifndef FRUIT_H
#define FRUIT_H

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

#endif // FRUIT_H
