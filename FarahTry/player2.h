#ifndef PLAYER2_H
#define PLAYER2_H

#include "Character.h"

class Player2 : public Character {
private:
    int size;
    int health;

public:
    Player2(const std::string& playerName, int playerPositionX, int playerPositionY);

    void drawCharacter() override;
    void moveLeft() override;
    void moveRight() override;
};

#endif
