#pragma once
class RandGenerator
{
public:
	//constructor
	RandGenerator();
	//destructor
	virtual ~RandGenerator();

//functions
	int generateRandRoom(int);  // generate a random number for rooms according to given rooms
	int generateRandChoice();  // generate a random number between 0 and 1

};

