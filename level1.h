#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"
class level1 : public Level {
	public:
		level1();
		~level1();
		Block* getNextBlock();
};

#endif
