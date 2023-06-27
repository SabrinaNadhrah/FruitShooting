#include <iostream>
#include <cstdlib>
#include <ctime>
#include <graphics.h>
#include "fruit1.h"
#include "fruit1.cpp"


void initializeFruits(Fruit* fruits[]) {
    for (int i = 0; i < numFruits; i++) {
        int randomSize = rand() % 3 + 1; // Randomly assign size 1, 2, or 3
        switch (randomSize) {
            case 1:
                fruits[i] = new SmallFruit();
                break;
            case 2:
                fruits[i] = new MediumFruit();
                break;
            case 3:
                fruits[i] = new BigFruit();
                break;
        }
        
        fruits[i]->setX(rand() % (screenWidth - fruitWidth)); // Random x position
        fruits[i]->setY(rand() % (screenHeight / 4)); // Random y position within the top half of the screen
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

int main() {
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Obstacle Demo");

    Obstacle obstacle1(WHITE, 5, 0, 25, 0, screenHeight / 2);
    Obstacle obstacle2(WHITE, -5, 0, 25, screenWidth, screenHeight / 2);

    while (!kbhit()) {
        obstacle1.move();
        obstacle2.move();
        delay(3);
    }

    closegraph();
    return 0;
}

void Score::updateScore(int marksGained, int deduction) {
    current_score += marksGained - deduction;

    if (current_score > high_score) {
        high_score = current_score;
    }

    if (deduction > 0) {
        deduction_count++;
    }

    if (marksGained > 0) {
        marks_gained_count++;
    }
}

void Score::drawScoreboard() const {
    // Initialize graphics
    initwindow(800, 600, "Scoreboard");

    // Load background image
    readimagefile("forest.jpeg", 0, 0, 800, 600);

    // Draw scoreboard background and current score

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(5, 5, 220, 80); // Example background rectangle
   
    

    // Convert the score, deduction count, and marks gained count to strings
    std::string scoreText = "Score: " + std::to_string(current_score);
    std::string deductionText = "Deductions: " + std::to_string(deduction_count);
    std::string marksGainedText = "Marks Gained: " + std::to_string(marks_gained_count);

    // Convert the strings to char arrays
    char scoreStr[50];
    char deductionStr[50];
    char marksGainedStr[50];
    strcpy(scoreStr, scoreText.c_str());
    strcpy(deductionStr, deductionText.c_str());
    strcpy(marksGainedStr, marksGainedText.c_str());

    setbkcolor(WHITE);
    setcolor(BLACK); // Set the text color to black
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    // Display the current score, deduction count, and marks gained count
    outtextxy(8, 10, scoreStr);
    outtextxy(8, 30, deductionStr);
    outtextxy(8, 50, marksGainedStr);

    // Close graphics window
    getch();
    closegraph();
}

int main() {
    // Create a Score object
    Score score;

    // Update the score with example values
    score.updateScore(10, 0); // Marks gained: 10, Deduction: 0
    score.updateScore(0, 4); // Marks gained: 0, Deduction: 4
    score.updateScore(8, 2); // Marks gained: 8, Deduction: 2

    // Display the scoreboard
    score.drawScoreboard();

    // Access and display the current score, high score, deduction count, and marks gained count
    std::cout << "Current Score: " << score.getScore() << std::endl;
    std::cout << "High Score: " << score.getHighScore() << std::endl;
    std::cout << "Deduction Count: " << score.getDeductionCount() << std::endl;
    std::cout << "Marks Gained Count: " << score.getMarksGainedCount() << std::endl;

    // Wait for a key press before exiting
    std::cout << "Press any key to exit..." << std::endl;
    _getch();

    return 0;
}

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Fruit Shooting");
    setbkcolor(WHITE) ;

	Weapon w1(screenWidth/2, screenHeight-100);
	char ch;

    int direction = 1 ;

	//w1.draw();

	while (true)
	{
		delay(40);

        // Move the weapon
        w1.move(5 * direction);

        // Reverse direction if the weapon reaches the screen boundaries
        if (w1.getPosition() <= 0 || w1.getPosition() >= (screenWidth - 155) )
            direction *= -1;

		w1.doAction();

		if (kbhit())
		{
			ch = getch();

			if (ch == 27)
				break;
			else if (ch == ' ')
				w1.shoot();
		}

        // Redraw the weapon
        cleardevice();
        w1.update();
        w1.draw();
	}

	return 0;
}

