
#include <cstdlib>
#include "level4.h"

using namespace std;

level4::level4() {
	currentLevel = 4;
	heavy = true;
	srand(seed);
}


level4::~level4()
{
}



Block* level4::getNextBlock() {

	int randomNum = rand() % 9;

	if (randomNum == 0) {
		return new Iblock();
	}
	else if (randomNum == 1) {
		return new Jblock();
	}
	else if (randomNum == 2) {
		return new Lblock();
	}
	else if (randomNum == 3) {
		return new Oblock();
	}

	else if (randomNum == 4) {
		return new Tblock();
	}
	else if (randomNum == 5 || randomNum == 6) {
		return new Sblock();
	}
	else if (randomNum == 7 || randomNum == 8) {
		return new Zblock();
	}
	else {
		cout << "CHECK LEVEL4.cpp" << endl;
		return nullptr;
	}
}