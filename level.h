#ifndef LEVEL_H
#define LEVEL_H


#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "block.h"
#include "Iblock.h"
#include "Sblock.h"
#include "Jblock.h"
#include "Lblock.h"
#include "Oblock.h"
#include "Tblock.h"
#include "Zblock.h"
#include "_1block.h"

using namespace std;

class Level {


	public:
		Level();

		~Level();

		int currentLevel;
		int seed;
		bool heavy;

		void setSeed(int seedS);

		virtual Block* getNextBlock() = 0;
		ifstream file;
		string fileName;
};

#endif
