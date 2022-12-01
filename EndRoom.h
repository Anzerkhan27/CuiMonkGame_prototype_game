#pragma once
#include "Room.h"
class EndRoom : public Room
{

public:
	//constructor
	EndRoom(string, int, int);

	//functions
	virtual void printRoom(Monk& monk);


};

