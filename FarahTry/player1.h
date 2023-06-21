#ifndef PLAYER1_H
#define PLAYER1_H

#include "Character.h"

class Player1 : public Character {
private:
    int size;
    int score;

public:
    Player1(const std::string& playerName, int playerPositionX, int playerPositionY);

    void drawCharacter() override;
    void moveLeft() override;
    void moveRight() override;
};

#endif
