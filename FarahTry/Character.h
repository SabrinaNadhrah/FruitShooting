#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;
class Character
{

private:
    string playerName;
    int positionX;
    int positionY;
    int size;

public:
    Character(const string &playerName, int playerPositionX, int playerPositionY);
    //display-related method
    void drawCharacter();

    //action-related method
    void moveLeft();
    void moveRight();
    
    //position-related method
    int getPosition() const;
    void setPosition(int x);
    int getY() const;
};

#endif
