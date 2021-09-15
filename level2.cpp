
#include <cstdlib>
#include "level2.h"

using namespace std;

level2::level2(){
	currentLevel = 2;
	heavy = false;
}


level2::~level2()
{
}



Block* level2::getNextBlock() {
	
	int randomNum = rand() % 7;



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
		return new Sblock();
	}
	else if (randomNum == 5) {
		return new Tblock();
	}
	else if (randomNum == 6) {
		return new Zblock();
	}
	else {
		cout << "CHECK LEVEL2.cpp" << endl;
		return nullptr;
	}
}
