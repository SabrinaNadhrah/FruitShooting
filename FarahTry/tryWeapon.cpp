#include <iostream>
#include <graphics.h>
#include <string>

const int MAXBULLET = 100;

// Forward declaration of the Weapon class
class Weapon;

class Bullet {
    // Bullet class implementation remains the same
    // ...
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
    Bullet* bullets;
    std::string imageFile; // Added member variable for image filename

public:
    Weapon(int _x = 0, int _y = 0, int _width = 150, int _height = 100, int _color = BLACK, const std::string& _imageFile = "");

    // Other member functions remain the same
    // ...
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

};

// Implement the Weapon class methods

Weapon::Weapon(int _x, int _y, int _width, int _height, int _color, const std::string& _imageFile)
    : x(_x), y(_y), width(_width), height(_height), color(_color), imageFile(_imageFile) {
    bullets = new Bullet[MAXBULLET];
    for (int i = 0; i < MAXBULLET; i++) {
        bullets[i].setWeapon(this);
    }
}

void Weapon::draw() const {
    readimagefile(imageFile.c_str(), x, y, x + width, y + height);
    // Additional code if needed
}

// Update the main function to use different images for each weapon

int main() {
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Choose Your Weapon!");
    setbkcolor(BLACK);
    cleardevice();

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
        readimagefile("rifflee.jpg", screenWidth / 2 - 100, screenHeight / 2 - 50, screenWidth / 2 + 100, screenHeight / 2 + 50);
        outtextxy(screenWidth / 2 - 30, screenHeight / 2 + 60, "Rifle");

        // Draw 2 players button with Gun image
        readimagefile("gunn.jpg", screenWidth / 2 - 100, screenHeight / 2 + 100, screenWidth / 2 + 100, screenHeight / 2 + 200);
        outtextxy(screenWidth / 2 - 25, screenHeight / 2 + 210, "Gun");

        // Draw Cannon button with Cannon image
        readimagefile("cannon.jpg", screenWidth / 2 - 100, screenHeight / 2 + 250, screenWidth / 2 + 100, screenHeight / 2 + 350);
        outtextxy(screenWidth / 2 - 40, screenHeight / 2 + 360, "Cannon");

        delay(100);
    }

    closegraph();

    // Use the selected option here
    Weapon w1(screenWidth / 2, screenHeight - 230, 150, 100, BLACK, "");
    // Use the selected option here
    if (option == 1) {
        std::cout << "Rifle selected" << std::endl;
        Weapon w1(screenWidth / 2, screenHeight - 230, 150, 100, BLACK, "rifflee.jpg");
        // Add code for 1 player game with Rifle
        w1.draw();  // Draw the weapon on the screen
    } else if (option == 2) {
        std::cout << "Gun selected" << std::endl;
        Weapon w1(screenWidth / 2, screenHeight - 230, 150, 100, BLACK, "gunn.jpg");
        // Add code for 2 player game with Gun
        w1.draw();  // Draw the weapon on the screen
    } else if (option == 3) {
        std::cout << "Cannon selected" << std::endl;
        Weapon w1(screenWidth / 2, screenHeight - 230, 150, 100, BLACK, "cannon.jpg");
        // Add code for Cannon game
        w1.draw();  // Draw the weapon on the screen
    }

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
