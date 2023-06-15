#ifndef SCORE_H
#define SCORE_H

class Score {
private:
    int max_value;
    int high_score;
    int current_score;
    int deduction_count;
    int marks_gained_count;

public:
    Score();

    int getScore() const;
    int getHighScore() const;
    int getDeductionCount() const;
    int getMarksGainedCount() const;

    void updateScore(int marksGained, int deduction);

    void drawScoreboard() const;
};

#endif
