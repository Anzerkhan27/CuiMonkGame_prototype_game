#pragma once

#include<iomanip>
#include<ctime>
#include "Monk.h"
#include <vector>
#include "Room.h"
#include "Room.h"
#include "RandGenerator.h"



using namespace std;

class Game
{
public:
	//Constructor
	Game();
	//virtual Destructor
	virtual ~Game();

	//Functions
	void mainMenu(); // display main menu
	void gameInit(); // start the game 
	void chooseDifficulty(); // set dificulty 
	void generateDungeon(); // generate rooms objects
	void generateRoom(vector<Room *>,int);  // print first room
	void goToConnectedRooms(vector<Room*>); // print connected rooms
	void virtualViaPointer(Room*);  // using base clases pointers 


  

	//Accessors
	inline const bool getRunning() const {return (this->running);}  
	inline const int getDifficulty() const { return (this->difficulty); }
	inline  int  getNumberOfRooms() const { return (this->numberOfRooms); }
	inline string  getGameLog() { return this->gameLog; };
	//modifiers
	void setDifficulty(int);   
	void setNumberOfRooms(int);
	void addToGameLog(string);
private:
	//date memebers
	int choice;
	int numberOfRooms;
	bool running;
	int difficulty;
	string gameLog;
	RandGenerator randomise;
	Monk monk;







};
