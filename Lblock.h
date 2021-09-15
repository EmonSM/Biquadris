#ifndef LBLOCK_H
#define LBLOCK_H

#pragma once
#include "block.h"

class Lblock : public Block {
	public:
		Lblock();
		void rotate(int direction);
};

#endif

