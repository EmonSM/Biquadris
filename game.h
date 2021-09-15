#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include "board.h"
#include "display.h"
#include <sstream>
#include "commands.h"
using namespace std;

class game
{
	void getChangedInput(string& cmd);
	bool processInputs(string& cmd, ofstream& myfile, ifstream& inFile);
	commands com;


	vector <Board*> players;

	public:
	void runGame(int argc, char* argv[]);
};

#endif
