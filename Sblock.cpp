#include "Sblock.h"
#include <iostream>

Sblock::Sblock() {
	length = 3;

	units[3][0]->initialize("S", uniqueBlockId);
	units[3][1]->initialize("S", uniqueBlockId);
	units[2][1]->initialize("S", uniqueBlockId);
	units[2][2]->initialize("S", uniqueBlockId);
}

void Sblock::rotate(int direction) {

	Block::rotate(direction);

	if (rotation == 0 || rotation == 2) {
		units[3][0]->initialize("S", uniqueBlockId);
		units[3][1]->initialize("S", uniqueBlockId);
		units[2][1]->initialize("S", uniqueBlockId);
		units[2][2]->initialize("S", uniqueBlockId);

		length = 3;
	}

	else {
		units[1][0]->initialize("S", uniqueBlockId);
		units[2][0]->initialize("S", uniqueBlockId);
		units[2][1]->initialize("S", uniqueBlockId);
		units[3][1]->initialize("S", uniqueBlockId);

		length = 2;
	}


}
