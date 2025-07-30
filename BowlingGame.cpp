#include <iostream>
#include <vector>
using namespace std;

class BowlingGame {
private:
    vector<int> rolls;

public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int rollIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(rollIndex)) {
                // Strike: 10 + next two rolls
                totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                rollIndex += 1;
            } else if (isSpare(rollIndex)) {
                // Spare: 10 + next roll
                totalScore += 10 + rolls[rollIndex + 2];
                rollIndex += 2;
            } else {
                // Normal frame
                totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
            }
        }
        return totalScore;
    }

private:
    bool isStrike(int rollIndex) {
        return rolls[rollIndex] == 10;
    }

    bool isSpare(int rollIndex) {
        return rolls[rollIndex] + rolls[rollIndex + 1] == 10;
    }
};

int main() {
    BowlingGame game;
    cout << "Enter your rolls (frame by frame):\n";

    for (int frame = 1; frame <= 10; ++frame) {
        int first, second = 0;
        cout << "Frame " << frame << ":\n";
        cout << "  First roll: ";
        cin >> first;
        game.roll(first);

        if (frame < 10) {
            if (first != 10) {
                cout << "  Second roll: ";
                cin >> second;
                game.roll(second);
            }
        } else {
            // Frame 10 rules
            cout << "  Second roll: ";
            cin >> second;
            game.roll(second);

            if (first == 10 || (first + second == 10)) {
                int third;
                cout << "  Bonus roll (Strike or Spare in 10th frame): ";
                cin >> third;
                game.roll(third);
            }
        }
    }

    cout << "\nTotal score: " << game.score() << endl;
    return 0;
}
