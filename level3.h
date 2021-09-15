#ifndef LEVEL3_H
#define LEVEL3_H

#include "level.h"
class level3 : public Level {
	public:
		level3();
		~level3();
		Block* getNextBlock();
};

#endif
