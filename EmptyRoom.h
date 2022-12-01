#pragma once
#include "Room.h"
#include "MonsterRoom.h"
class EmptyRoom : public Room
{
public:
	//constructor 
	EmptyRoom(string, int,int);

	//functions
	virtual void printRoom(Monk &monk);// pure virtual function of the base class Room



	

};

