#pragma once
#include <string>
#include "Monk.h"


using namespace std;

class Room
{
public:
	//Constructor
	Room(string, int, int);


	//Accessors
	inline string  const getName() const { return this->name;};
	inline int  const getRoomNo() const {return this->roomNumber;};
	inline int const isAlreadyVisited() const { return this->isVisited; }
	inline string  getGameLog()  { return this->gameLogData; };


	//modifiers
	void markVisited();  // set roomVisited to  1
	void setGameLogData(string);
	//functions
	virtual	void  printRoom(Monk &monk) = 0;  // pure virtual function
	void printCurrentRoom(string);   //   print  room file on the screen
	void addToGameLog(string);



private:
	string name;   // name of the room
	int roomNumber;  // room number number 
	int isVisited;   // set to 1 if room visited
	string gameLogData; 
	
};


