#ifndef BOARD_H
#define BOARD_H

#pragma once
#include "block.h"

#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "window.h"

class Board {

	Level* currentLevel;
	int Score;

	int gapLeft;
	int gapTop;

	Block* currentBlock;
	Block* nextBlock;

	vector <vector <Unit*>> theBoard;

	string File;

	bool heavy;
	bool blind;
	
	int placed;
	Xwindow* graphicWindow;

	bool graphicsEnabled;


public:
	Board(string inFile, bool graphics);
	~Board();


	bool fixGap();

	static int playerCount;

	int playerNumber;

	void incrementGapLeft(int by = 1);
	void incrementGapTop(int by = 1);

	int getGapLeft();
	int getGapTop();

	Block* getCurrentBlock();
	Block* getNextBlock();
	Level* getCurrentLevel();

	vector <vector <Unit*>> getTheBoard();

	bool forceToPlace(); // Place block based on certain conditions
	void place(); // place the block

	void removeCompletedRows();

	void drop();

	bool checkEnd();

	string getFileName();

	void toggleHeavy();

	bool setCurrentBlock(string block, Block* old);

	void changeLevel(int by);

	int getScore();

	bool isPossible();  //  do this

	bool isBlind();

	void toggleBlind();

	bool specialAction;

	void outputGraphics();


};


#endif
