#include <graphics.h>
#include "bullet.h"
#include "weapon.h"

Bullet::Bullet(int _x, int _y, int _size, int _color, int _speed) : x(_x), y(_y),
                                                                    size(_size), color(_color),
                                                                    speed(_speed),
                                                                    weapon(NULL),
                                                                    active(false)
{
}

int Bullet::getY() const { return y; }
bool Bullet::getActive() const { return active; }
void Bullet::setWeapon(Weapon *w) { weapon = w ; }

void Bullet::drawHelper(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillellipse(x, y, size, size);
}

void Bullet::draw() const { drawHelper(color); }
void Bullet::undraw() const { drawHelper(0); }

void Bullet::move()
{
    if (!active)
        return;
    undraw();
    y -= speed;

    if (y > 0)
        draw();
    else
        active = false;
}

void Bullet::reset()
{
    x = weapon->getX() + weapon->getWidth() / 2;
    y = weapon->getY() - size;
    active = true;
}
