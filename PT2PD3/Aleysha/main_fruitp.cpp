#include <iostream>
#include <cstdlib>
#include <ctime>
#include <graphics.h>
#include "fruitp.h"
#include "fruitp.cpp"

void initializeFruits(Fruit* fruits[]) {
    for (int i = 0; i < numFruits; i++) {
        int randomSize = rand() % 3 + 1; // Randomly assign size 1, 2, or 3
        int randomScore = (4 - randomSize) * 2; // Calculate score based on size
        fruits[i] = new Fruit(randomSize, randomScore);
        fruits[i]->setX(rand() % (screenWidth - fruitWidth)); // Random x position
        fruits[i]->setY(rand() % (screenHeight / 2)); // Random y position within the top half of the screen
    }
}

void deleteFruits(Fruit* fruits[]) {
    for (int i = 0; i < numFruits; i++)
        delete fruits[i];
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    initwindow(screenWidth, screenHeight, "Fruit Shooting Game");
    setbkcolor(WHITE);
    cleardevice();

    readimagefile("background.jpeg", 0, 0, screenWidth, screenHeight);
     void* imageBuffer = malloc(imagesize(0, 0, screenWidth, screenHeight));
    getimage(0, 0, screenWidth, screenHeight, imageBuffer);

    Fruit* fruits[numFruits];
    initializeFruits(fruits);

    while (!kbhit()) {
        cleardevice();

        putimage(0, 0, imageBuffer, COPY_PUT);

        for (int i = 0; i < numFruits; i++) {
            fruits[i]->move();
            fruits[i]->draw();
        }

        delay(10);
    }

    deleteFruits(fruits);
    free(imageBuffer);
    closegraph();

    return 0;
}
