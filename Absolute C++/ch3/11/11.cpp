#include <iostream>
#include <ctime>
#define PLAYER 1
#define COMPUTER 0
#define DEBUG 0

using namespace std;

int humanTurn(int);
int computerTurn(int);
void outputResult(int player, int score, int now_point = -1, int total_score = -1);

int main(void) {

	int humanTotalScore = 0, computerScore = 0, round = 1;
	bool isWin = false;
	srand(time(NULL));

	while (computerScore < 100) {

		cout << "-----Round " << round << "-----" << endl;
		cout << "\nSCORE BOARD:" << endl << "[Player] " << humanTotalScore << " points" << endl;
		cout << "[COMPUTER] " << computerScore << " points" << endl;

		humanTotalScore = humanTurn(humanTotalScore);

		if (humanTotalScore >= 100) {
			isWin = true;
			break;
		}

		computerScore = computerTurn(computerScore);

        if(DEBUG) {
            cout << "\n[DEBUG]: " << humanTotalScore << endl;
            cout << "[DEBUG]: " << computerScore << endl;
        }

		round++;
	
	}

	if (isWin)
		cout << "\nThe Player win at " << humanTotalScore << " points.";
	else
		cout << "\nThe Computer win at " << computerScore << " points.";

	system("pause");
	return 0;

}

int humanTurn(int humanTotalScore) {

	int score = 0, now_point = 0;
	char input = 'r';

	while (input == 'r') {
	
		now_point = rand() % 6 + 1;
		if (now_point != 1) {
			score += now_point;
			if(humanTotalScore + score >= 100) {
				outputResult(PLAYER, score, now_point, humanTotalScore + score);
				return humanTotalScore + score;
			}
		}
		else {
			score = 0;
			outputResult(PLAYER, score, now_point, humanTotalScore + score);
			break;
		}

		outputResult(PLAYER, score, now_point, humanTotalScore + score);

		cin >> input;
		
	}

	return humanTotalScore + score;

}

int computerTurn(int computerTotalScore) {

    int score = 0, now_point = 0;

    while(score < 20) {

        now_point = rand() % 6 + 1;
        if (now_point != 1) {
			score += now_point;
			if(computerTotalScore + score >= 100) {
				outputResult(COMPUTER, score);
				return computerTotalScore + score;
			}
		}
		else {
			score = 0;
			break;
		}

    }

	outputResult(COMPUTER, score);

	return computerTotalScore + score;

}

void outputResult(int player, int score, int now_point, int total_score) {

	if (player == PLAYER) {

		cout << "\n< You dice out " << now_point << " points >" << endl;
		cout << "\nYou now have " << score << " points in this turn." << endl;

		if (now_point != 1 && total_score < 100)
			cout << "roll or hold? > ";

	}
	else
		cout << "\nComputer total dice out " << score << " points in this turn." << endl;

}