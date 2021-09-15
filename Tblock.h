#ifndef TBLOCK_H
#define TBLOCK_H

#pragma once
#include "block.h"

class Tblock : public Block {
	public:
		Tblock();
		void rotate(int direction);
};

#endif

