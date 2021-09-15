#include "Oblock.h"
#include <iostream>

Oblock::Oblock() {
	length = 2;

	units[3][0]->initialize("O", uniqueBlockId);
	units[2][0]->initialize("O", uniqueBlockId);
	units[2][1]->initialize("O", uniqueBlockId);
	units[3][1]->initialize("O", uniqueBlockId);
}

void Oblock::rotate(int direction) {

	Block::rotate(direction);

	if (rotation == 0 || rotation == 1 || rotation == 2 || rotation == 3) {
		units[3][0]->initialize("O", uniqueBlockId);
		units[2][0]->initialize("O", uniqueBlockId);
		units[2][1]->initialize("O", uniqueBlockId);
		units[3][1]->initialize("O", uniqueBlockId);

		length = 2;
	}
}
