#include "MonsterRoom.h"
#include "Monster.h"
#include <windows.h>

MonsterRoom::MonsterRoom(string nm, int number,int num2) : Room(nm, number,num2)
{

}

MonsterRoom::~MonsterRoom()
{
}
// overding pure virtual function from the parent class Room
void MonsterRoom::printRoom(Monk &monk)
{
	markVisited(); // mark the room visited by setting value of isVisited to 1
	monk.setRoomsVisited();  //  increment the number of rooms visited 
	system("CLS");   // clear screen
	addToGameLog("Visited Monster Room ");
	// set turn for monk 
	int turn = 0;
	int nextStep{};


	monster.initialise("Goblin", "A scary creature");  // set name and description for monster 

	do
	{
		string filename = "MonsterRoom.txt";
		printCurrentRoom(filename);

		// display the current Hp and Ap for monk and monster
		cout << monk.getName() << " HP: " << monk.getHp() << " AP: " << monk.getAp() << endl;
		cout << monster.getName() << " HP: " << monster.getHp() << " AP: " << monster.getAp() << endl << endl;
		
		
		if (turn == 1) {
			//Monsters Turn!
			cout << "Monsters Turn" << endl;
			addToGameLog("Monsters Turn");
			int i = rand() % 2;
			if (i == 1) { // Monster will attack

				cout << "Monster is Attacking" << endl;
				addToGameLog("Monster is Attacking");
				
				Sleep(600);
				int j = randomise.generateRandChoice();  //generate random number 
				if (j == 0) {

					cout << "Attack succesfull" << endl;
					addToGameLog("Attack succesfull");
					Sleep(600);  // sleep for 6 seconds
					monk.damage(monster.getAp());     // reduce monks Hp by monsters Ap
					monk.setDamageTaken(monster.getAp());  // record the damage taken
					system("CLS");
					turn = 0;   // give turn to monk 

				}
				else if (j == 1) {  // attack failed 

					cout << "Attack failed";
					addToGameLog("Attack failed");
					Sleep(600);
					system("CLS");
					turn = 0;

				}


			}
			else if (i == 0) {  // Monster will defend 
				cout << "Monster is Defending" << endl;
				addToGameLog("Monster is Defending");
				Sleep(600);
				int j = randomise.generateRandChoice();
				if (j == 0) {

					cout << "Defence succesfull" << endl << endl;
					addToGameLog("Defence succesfull");
					monster.gainHp();  // gain hp by 1
					Sleep(600);
					system("CLS");

					turn = 0;

				}
				else if (j == 1) {

					cout << "Defence failed" << endl;
					addToGameLog("Defence failed");
					Sleep(600);
					system("CLS");
					turn = 0;



				}
			}
		}
		else if (turn == 0)

		{
			cout << "Monks Turn" << endl;
			addToGameLog("Monks Turn");
			cout << "[1]ATTACK " << endl << "[2]DEFEND" << endl;

			cin >> nextStep;    // player will attack or defence 

			while (!cin.good()) {  // Input validation 

				cout << "Faulty Input" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');

				cin >> nextStep;
			}

			if (nextStep == 1)   // Player will attack 
			{
				cout << "Attacking Monster!" << endl;
				addToGameLog("Attacking Monster!");
				Sleep(600);
				int i = randomise.generateRandChoice();  // generate a random number between 0 and 1
				if (i == 0)   // Attack succesfull
				{
					cout << "Attack Successfull";
					addToGameLog("Attack Successfull");
					monster.damage(monk.getAp());    // reduce monsters Hp by monks Ap
					monk.setDamageDone(monk.getAp());  // record the damage done
					Sleep(600);
					system("CLS");
					turn = 1;
				}
				else {
					cout << "Attack failed";
					addToGameLog("Attacking failed");
					Sleep(600);
					system("CLS");
					turn = 1;

				}
			}
			else if (nextStep == 2) {
				cout << "Defending" << endl;
				addToGameLog("Defending");
				Sleep(600);
				int i = randomise.generateRandChoice();
				if (i == 0)   // Defence  succesfull
				{
					cout << "Defence Successfull" << endl;
					addToGameLog("Defence Successfull");

					monk.gainHp();  // gain Hp by 1
					Sleep(600);
					system("CLS");
					turn = 1;
				}
				else {
					cout << "Defence failed" << endl;
					addToGameLog("Defence Failed");
					Sleep(600);
					system("CLS");
					turn = 1;

				}


			}
			else
			{
				cout << "Faulty input" << endl;
				Sleep(600);
				system("CLS");
			}
		}
	}

	while ((monk.getHp() > 0) && (monster.getHp() > 0));  // while monster or monk is not dead 

	if (monk.getHp() > 0) {

		cout << "You have KILLED THE MONSTER!" << endl;
		addToGameLog("You have KILLED THE MONSTER!");
		monk.setMonstersKilled();  // incremenet number of monster killed by 1
		cout << "Walking to the next Room---------";
		addToGameLog("Walking to the next Room---------");
		Sleep(800);
	}
	else {

		cout << "Monster KILLED YOU!" << endl;
		addToGameLog("Monster KILLED YOU!");
		cout << "You have LOST!" << endl;
		addToGameLog("You have Lost");
		Sleep(1500);
		system("CLS");
	}

	
}
