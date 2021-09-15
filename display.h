#pragma once
#include <iostream>
#include "board.h"

class TextDisplay
{
public:
	TextDisplay();
	~TextDisplay();

	void printBoard(vector <Board*> players, int highScore);
};

