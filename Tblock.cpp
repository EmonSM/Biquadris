#include "Tblock.h"
#include <iostream>

Tblock::Tblock() {
	length = 3;

	units[2][0]->initialize("T", uniqueBlockId);
	units[2][1]->initialize("T", uniqueBlockId);
	units[3][1]->initialize("T", uniqueBlockId);
	units[2][2]->initialize("T", uniqueBlockId);
}

void Tblock::rotate(int direction) {

	Block::rotate(direction);

	if (rotation == 0) {
		units[2][0]->initialize("T", uniqueBlockId);
		units[2][1]->initialize("T", uniqueBlockId);
		units[3][1]->initialize("T", uniqueBlockId);
		units[2][2]->initialize("T", uniqueBlockId);

		length = 3;
	}

	else if (rotation == 1) {
		units[2][0]->initialize("T", uniqueBlockId);
		units[1][1]->initialize("T", uniqueBlockId);
		units[2][1]->initialize("T", uniqueBlockId);
		units[3][1]->initialize("T", uniqueBlockId);

		length = 2;
	}

	else if (rotation == 2) {
		units[3][0]->initialize("T", uniqueBlockId);
		units[2][1]->initialize("T", uniqueBlockId);
		units[3][1]->initialize("T", uniqueBlockId);
		units[3][2]->initialize("T", uniqueBlockId);

		length = 3;
	}

	else if (rotation == 3) {
		units[1][0]->initialize("T", uniqueBlockId);
		units[2][0]->initialize("T", uniqueBlockId);
		units[3][0]->initialize("T", uniqueBlockId);
		units[2][1]->initialize("T", uniqueBlockId);

		length = 2;
	}
}



