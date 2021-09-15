#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
using namespace std;


struct commands {
	string right = "right";
	string left = "left";
	string down = "down";
	string drop = "drop";
	string clockwise = "clockwise";
	string counterClockwise = "counterclockwise";
	string heavy = "heavy";
	string force = "force";
	string blind = "blind";
	string levelUp = "levelup";
	string levelDown = "leveldown";
	string restart = "restart";
	string sequence = "sequence";
	string exit = "exit";

	string listOfCom[14] = { right, left, down, drop, clockwise, counterClockwise, heavy, force, blind, levelUp, levelDown, restart, sequence, exit };
}; 

#endif

