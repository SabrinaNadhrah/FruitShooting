#ifndef WEAPON_H
#define WEAPON_H

#include <vector>
#include <graphics.h>
#include "bullet.h"

#define MAXBULLET 10

class Bullet;

class Weapon
{
private:
	int x, y;
	int width, height;
	int color;
	Bullet *bullets;
	void drawHelper(int c) const;

public:
	Weapon(int _x = 0, int _y = 0, int _width = 150, int _height = 100, int _color = BLACK);
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	void shoot();
	void draw() const;
	void undraw() const;
	void move(int dx);
	void doAction();
    int getPosition() const ;
    void update () ;
};

#endif
