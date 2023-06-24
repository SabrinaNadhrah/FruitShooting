#ifndef SCORE_H
#define SCORE_H

#include <string>

class Score {
private:
    int max_value;
    int high_score;
    int current_score;
    int deduction_count;
    int marks_gained_count;
    int health; // New health variable

public:
    Score();

    int getScore() const;
    int getHighScore() const;
    int getDeductionCount() const;
    int getMarksGainedCount() const;
    int getHealth() const; // New health getter

    void updateScore(int marksGained, int deduction);
    void decreaseHealth(int amount); // New health modifier

    void drawScoreboard() const;
};

#endif

