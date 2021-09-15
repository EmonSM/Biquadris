#include "Zblock.h"
#include <iostream>

Zblock::Zblock() {
	length = 3;

	units[2][0]->initialize("Z", uniqueBlockId);
	units[2][1]->initialize("Z", uniqueBlockId);
	units[3][1]->initialize("Z", uniqueBlockId);
	units[3][2]->initialize("Z", uniqueBlockId);
}

void Zblock::rotate(int direction) {

	Block::rotate(direction);

	if (rotation == 0 || rotation == 2) {
		units[2][0]->initialize("Z", uniqueBlockId);
		units[2][1]->initialize("Z", uniqueBlockId);
		units[3][1]->initialize("Z", uniqueBlockId);
		units[3][2]->initialize("Z", uniqueBlockId);

		length = 3;
	}

	else {
		units[3][0]->initialize("Z", uniqueBlockId);
		units[2][0]->initialize("Z", uniqueBlockId);
		units[2][1]->initialize("Z", uniqueBlockId);
		units[1][1]->initialize("Z", uniqueBlockId);

		length = 2;
	}
}
