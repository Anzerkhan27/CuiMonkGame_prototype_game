#pragma once
#include "Room.h"
#include "EmptyRoom.h"

class AttackRoom : public Room
{
public:
	//constructor
	AttackRoom(string, int,int);

	//functions
	virtual void printRoom(Monk &monk);// pure virtual function of the base class Room





};

