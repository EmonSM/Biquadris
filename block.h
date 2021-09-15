#ifndef BLOCK_H
#define BLOCK_H




#include <vector>
#include <string>
#include "unit.h"

using namespace std;

class Block {

	protected:
		int rotation; // 0, 1, 2, 3 for 0, 90, 180, 270 degree rotation to store location (only 2 for Iblock)
		int length;

	public:

		Block();
		virtual ~Block();
		static int numberOfBlocks;
		int uniqueBlockId;
		void clear();
		virtual void rotate(int direction);
		int getLength();
		vector <vector <Unit*>> units;
};

#endif
