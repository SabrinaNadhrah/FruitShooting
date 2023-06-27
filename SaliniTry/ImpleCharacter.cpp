#include "Character.h"
#include <graphics.h>

Character::Character(const std::string& playerName, int playerPositionX, int playerPositionY)
    : playerName(playerName), positionX(playerPositionX), positionY(playerPositionY) {}

void Character::setPosition(int x) {
    positionX = x;
}

int Character::getPosition() const {
    return positionX;
}

int Character::getY() const {
    return positionY;
}
