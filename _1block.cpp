#include "_1block.h"
#include <iostream>

_1block::_1block() {
	length = 1;

	units[3][0]->initialize("*", uniqueBlockId);

}

void _1block::rotate(int direction) {

	Block::rotate(direction);

	if (rotation == 0 || rotation == 1 || rotation == 2 || rotation == 3) {
		units[3][0]->initialize("*", uniqueBlockId);

		length = 1;
	}

}
