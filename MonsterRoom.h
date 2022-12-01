#pragma once
#include "Room.h"
#include "AttackRoom.h"
#include "Monster.h"
#include "RandGenerator.h"
class MonsterRoom : public Room
{
public:
	//constructor
	MonsterRoom(string, int,int);
	//destructor
	virtual ~MonsterRoom();

	//functions
	virtual void printRoom(Monk &monk);  // pure virtual function of the base class Room


private:
	Monster monster;    //  Monster object used in the room
	RandGenerator randomise;  // to generate a random number 
};

