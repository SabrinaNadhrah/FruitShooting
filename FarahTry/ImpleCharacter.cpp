#include "character.h"
#include <graphics.h>


using namespace std;
Character::Character(const string& playerName, int playerPositionX, int playerPositionY)
    : playerName(playerName), positionX(playerPositionX), positionY(playerPositionY), size(50) {}

void Character::moveLeft() {
    positionX -= 5;
}

void Character::moveRight() {
    positionX += 80;
}

int Character::getPosition() const {
    return positionX;
}

void Character::setPosition(int x) {
    positionX = x;
}

int Character::getY() const {
    return positionY;
}

void Character::drawCharacter() {
    int x = positionX;
    int y = positionY;

    readimagefile("cat.jpg", x, y, x + 150, y + 150);
}
