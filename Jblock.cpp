#include "Jblock.h"
#include <iostream>

Jblock::Jblock() {
	length = 3;

	units[2][0]->initialize("J", uniqueBlockId);
	units[3][0]->initialize("J", uniqueBlockId);
	units[3][1]->initialize("J", uniqueBlockId);
	units[3][2]->initialize("J", uniqueBlockId);
}

void Jblock::rotate(int direction) {

	Block::rotate(direction);

	if (rotation == 0) {
		units[2][0]->initialize("J", uniqueBlockId);
		units[3][0]->initialize("J", uniqueBlockId);
		units[3][1]->initialize("J", uniqueBlockId);
		units[3][2]->initialize("J", uniqueBlockId);

		length = 3;
	}

	else if (rotation == 1) {
		units[3][0]->initialize("J", uniqueBlockId);
		units[2][0]->initialize("J", uniqueBlockId);
		units[1][0]->initialize("J", uniqueBlockId);
		units[1][1]->initialize("J", uniqueBlockId);

		length = 2;
	}

	else if (rotation == 2) {
		units[2][0]->initialize("J", uniqueBlockId);
		units[2][1]->initialize("J", uniqueBlockId);
		units[2][2]->initialize("J", uniqueBlockId);
		units[3][2]->initialize("J", uniqueBlockId);

		length = 3;
	}

	else {
		units[3][0]->initialize("J", uniqueBlockId);
		units[3][1]->initialize("J", uniqueBlockId);
		units[2][1]->initialize("J", uniqueBlockId);
		units[1][1]->initialize("J", uniqueBlockId);

		length = 2;
	}
}



