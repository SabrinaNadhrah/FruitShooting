#include "score.h"
#include <graphics.h>

Score::Score() {
    max_value = 100;
    high_score = 0;
    current_score = 0;
    deduction_count = 0;
    marks_gained_count = 0;
}

int Score::getScore() const {
    return current_score;
}

int Score::getHighScore() const {
    return high_score;
}

int Score::getDeductionCount() const {
    return deduction_count;
}

int Score::getMarksGainedCount() const {
    return marks_gained_count;
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
#include <iostream>
#include <conio.h>
#include <graphics.h>
#include "score.h"

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
