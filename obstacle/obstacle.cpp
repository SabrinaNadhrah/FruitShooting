#include <graphics.h>
#include <string>
#include "obstacle.h"
#include "impleobstacle.cpp"

int main()
{
    int screenWidth = 800; // Adjust with your desired screen width
    int screenHeight = 600; // Adjust with your desired screen height

    initwindow(screenWidth, screenHeight, "Obstacle Game");

    setbkcolor(WHITE); // Set background color to white

    int obstacleWidth = 100; // Adjust with the actual width of your obstacle image
    int obstacleHeight = 100; // Adjust with the actual height of your obstacle image

    int obstacle1X = screenWidth / 2 - obstacleWidth / 2; // start at the middle of the screen
    int obstacle1Y = screenHeight / 2 - obstacleHeight / 2;

    int obstacle2X = screenWidth / 2 - obstacleWidth / 2; // start at the middle of the screen
    int obstacle2Y = screenHeight / 2 - obstacleHeight / 2 - 100; // adjust the obstacle's Y position above the first obstacle

    Obstacle obstacle1("Obstacle1", obstacle1X, obstacle1Y, obstacleWidth, obstacleHeight);
    Obstacle obstacle2("Obstacle2", obstacle2X, obstacle2Y, obstacleWidth, obstacleHeight);

    while (!kbhit())
    {
        setactivepage(1);
        cleardevice(); // Clear the screen

        obstacle1.undrawObstacle(); // Undraw the obstacle before moving
        obstacle1.moveRight();
        if (obstacle1.getPosition() >= screenWidth - obstacleWidth)
            obstacle1.setPosition(0);
        obstacle1.drawObstacle();

        obstacle2.undrawObstacle(); // Undraw the obstacle before moving
        obstacle2.moveLeft();
        if (obstacle2.getPosition() <= 0)
            obstacle2.setPosition(screenWidth - obstacleWidth);
        obstacle2.drawObstacle();

        setvisualpage(1);

        delay(100);
    }

    closegraph();
    return 0;
}
