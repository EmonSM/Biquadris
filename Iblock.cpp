#include "Iblock.h"
#include <iostream>

Iblock::Iblock() {
	length = 4;

	units[3][0]->initialize("I", uniqueBlockId);
	units[3][1]->initialize("I", uniqueBlockId);
	units[3][2]->initialize("I", uniqueBlockId);
	units[3][3]->initialize("I", uniqueBlockId);
}

void Iblock::rotate(int direction) {

	Block::rotate(direction);

	if (rotation == 0 || rotation == 2) {
		units[3][0]->initialize("I", uniqueBlockId);
		units[3][1]->initialize("I", uniqueBlockId);
		units[3][2]->initialize("I", uniqueBlockId);
		units[3][3]->initialize("I", uniqueBlockId);

		length = 4;
	}

	else {
		units[0][0]->initialize("I", uniqueBlockId);
		units[1][0]->initialize("I", uniqueBlockId);
		units[2][0]->initialize("I", uniqueBlockId);
		units[3][0]->initialize("I", uniqueBlockId);

		length = 1;
	}


}
