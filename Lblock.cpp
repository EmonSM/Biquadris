#include "Lblock.h"
#include <iostream>

Lblock::Lblock() {
	length = 3;

	units[3][0]->initialize("L", uniqueBlockId);
	units[3][1]->initialize("L", uniqueBlockId);
	units[3][2]->initialize("L", uniqueBlockId);
	units[2][2]->initialize("L", uniqueBlockId);
}

void Lblock::rotate(int direction) {

	Block::rotate(direction);

	if (rotation == 0) {
		units[3][0]->initialize("L", uniqueBlockId);
		units[3][1]->initialize("L", uniqueBlockId);
		units[3][2]->initialize("L", uniqueBlockId);
		units[2][2]->initialize("L", uniqueBlockId);

		length = 3;
	}

	else if (rotation == 1) {
		units[1][0]->initialize("L", uniqueBlockId);
		units[2][0]->initialize("L", uniqueBlockId);
		units[3][0]->initialize("L", uniqueBlockId);
		units[3][1]->initialize("L", uniqueBlockId);

		length = 2;
	}

	else if (rotation == 2) {
		units[3][0]->initialize("L", uniqueBlockId);
		units[2][0]->initialize("L", uniqueBlockId);
		units[2][1]->initialize("L", uniqueBlockId);
		units[2][2]->initialize("L", uniqueBlockId);

		length = 3;
	}

	else {
		units[1][0]->initialize("L", uniqueBlockId);
		units[1][1]->initialize("L", uniqueBlockId);
		units[2][1]->initialize("L", uniqueBlockId);
		units[3][1]->initialize("L", uniqueBlockId);

		length = 2;
	}
}




