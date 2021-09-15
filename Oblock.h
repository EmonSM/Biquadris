#ifndef OBLOCK_H
#define OBLOCK_H

#pragma once
#include "block.h"

class Oblock : public Block {
	public:
		Oblock();
		void rotate(int direction);
};

#endif

