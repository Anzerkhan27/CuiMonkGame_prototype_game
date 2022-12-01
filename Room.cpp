#include "Room.h"
#include <fstream>

Room::Room(string n, int number,int num2) :name(n), roomNumber(number), isVisited(num2) {

	

}
// mark the room visited 
void Room::markVisited()
{
	this->isVisited = 1;

}
void Room::setGameLogData(string name)
{
	this->gameLogData = name;
}
// print room file on the screen 
void Room::printCurrentRoom(string fileName)
{
	fstream file(fileName);		//fstream represents the file stream (both ofstream and ifstream capabilities).

	if (file.is_open()) {
		cout << file.rdbuf() << endl;
		file.close();
	}
	else {
		cout << "Error - File cannot be opened";
	}

}

void Room::addToGameLog(string n)
{
	this->gameLogData += n + "\n";
}


