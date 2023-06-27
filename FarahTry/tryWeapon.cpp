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
    std::string imageFilename; // Image filename for the weapon

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
    void setImageFilename(const std::string& filename); // Set image filename for the weapon
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
    if (!imageFilename.empty()) {
        readimagefile(imageFilename.c_str(), x, y, x + width, y + height);
    } else {
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        rectangle(x, y, x + width, y + height);
        floodfill(x + width / 2, y + height / 2, color);
    }
}

void Weapon::undraw() const {
    if (!imageFilename.empty()) {
        // Optional: Implement undraw functionality for image if needed
    } else {
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        rectangle(x, y, x + width, y + height);
        floodfill(x + width / 2, y + height / 2, BLACK);
    }
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

void Weapon::setImageFilename(const std::string& filename) {
    imageFilename = filename;
}

int main() {
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Fruit Shooting");

    int option = 0;
    int mouseX, mouseY;

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            mouseX = mousex();
            mouseY = mousey();

            if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 - 50 && mouseY <= screenHeight / 2 + 50) {
                option = 1; // 1 player selected
                break;
            } else if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 + 100 && mouseY <= screenHeight / 2 + 200) {
                option = 2; // 2 players selected
                break;
            } else if (mouseX >= screenWidth / 2 - 100 && mouseX <= screenWidth / 2 + 100 && mouseY >= screenHeight / 2 + 250 && mouseY <= screenHeight / 2 + 350) {
                option = 3; // Cannon selected
                break;
            }
        }

        setcolor(WHITE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 3);
        outtextxy(screenWidth / 2 - 80, screenHeight / 2 - 100, "Choose Your Weapon!");
        setfillstyle(SOLID_FILL, LIGHTGRAY);

        // Draw 1 player button with Rifle image
        rectangle(screenWidth / 2 - 100, screenHeight / 2 - 50, screenWidth / 2 + 100, screenHeight / 2 + 50);
        outtextxy(screenWidth / 2 - 30, screenHeight / 2 + 60, "Rifle");

        // Draw 2 players button with Gun image
        rectangle(screenWidth / 2 - 100, screenHeight / 2 + 100, screenWidth / 2 + 100, screenHeight / 2 + 200);
        outtextxy(screenWidth / 2 - 30, screenHeight / 2 + 210, "Gun");

        // Draw Cannon button with Cannon image
        rectangle(screenWidth / 2 - 100, screenHeight / 2 + 250, screenWidth / 2 + 100, screenHeight / 2 + 350);
        outtextxy(screenWidth / 2 - 30, screenHeight / 2 + 360, "Cannon");

        delay(10);
        cleardevice();
    }

    // Create the weapon based on the user's selection
    Weapon weapon;
    switch (option) {
        case 1:
            weapon.setImageFilename("riffle.jpg"); // Set the image filename for the Rifle
            break;
        case 2:
            weapon.setImageFilename("gunn.jpg"); // Set the image filename for the Gun
            break;
        case 3:
            weapon.setImageFilename("cannon.jpg"); // Set the image filename for the Cannon
            break;
    }

    weapon.draw();

    while (true) {
        if (kbhit()) {
            char key = getch();
            switch (key) {
                case 'a':
                case 'A':
                    weapon.move(-20);
                    break;
                case 'd':
                case 'D':
                    weapon.move(20);
                    break;
                case ' ':
                    weapon.shoot();
                    break;
            }
        }

        weapon.doAction();
        delay(10);
        cleardevice();
    }

    closegraph();
    return 0;
}
