#include "player2.h"
#include <graphics.h>

Player2::Player2(const std::string& playerName, int playerPositionX, int playerPositionY)
    : Character(playerName, playerPositionX, playerPositionY){}

void Player2::drawCharacter() {
    int x = positionX;
    int y = positionY;

    // Draw the character using graphics library or other method
    readimagefile("cat.jpg", x, y, x + 150, y + 150);
}

void Player2::moveLeft() {
    positionX -= 5;
}

void Player2::moveRight() {
    positionX += 5;
}
