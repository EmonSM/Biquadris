#ifndef LEVEL0_H
#define LEVEL0_H

#include "level.h"


#pragma once
class level0 :public Level {
	public:
		level0(string in);
		~level0();
		Block* getNextBlock();
};

#endif
