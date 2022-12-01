#include "EmptyRoom.h"
#include <windows.h>
EmptyRoom::EmptyRoom(string n, int number, int num2) : Room(n, number,num2)
{


}

// overding pure virtual function from the parent class Room
void EmptyRoom::printRoom(Monk &monk)
{
	markVisited(); // mark the room visited by setting value of isVisited to 1
	monk.setRoomsVisited(); //  increment the number of rooms visited 
	system("CLS");   // clear screen
	addToGameLog("Visited EmptyRoom");
	int choice{};
	while (choice != 2)     // while the player doesnt go to the next room 
	{

		string filename = "EmptyRoom.txt";
		printCurrentRoom(filename); // print the room file

		cout << "-------------------------------------" << endl;

		cout << monk.getName() << " HP: " << monk.getHp() << endl;     // display the player attributes on the screem
		cout << "----------------------------" << endl << endl;




		cin >> choice;
		while (!cin.good()) {       // Input Validation

			cout << "Faulty Input" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cin >> choice;
		}




		switch (choice)
		{
		case 1:


			cout << "Praying......" << endl;
			addToGameLog("Praying.....");
			monk.gainFullHp();    // Restore Player's Hp to 15
			Sleep(600);          // sleep for smooth transition
			system("CLS");
			
			break;
		case 2:
			cout << "Walking to the next Room------" << endl;
			addToGameLog("Walking to the next Room------");
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




