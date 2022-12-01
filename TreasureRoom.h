#pragma once
#include "Room.h"
class TreasureRoom : public Room
{
public:
	// constructor
	TreasureRoom(string, int, int);
	// destructor
	virtual ~TreasureRoom();

//functions
	void printRoom(Monk &monk);


};

