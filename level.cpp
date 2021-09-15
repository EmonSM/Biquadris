#include "level.h"



Level::Level(){
	currentLevel = 0;
	heavy = false; 
	seed = 0;
	fileName = "";
}




Level::~Level(){

	file.clear();
	file.close();
}


void Level::setSeed(int seedS) {
	seed = seedS;
}