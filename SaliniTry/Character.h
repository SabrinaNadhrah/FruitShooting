#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string playerName;
    int positionX;
    int positionY;

public:
    Character(const std::string& playerName, int playerPositionX, int playerPositionY);
    virtual ~Character() {}

    void setPosition(int x);
    int getPosition() const;
    int getY() const;
    virtual void drawCharacter() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
};

#endif
