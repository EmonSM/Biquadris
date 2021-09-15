#pragma once
#ifndef UNIT_H
#define UNIT_H


#include <string>

#include <vector>
using namespace std;

class Unit{

	bool init;
	int score;
	string BlockString; // character that represents block


public:

	Unit();
	bool isInit();

	void initialize(string BlockString, int blockId);
	void deInit();

	string getBlockString();
	int getScore();
	void setScore(int points);
	int blockId;

	int getColor();

};

#endif
