#include "Game.h"
#include <iostream>
#include <windows.h>
#include "Room.h"
#include "EmptyRoom.h"
#include "MonsterRoom.h"
#include "AttackRoom.h"
#include "TreasureRoom.h"
#include <algorithm>
#include <random>
#include <fstream>
#include "EndRoom.h"
#include "EndRoom.h"
#include "RandGenerator.h"
using namespace std;




void saveGameLogs(string n) {


	ofstream outfile("gameLog.txt");
	outfile << endl << "Full game log" << endl;
	outfile << n;
	outfile.close();
}


void printCurrentRoom(string fileName) //Prints the text file on screen
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

// input validation function 

int getChoice() {          

	


	int choice = 0;
	
	cin >> choice;


	while (!cin.good()) {
	
		cout << "Faulty Input" << endl;
		Sleep(600);
		system("CLS");
		cin.clear();
		cin.ignore(INT_MAX, '\n');


		string fileName = "SplashScreen.txt";  
		printCurrentRoom(fileName);
	
		cin >> choice;
	}

	return choice;


}

Game::Game()
{
	// setting Default values
	choice = 0;
	difficulty = 1;
	running = true;
	numberOfRooms = 4;
}

Game::~Game()
{


}

// displaying the Main Menu on the screen
void Game::mainMenu()
{
	string fileName = "SplashScreen.txt";
	printCurrentRoom(fileName);  // print the current room file

	choice = getChoice();




		switch (choice) {

		case 0:             // if user inputs 0 quit the game 
			
			running = false;
			break;
		case 1:           // if the user inputs 1 start the game 

			gameInit();   // set the name and descirption of the player 
			generateDungeon();  
			running = false;

			break;

		case 2:

			chooseDifficulty();      // select dificulty 
			break;


		case 3:
			system("ClS");
			printCurrentRoom("Instructions.txt");
			Sleep(1200);
			break;


		default:
			cout << "Faulty input";
			Sleep(600);
			system("CLS");

			break;
		}

	}
	


// instantiate the monk object by asking user the name and description 

void Game::gameInit()
{

	system("CLS");
	string name;
	string description;
	
	cin.ignore();


	cout << "Enter Monk's name: " ;
	getline(cin, name);
	while (name.empty()) {        // check if the input is empty or not 
		cout << "Enter a name!" << endl;
		
		Sleep(6000);
		system("CLS");
		cout << "Enter Monk's name: ";
		getline(cin, name);
	
	}

	cout << "Enter Description: ";
	getline(cin, description);
	if (description.empty()) {
		cout << "Enter a description!" << endl;
		cout << "Enter Description: ";
		getline(cin, description);

	}
	cout << "Entering a Room......";
	Sleep(600);//sleeps for 6 second

	monk.initialise(name, description);      // set the name and description  for the the monk object 

}

void Game::chooseDifficulty()
{

	system("CLS");
	int choice;
	cout << "SELECT DIFFICULTY " << endl << endl;
	cout << "-----------------------------------" << endl;
	cout << "[1]EASY    [2]Medium(default)   [3]Hard " << endl;

	cin >> choice;

	switch (choice)
	{

	case 1:                // if the user inputs 1 set the difficulty to easy 
		setDifficulty(0);
		setNumberOfRooms(3);  // set the number of rooms to 3
		system("CLS");
		break;
	case 2:              // if the user inputs 2 set the difficulty to medium 
		setDifficulty(1);
		setNumberOfRooms(4);  // set the number of rooms to 4
		system("CLS");
		break;
	case 3:
		setDifficulty(2);   // if the user inputs 3 set the difficulty to hard
		setNumberOfRooms(5); // set the number of rooms to 5
		system("CLS");
		break;
	default:
		break;
	}



}
// gnerates the Dungeon
void Game::generateDungeon()
{

	
	// instantiate all the room objects
	EmptyRoom room("Empty Room", 1, 0);
	MonsterRoom room1("Monster Room", 2, 0);
	AttackRoom room2("Attack Room", 3, 0);
	MonsterRoom room3("Monster Room", 4, 0);
	TreasureRoom room4("TreasureRoom", 0, 0);
	MonsterRoom room5("Monster Room", 5, 0);
	EndRoom room6("EndRoom", 6, 0);



	//create a vector of base class pointers 
	vector <Room*> rooms;
	rooms.push_back(&room);
	rooms.push_back(&room1);
	rooms.push_back(&room2);



	srand(time(NULL));
	
    int i = randomise.generateRandRoom(numberOfRooms);  // generate a random number in the range of 1 to number of rooms

	

	// add the monster according to level of difficulty 
	switch (difficulty)

	{

	case 0:        // if dificulty level is eassy on add one monster room
		break;

	case 1:
		rooms.push_back(&room3);       // add 2 monster rooms at default dificulty 
		break;
	case 2:               // add two monster rooms at hard difficulty 

		rooms.push_back(&room3);
		rooms.push_back(&room5);

		break;
	default:
		break;
	}


   generateRoom(rooms, i);     // print the first room 
  

   auto rng = std::default_random_engine{};
   shuffle(begin(rooms), end(rooms), rng);   // shuffle the vector for generating random rooms
  
   rooms.push_back(&room4);                 // add treasure room at the end of the vector 
   

   goToConnectedRooms(rooms);             //  print all the rooms of the vector which have not been visited yet 


   room6.printRoom(monk); // print the final stats 
  
  
   saveGameLogs(getGameLog());

	}


// print the first dungeon room by iterating over the rooms vector 
void Game::generateRoom(vector<Room *> roomList,int i)
{

	for (int j = 0; (j < roomList.size() )&& (monk.getHp() > 0); j++)
	{


	if (roomList[j]->getRoomNo() == i) {
		
	  virtualViaPointer(roomList[j]);            // use base class pointers for run time polymorphism 
	    addToGameLog(roomList[j]->getGameLog());
		}
	
		
			}
		}

	

// print the remaining rooms untill the player is not dead 

void Game::goToConnectedRooms(vector<Room*> roomList)
{

	for (int k = 0; (k < roomList.size()) && (monk.getHp() > 0); k++) {

		{
			if (roomList[k]->isAlreadyVisited() == 0)         // if the room is not being visited print the room
			{
			
			 virtualViaPointer(roomList[k]);
			 addToGameLog(roomList[k]->getGameLog());
				


				}
			}}

	}








	


// use of base class pointers for run time polymorphism 
void Game::virtualViaPointer(Room* baseClassPtr)
{
	baseClassPtr->printRoom(monk);
}


// set dificulty

void Game::setDifficulty(int n)
{
	this->difficulty = n;


	
}
// set number of rooms
void Game::setNumberOfRooms(int n)
{
	this->numberOfRooms = n;

}

void Game::addToGameLog(string n)
{
	this->gameLog += n + "\n";
}

