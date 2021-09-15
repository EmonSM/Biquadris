#ifndef ZBLOCK_H
#define ZBLOCK_H

#pragma once
#include "block.h"

class Zblock : public Block {
	public:
		Zblock();
		void rotate(int direction);
};

#endif

