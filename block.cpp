#include "block.h"



int Block::numberOfBlocks = 0;

Block::Block() {

	numberOfBlocks += 1;
	uniqueBlockId = numberOfBlocks;

	for (int i = 0; i < 4; i += 1) {
		vector <Unit*> v1;
		units.emplace_back(v1);
		for (int j = 0; j < 4; j += 1) {
			Unit* v2 = new Unit();
			v2->blockId = uniqueBlockId;
			units[i].emplace_back(v2);
		}
	}
	rotation = 0;
	length = 0;
}

Block::~Block() {
	for (int i = 0; i < 4; i += 1) {
		for (int j = 0; j < 4; j += 1) {
			delete units[i][j];
		}
	}
}

void Block::clear() {
	for (int i = 0; i < 4; i += 1) {
		for (int j = 0; j < 4; j += 1) {
			units[i][j]->deInit();
		}
	}
}

void Block::rotate(int direction) {

	clear();

	if (direction == 1) {
		rotation += 1;
		if (rotation == 4) {
			rotation = 0;
		}
	}

	else if (direction == -1) {
		rotation -= 1;
		if (rotation == -1) {
			rotation = 3;
		}
	}


}


int Block::getLength() {
	return length;
}
