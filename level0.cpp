#include "level0.h"
#include <iostream>
using namespace std;


level0::level0(string in) {

	currentLevel = 0;
	fileName = in;
	file.open(fileName);



	if (!file.is_open()) {
		std::cout << "Unable to open file" << endl;
	}

	heavy = false;
}

level0::~level0()
{
	file.clear();
	file.close();
}

Block *level0::getNextBlock() {
	string read;
	
	file >> read;

	if (file.fail()) {
		file.clear();
		file.open(fileName);
	}
	else if (read == "I") {
		return new Iblock();
	}
	else if (read == "J") {
		return new Jblock();
	}
	else if (read == "L") {
		return new Lblock();
	}
	else if (read == "O") {
		return new Oblock();
	}
	else if (read == "S") {
		return new Sblock();
	}
	else if (read == "T") {
		return new Tblock();
	}
	else if (read == "Z") {
		return new Zblock();
	}
	else {
		cout << "CHECK LEVEL0.cpp" << endl;
		return nullptr;
	}
}
