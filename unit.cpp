#include "unit.h"



Unit::Unit() {
	init = false;
	score = 0;
	blockId = -1;
}

bool Unit::isInit() {
	return init;
}

void Unit::initialize(string BlockString, int blockId) {
	this->BlockString = BlockString;
	this->blockId = blockId;
	score = 0;
	init = true;
}

void Unit::deInit() {
	init = false;
}


string Unit::getBlockString() {
	return BlockString;
}

int Unit::getScore() {
	return score;
}

void Unit::setScore(int points) {
	score = points;
}

int Unit::getColor() {
	if (BlockString == "S") {
		return 2;
	}
	else if (BlockString == "Z") {
		return 3;
	}
	else if (BlockString == "T") {
		return 4;
	}
	else if (BlockString == "L") {
		return 5;
	}
	else if (BlockString == "J") {
		return 6;
	}
	else if (BlockString == "O") {
		return 7;
	}
	else if (BlockString == "I") {
		return 8;
	}
	else if (BlockString == "*") {
		return 1;
	}
	else {
		return 9;
	}
}
