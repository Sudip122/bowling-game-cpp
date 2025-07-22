
#include <iostream>
#include <vector>

class BowlingGame {
private:
    std::vector<int> rolls;

public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int frameIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(frameIndex)) {
                totalScore += 10 + strikeBonus(frameIndex);
                frameIndex += 1;
            } else if (isSpare(frameIndex)) {
                totalScore += 10 + spareBonus(frameIndex);
                frameIndex += 2;
            } else {
                totalScore += sumOfBallsInFrame(frameIndex);
                frameIndex += 2;
            }
        }

        return totalScore;
    }

private:
    bool isStrike(int index) {
        return rolls[index] == 10;
    }

    bool isSpare(int index) {
        return rolls[index] + rolls[index + 1] == 10;
    }

    int strikeBonus(int index) {
        return rolls[index + 1] + rolls[index + 2];
    }

    int spareBonus(int index) {
        return rolls[index + 2];
    }

    int sumOfBallsInFrame(int index) {
        return rolls[index] + rolls[index + 1];
    }
};

// Example usage
int main() {
    BowlingGame game;

    std::vector<int> sampleRolls = {5, 4, 1, 5, 4, 5, 10, 9, 0, 10, 10, 7, 2, 1, 9, 2, 6};
    for (int pins : sampleRolls) {
        game.roll(pins);
    }

    std::cout << "Final Score: " << game.score() << std::endl;
    return 0;
}
