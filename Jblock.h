#ifndef JBLOCK_H
#define JBLOCK_H

#pragma once
#include "block.h"

class Jblock : public Block {
	public:
		Jblock();
		void rotate(int direction);
};

#endif

