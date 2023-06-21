#include <graphics.h>
#include "weapon.h"
#include "bullet.h"

Weapon::Weapon(int _x, int _y, int _width, int _height, int _color) : x(_x), y(_y),
                                                                            width(_width), 
                                                                            height(_height),
                                                                            color(_color)
                                                                            
{
    bullets = new Bullet[MAXBULLET];
    for (int i = 0; i < MAXBULLET; i++)
        bullets[i].setWeapon(this);
   /*for (Bullet* bullet : bullets)
        bullet->setWeapon(this);
        */
}

int Weapon::getX() const { return x; }
int Weapon::getY() const { return y; }
int Weapon::getWidth() const { return width; }
int Weapon::getHeight() const { return height; }

void Weapon::shoot()
{
    int foundAt = -1;
    for (int i = 0; i < MAXBULLET; i++)
    {
        if (!bullets[i].getActive())
        {
            foundAt = i;
            break;
        }
    }

    if (foundAt != -1){
        bullets[foundAt].reset();
        bullets[foundAt].draw();
    }
}

void Weapon::drawHelper(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    bar(x, y, x + width, y + height);
}

void Weapon::draw() const { drawHelper(color); }
void Weapon::undraw() const { drawHelper(0); }
void Weapon::move(int dx)
{
    undraw();
    x += dx;
    draw();
}

void Weapon::doAction()
{
    for (int i = 0; i < MAXBULLET; i++)
        bullets[i].move();
}

int Weapon::getPosition() const 
{
    return x ;
}

void Weapon::update()
{

}