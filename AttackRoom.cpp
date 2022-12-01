#include "AttackRoom.h"
#include <windows.h>


AttackRoom::AttackRoom(string nm, int number,int num2) : Room(nm, number,num2)
{
	setGameLogData("");
}
// overding pure virtual function from the parent class Room
void AttackRoom::printRoom(Monk& monk)
{
	markVisited();     // mark the room visited by setting value of isVisited to 1
	monk.setRoomsVisited();  //  increment the number of rooms visited 
	system("CLS");    // clear screen
	addToGameLog("Visited AttackRoom");

	int choice{};
	while (choice != 2)               // while the player doesnt go to the next room 
	{
		string filename = "LuckyDrawRoom.txt";
		printCurrentRoom(filename);    // print the room file
		cout << "-------------------------------------" << endl;

		cout << monk.getName() << " HP: " << monk.getHp() << " AP : " << monk.getAp() << endl;  // display the player attributes on the screem
		cout << "----------------------------" << endl << endl;
	


		cin >> choice;
		while (!cin.good()) {               // Input Validation

			cout << "Faulty Input" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cin >> choice;
		}

	

		switch (choice)                
		{
		case 1:
			cout << "Drinking potion......" << endl;
			addToGameLog("Drinking potion.....");
			monk.gainOrLoosePts();          // gain or loose points depending upon the random number
			Sleep(800);                    // sleep function for smoothe transition
			system("CLS");

			break;
		case 2:

			cout << "Walking to the next Room------" << endl;
			Sleep(600);

			break;


		default:

			cout << "Faulty input";
			Sleep(300);
			system("CLS");

			break;
		}
	}
}

