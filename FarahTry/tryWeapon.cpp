#include <iostream>
#include <graphics.h>
#include <string>

const int MAXBULLET = 100;

// Forward declaration of the Weapon class
class Weapon;

class Bullet {
private:
    int x, y;
    int size;
    int color;
    int speed;
    bool active;
    Weapon* weapon; // Forward declaration allows using the pointer to Weapon

public:
    Bullet(int _x = 0, int _y = 0, int _size = 10, int _color = BLUE, int _speed = 10);

    int getY() const;
    bool getActive() const;
    void setWeapon(Weapon* w);

    void draw() const;
    void undraw() const;
    void move();
    void reset();
};

class Weapon {
private:
    int x, y;
    int width, height;
    int color;
    Bullet* bullets; // Use the pointer to Bullet
    std::string imagePath;

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
    int getPosition() const;
    void update();
    void setImagePath(const std::string& path);
};

// Implement the Bullet class methods

Bullet::Bullet(int _x, int _y, int _size, int _color, int _speed)
    : x(_x), y(_y), size(_size), color(_color), speed(_speed), weapon(nullptr), active(false) {
}

int Bullet::getY() const {
    return y;
}

bool Bullet::getActive() const {
    return active;
}

void Bullet::setWeapon(Weapon* w) {
    weapon = w;
}

void Bullet::draw() const {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(x, y, size, size);
}

void Bullet::undraw() const {
    // Optional: Implement undraw functionality if needed
}

void Bullet::move() {
    if (!active)
        return;
    undraw();
    y -= speed;

    if (y > 0)
        draw();
    else
        active = false;
}

void Bullet::reset() {
    x = weapon->getX() + weapon->getWidth() / 2;
    y = weapon->getY() - size;
    active = true;
}

// Implement the Weapon class methods

Weapon::Weapon(int _x, int _y, int _width, int _height, int _color)
    : x(_x), y(_y), width(_width), height(_height), color(_color) {
    bullets = new Bullet[MAXBULLET];
    for (int i = 0; i < MAXBULLET; i++) {
        bullets[i].setWeapon(this);
    }
}

int Weapon::getX() const {
    return x;
}

int Weapon::getY() const {
    return y;
}

int Weapon::getWidth() const {
    return width;
}

int Weapon::getHeight() const {
    return height;
}

void Weapon::shoot() {
    int foundAt = -1;
    for (int i = 0; i < MAXBULLET; i++) {
        if (!bullets[i].getActive()) {
            foundAt = i;
            break;
        }
    }

    if (foundAt != -1) {
        bullets[foundAt].reset();
        bullets[foundAt].draw();
    }
}

void Weapon::draw() const {
    readimagefile(imagePath.c_str(), x, y, x + width, y + height);
}

void Weapon::undraw() const {
    // Optional: Implement undraw functionality if needed
}

void Weapon::move(int dx) {
    undraw();
    x += dx;
    draw();
}

void Weapon::doAction() {
    for (int i = 0; i < MAXBULLET; i++) {
        bullets[i].move();
    }
}

int Weapon::getPosition() const {
    return x;
}

void Weapon::update() {
    // Optional: Implement update functionality if needed
}

void Weapon::setImagePath(const std::string& path) {
    imagePath = path;
}

int chooseWeaponPage() {
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Choose Weapon");

    // Display the available weapons and let the player choose
    int choice = 0;
    while (choice < 1 || choice > 3) {
        cleardevice();
        outtextxy(screenWidth / 2 - 50, screenHeight / 2 - 30, "Choose a Weapon:");
        outtextxy(screenWidth / 2 - 60, screenHeight / 2, "1. Rifle");
        outtextxy(screenWidth / 2 - 60, screenHeight / 2 + 20, "2. Cannon");
        outtextxy(screenWidth / 2 - 60, screenHeight / 2 + 40, "3. Gun");

        char ch = getch();
        if (ch >= '1' && ch <= '3') {
            choice = ch - '0';
        }
    }

    closegraph();
    return choice;
}

int main() {
    int choice = chooseWeaponPage();
    initwindow(getmaxwidth(), getmaxheight(), "Fruit Shooting");
    setbkcolor(WHITE);

    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    Weapon w1(screenWidth / 2, screenHeight - 230);
    
    std::string weaponImagePath;
    if (choice == 1) {
        // Rifle
        weaponImagePath = "riffle.jpg";
    } else if (choice == 2) {
        // Cannon
        weaponImagePath = "cannon.jpg";
    } else if (choice == 3) {
        // Gun
        weaponImagePath = "gunn.jpg";
    }
    w1.setImagePath(weaponImagePath);

    char ch;

    int direction = 1;

    while (true) {
        delay(40);

        // Move the weapon
        w1.move(5 * direction);

        // Reverse direction if the weapon reaches the screen boundaries
        if (w1.getPosition() <= 0 || w1.getPosition() >= (screenWidth - 155))
            direction *= -1;

        w1.doAction();

        if (kbhit()) {
            ch = getch();

            if (ch == 27)
                break;
            else if (ch == ' ')
                w1.shoot();
        }

        // Redraw the weapon
        cleardevice();
        w1.update();
        w1.draw();
    }

    closegraph();
    return 0;
}
