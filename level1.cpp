
#include <cstdlib>
#include "level1.h"

using namespace std;

level1::level1() {
	currentLevel = 1;
	heavy = false;
}


level1::~level1()
{
}



Block* level1::getNextBlock() {

	int randomNum = rand() % 12;

	if (randomNum == 0 || randomNum == 1) {
		return new Iblock();
	}
	else if (randomNum == 2 || randomNum == 3) {
		return new Jblock();
	}
	else if (randomNum == 4 || randomNum == 5) {
		return new Lblock();
	}
	else if (randomNum == 6 || randomNum == 7) {
		return new Oblock();
	}

	else if (randomNum == 8 || randomNum == 9) {
		return new Tblock();
	}
	else if (randomNum == 10) {
		return new Sblock();
	}
	else if (randomNum == 11) {
		return new Zblock();
	}
	else {
		cout << "CHECK LEVEL1.cpp" << endl;
		return nullptr;
	}
}