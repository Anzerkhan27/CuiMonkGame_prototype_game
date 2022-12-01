#include "TreasureRoom.h"
#include  <windows.h>

TreasureRoom::TreasureRoom(string nme, int num1, int num2) : Room(nme, num1, num2)
{


}

TreasureRoom::~TreasureRoom()

{


}
// overding pure virtual function from the parent class Room
void TreasureRoom::printRoom(Monk& monk)
{

	markVisited();// mark the room visited by setting value of isVisited to 1
	monk.setRoomsVisited();  //  increment the number of rooms visited 
	system("CLS");   // clear screen
	addToGameLog("Visited Treasure");

	int choice{};
	
	{

		string filename = "TreasureRoom.txt";
		printCurrentRoom(filename);

		cout << "-------------------------------------" << endl;

		cout << monk.getName() << " HP: " << monk.getHp() << endl;  // display players Hp 
		cout << "----------------------------" << endl << endl;




		cin >> choice;
		while (!cin.good()) {  // input validation 

			cout << "Faulty Input" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cin >> choice;
		}


		// if the user inputs 1 the player wins the game 
		switch (choice)
		{
		case 1:              
			cout << "Taking Treasure............." << endl;
			addToGameLog("Taking Treasure...........");
			Sleep(1000);
			system("CLS");
			cout << "YOU HAVE WON THE GAME" << endl;
			addToGameLog("YOU HAVE WON THE GAME");
			Sleep(1500);
		
			break;

		default:
				cout << "Faulty input";
			Sleep(300);
			system("CLS");

			break;
		}
	}


}
