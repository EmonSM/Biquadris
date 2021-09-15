#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"
class level2 : public Level{
	public:
		level2();
		~level2();
		Block* getNextBlock();
};

#endif
