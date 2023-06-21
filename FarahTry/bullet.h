#ifndef BULLET_H
#define BULLET_H

//#include <graphics.h>
#include "weapon.h"

class Weapon;

class Bullet
{
  private:
	int x, y;			// Coordinates of the bullet on the screen
	int size;			// size of bullet
	int color;			// color of the bullet
	int speed;			// speed at which the bullet moves
	bool active;		// the bullet is active or not
	Weapon *weapon;		// The weapon attribute is a pointer to the associated Weapon object
	void drawHelper(int c) const;

  public:
	Bullet(int _x = 0, int _y = 0, int _size = 10, int _color = BLUE, int _speed = 10);
	int getY() const;
	bool getActive() const;
	void setWeapon(Weapon *w);
	void draw() const;
	void undraw() const;
	void move();
	void reset();
};

#endif