#ifndef LEVEL4_H
#define LEVEL4_H

#include "level.h"
class level4 : public Level {
	public:
		level4();
		~level4();
		Block* getNextBlock();
};

#endif
