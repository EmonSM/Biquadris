#include "display.h"

TextDisplay::TextDisplay(){

}


TextDisplay::~TextDisplay(){
}


void TextDisplay::printBoard(vector <Board*> players, int highScore) {

	int gap = 5;

	cout << string(players.size() * (11 + gap) - gap, '-') << endl;
	cout << "High Score: " << highScore << endl;
	cout << string(players.size() * (11 + gap) - gap, '-') << endl;

	for (Board* b1 : players) {
		cout << "Player:   " << b1->playerNumber;
		cout << string(gap, ' ');
	}
	cout << endl;

	for (Board* b1 : players) {
		cout << string(11, '-');
		cout << string(gap, ' ');
	}
	cout << endl;

	for (Board* b1 : players) {

		cout << "Level:    " << b1->getCurrentLevel()->currentLevel;
		cout << string(gap, ' ');
	}
	cout << endl;

	for (Board* b1 : players) {
	
		cout << "Score:" << string(5 - to_string(b1->getScore()).length(), ' ') << b1->getScore();
		cout << string(gap, ' ');
	}

	cout << endl;

	for (Board* b1 : players) {

		cout << string(11, '-');
		cout << string(gap, ' ');
	}

	cout << endl;

	for (int i = 0; i < 18; i += 1) {

		for (Board* b1 : players) {

			for (int j = 0; j < 11; j += 1) {

				if (i >= b1->getGapTop() && i - b1->getGapTop() < 4 && j >= b1->getGapLeft() && j - b1->getGapLeft() < 4) {

					if (b1->getCurrentBlock()->units[i - b1->getGapTop()][j - b1->getGapLeft()]->isInit()) {
						cout << b1->getCurrentBlock()->units[i - b1->getGapTop()][j - b1->getGapLeft()]->getBlockString();
					}
					else if (b1->isBlind() && j >= 2 && j <= 8 && i <= 18 - 3 && i >= 18 - 12) {
						cout << "?";
					}
					else if (b1->getTheBoard()[i][j]->isInit()) {
						cout << b1->getTheBoard()[i][j]->getBlockString();
					}
					else {
						cout << " ";
					}
				}
				else if (b1->isBlind() && j >= 2 && j <= 8 && i <= 18 - 3 && i >= 18 - 12) {
					cout << "?";
				}
				else if (b1->getTheBoard()[i][j]->isInit()) {
					cout << b1->getTheBoard()[i][j]->getBlockString();
				}
				else {
					cout << " ";
				}
			}
			cout << string(gap, ' ');;
		}
		cout << endl;
	}
	
	for (Board* b1 : players) {
		cout << string(11, '-');
		cout << string(gap, ' ');
	}
	cout << endl;

	for (Board* b1 : players) {
		cout << "Next:      ";
		cout << string(gap, ' ');
	}
	cout << endl;

	for (int i = 2; i < 4; i += 1) {
		for (Board* b : players) {
			if (b->getNextBlock() != nullptr) {
				for (int j = 0; j < 4; j += 1) {
					if (b->getNextBlock()->units[i][j]->isInit()) {
						cout << b->getNextBlock()->units[i][j]->getBlockString();
					}
					else {
						cout << " ";
					}
				}
				cout << string(7, ' ') << string(gap, ' ');
			}
			else {
				cout << string(11, ' ') << string(gap, ' ');
			}
			
		}
		cout << endl;
	}
}
