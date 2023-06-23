#include "player1.h"
#include <graphics.h>

Player1::Player1(const std::string& playerName, int playerPositionX, int playerPositionY)
    : Character(playerName, playerPositionX, playerPositionY) {}

void Player1::drawCharacter() {
    int x = positionX;
    int y = positionY;

    // Draw the character using graphics library or other method
    readimagefile("cat.jpg", x, y, x + 150, y + 150);
}

void Player1::moveLeft() {
    positionX -= 5;
}

void Player1::moveRight() {
    positionX += 5;
}

