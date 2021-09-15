#include "board.h"
#include <iostream>

int Board::playerCount = 0;

Board::Board(string inF, bool graphics) {

	playerCount += 1;
	playerNumber = playerCount;
	graphicsEnabled = graphics;

	gapLeft = 0;
	gapTop = 0;
	Score = 0;
	heavy = false;
	blind = false;
	placed = 0;
	specialAction = false;


	for (int i = 0; i < 18; i += 1) {
		vector<Unit*> v;
		theBoard.emplace_back(v);
		for (int j = 0; j < 11; j += 1) {
			Unit* u = new Unit();
			theBoard[i].emplace_back(u);
		}
	}

	File = inF;
	currentLevel = new level0(File);
	currentBlock = currentLevel->getNextBlock();
	nextBlock = currentLevel->getNextBlock();

	if (graphics) {
		graphicWindow = new Xwindow(230, 465);
		outputGraphics();
	}
	else {
		graphicWindow = nullptr;
	}

}

Board::~Board() {
	playerCount -= 1;
	delete currentBlock;
	delete nextBlock;
	for (int i = 0; i < 18; i += 1) {
		for (int j = 0; j < 11; j += 1) {
			delete theBoard[i][j];
		}
	}
	delete currentLevel;
	delete graphicWindow;
}

bool Board::fixGap() {

	bool yes = false;

	if (gapLeft < 0) {
		gapLeft = 0;
		yes = true;
	}

	else if (gapLeft + currentBlock->getLength() > 11) {
		gapLeft = 11 - currentBlock->getLength();
		yes = true;
	}

	if (gapTop < 0) {
		gapTop = 0;
		yes = true;
	}
	else if (gapTop /*+ currentBlock->getHeight()*/ > 14) {
		gapTop = 14/* - currentBlock->getHeight()*/;
		yes = true;
	}
	return yes;
}

void Board::incrementGapLeft(int by) {

	int tempGapLeft = gapLeft;
	gapLeft += by;

	bool check;

	check = fixGap();

	if (check) {
		return;
	}

	if (!isPossible()) {
		gapLeft = tempGapLeft;
		return;
	}

	if (heavy) {
		if (!forceToPlace()) {
			incrementGapTop();
		}
		else {
			return;
		}
		if (!forceToPlace()) {
			incrementGapTop();
		}
		else {
			return;
		}
	}

	if (currentLevel->heavy) {
		if (!forceToPlace()) {
			incrementGapTop();
		}
	}
}

void Board::incrementGapTop(int by) {
	gapTop += by;

	fixGap();
}

int Board::getGapLeft() {
	return gapLeft;
}

int Board::getGapTop() {
	return gapTop;
}

Block* Board::getCurrentBlock() {
	return currentBlock;
}

vector <vector <Unit*>> Board::getTheBoard() {
	return theBoard;
}

bool Board::forceToPlace() {


	if (gapTop /*+ currentBlock->getHeight()*/ == 14) {
		place();
		return true;
	}

	for (int i = 0; i < 18 - 1; i += 1) {  // ALways place when on bottom row so thats why -1

		for (int j = 0; j < 11; j += 1) {

			if (i >= gapTop && i - gapTop < 4 && j >= gapLeft && j - gapLeft < 4) {

				if (currentBlock->units[i - gapTop][j - gapLeft]->isInit() && theBoard[i + 1][j]->isInit()) {
					place();
					return true;
				}
			}
		}
	}

	return false;
}

void Board::place() {
	for (int i = 0; i < 4; i += 1) {
		for (int j = 0; j < 4; j += 1) {
			if (currentBlock->units[i][j]->isInit()) {
				theBoard[i + gapTop][j + gapLeft]->initialize(currentBlock->units[i][j]->getBlockString(), currentBlock->uniqueBlockId);
				theBoard[i + gapTop][j + gapLeft]->setScore(currentLevel->currentLevel);
			}
		}
	}
	gapLeft = 0;
	gapTop = 0;
	if (currentLevel->currentLevel == 4) {
		placed += 1;
		if (placed % 5 == 0) {
			int tempGapLeft = gapLeft;
			int tempGapTop = gapTop;
			Block* tempBlock = currentBlock;

			currentBlock = new _1block();
			gapLeft = 5;
			gapTop = 0;
			
			drop();
			delete currentBlock;

			gapLeft = tempGapLeft;
			gapTop = tempGapTop;
			currentBlock = tempBlock;
		}
	}

	removeCompletedRows();
	delete currentBlock;
	currentBlock = nextBlock;
	nextBlock = currentLevel->getNextBlock();

	blind = false;
}

void Board::removeCompletedRows() {

	int count = 0;
	bool deleteRow;
	for (int i = 0; i < 18; i += 1) {  // ALways place when on bottom row so thats why -1

		deleteRow = true;
		
		for (int j = 0; j < 11; j += 1) {

			if (theBoard[i][j]->isInit() == false) {
				deleteRow = false;
			}
		}

		if (deleteRow) {
			count += 1;
			for (int j = 0; j < 11; j += 1) {
				int uBlockId = theBoard[i][j]->blockId;
				bool remove = true;
				for (int iter = 0; iter < 18; iter += 1) {
					for (int iter2 = 0; iter2 < 11; iter2 += 1) {
						if ( theBoard[iter][iter2]->isInit() && theBoard[iter][iter2]->blockId == uBlockId) {
							if (i == iter && j == iter2) {

							}
							else {
								remove = false;
							}
						}
					}
				}
				if (remove) {
					Score += (theBoard[i][j]->getScore() + 1) * (theBoard[i][j]->getScore() + 1);
					
				}
				else {
					theBoard[i][j]->blockId = -1;
				}
			}
			for (int j = 0; j < 11; j += 1) {
				delete theBoard[i][j];
			}
			theBoard.erase(theBoard.begin() + i);
			vector<Unit*> v;
			theBoard.emplace(theBoard.begin(), v);
			for (int j = 0; j < 11; j += 1) {
				Unit* u = new Unit();
				theBoard[0].emplace_back(u);
			}
		}
	}

	if (count != 0) {
		Score += ((count + getCurrentLevel()->currentLevel) * (count + getCurrentLevel()->currentLevel));
	}

	if (count >= 2) {
		specialAction = true;
	}
}

void Board::drop() {
	while (!forceToPlace()) {
		incrementGapTop();
	}
}

bool Board::checkEnd() {
	for (int i = 0; i < 4; i += 1) {
		for (int j = 0; j < 4; j += 1) {
			if (theBoard[i][j]->isInit() && currentBlock->units[i][j]->isInit()) {
				return true;
			}
		}
	}
	return false;
}

string Board::getFileName() {
	return File;
}

void Board::toggleHeavy() {
	if (heavy) {
		heavy = false;
	}
	else {
		heavy = true;
	}
}

bool Board::setCurrentBlock(string block, Block* old) {
	if (block == "I") {
		currentBlock = new Iblock();
	}
	else if (block == "J") {
		currentBlock = new Jblock();
	}
	else if (block == "L") {
		currentBlock = new Lblock();
	}
	else if (block == "O") {
		currentBlock = new Oblock();
	}
	else if (block == "S") {
		currentBlock = new Sblock();
	}
	else if (block == "T") {
		currentBlock = new Tblock();
	}
	else if (block == "Z") {
		currentBlock = new Zblock();
	}
	else {
		currentBlock = old;
		return false;
	}
	delete old;
	return true;
}

Level* Board::getCurrentLevel() {
	return currentLevel;
}

void Board::changeLevel(int by) {
	
	if (by == 0) {
		return;
	}
	int newLevel = currentLevel->currentLevel + by;

	if (newLevel < 0) {
		newLevel = 0;
	}
	else if (newLevel > 4) {
		newLevel = 4;
	}
	delete currentLevel;

	if (newLevel == 0) {
		currentLevel = new level0(File);
	}
	else if (newLevel == 1) {
		currentLevel = new level1();
	}
	else if (newLevel == 2) {
		currentLevel = new level2();
	}
	else if (newLevel == 3) {
		currentLevel = new level3();
	}
	else if (newLevel == 4) {
		currentLevel = new level4();
	}
}

int Board::getScore() {
	return Score;
}

bool Board::isPossible(){
	for (int i = 0; i < 4; i += 1) {
		for (int j = 0; j < 4; j += 1) {
			if (currentBlock->units[i][j]->isInit() && theBoard[i + gapTop][j + gapLeft]->isInit()) {
				return false;
			}
		}
	}
	return true;
}

Block* Board::getNextBlock() {
	return nextBlock;
}

bool Board::isBlind() {
	return blind;
}

void Board::toggleBlind() {
	if (blind) {
		blind = false;
	}
	else {
		blind = true;
	}
}

void Board::outputGraphics() {
	graphicWindow->fillRectangle(0, 0, 230, 465, 0);

	graphicWindow->drawBigString(5, 10, "Player: " + to_string(playerNumber), Xwindow::Black);
	graphicWindow->drawBigString(5, 30, "Score: " + to_string(getScore()), Xwindow::Black);
	graphicWindow->drawBigString(5, 50, "Level: " + to_string(getCurrentLevel()->currentLevel), Xwindow::Black);

	for (int i = 0; i < 18; i += 1) {
		for (int j = 0; j < 11; j += 1) {
			if (i >= getGapTop() && i - getGapTop() < 4 && j >= getGapLeft() && j - getGapLeft() < 4) {

				if (getCurrentBlock()->units[i - getGapTop()][j - getGapLeft()]->isInit()) {
					graphicWindow->fillRectangle(5 + 20 * j, (20 * i) + 100, 20, 20, getCurrentBlock()->units[i - getGapTop()][j - getGapLeft()]->getColor());
				}
				else if (getTheBoard()[i][j]->isInit()) {
					graphicWindow->fillRectangle(5 + 20 * j, (20 * i) + 100, 20, 20, getTheBoard()[i][j]->getColor());
				}
			}
			else if (getTheBoard()[i][j]->isInit()) {
				graphicWindow->fillRectangle(5 + 20 * j, (20 * i) + 100, 20, 20, getTheBoard()[i][j]->getColor());
			}

		}
	}
}

