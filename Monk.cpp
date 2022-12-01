#include "Monk.h"
#include <windows.h>

Monk::Monk()
{
	// set default values 
	GameEntity::setHp(15);
	GameEntity::setAp(3);
	roomsVisited = 0;
	monstersKilled = 0;
	damageDone = 0;
    damageTaken = 0;

}

Monk::~Monk()
{
}

// display the player stats 

void Monk::getAsString() const
{
	cout << "Player Details: " << endl;
	cout << "Name:  " << getName() << endl;
	cout << "Description:  " << getDescription() << endl;
	cout << "Hp :" << getHp() << endl;
	cout << "Ap :" << getAp() << endl;
	cout << "Rooms Visited: " << getRoomsVisited() << endl;
	cout << "Monsters Killed:  " << getMonstersKilled() << endl;
	cout << "Damage Done: " << getDamageDone() << endl;
	cout << "Damage Taken: " << getDamageTaken() << endl;


}

// restore hP to 15
void Monk::gainFullHp()
{
	
	if (GameEntity::getHp() == 15)

	{
		cout << "Your Hp is already full!";
	}
	else {
		GameEntity::setHp(15);
	}
	


}
// loose or gain hp and ap by 1
void Monk::gainOrLoosePts()
{
	int i = rand() % 2;
	switch (i)
	{

	case 0:


		if (getAp() < 6) {
			GameEntity::setAp(getAp() + 1);
			cout << "Attack points increased!" << endl;

		}
		else {
		
			cout << "Attack points already full" << endl;
		
		}
		if (getHp() < 15)
		{
			GameEntity::setHp(getHp() + 1);
			cout << "Health points increased" << endl;
		}
		else
		{
			cout << "Health points  already full";
		}


	
		break;
	case 1:
		if (getAp() > 1)
		{
			GameEntity::setAp(getAp() - 1);
			cout << "Ap decreased!" << endl;
		}
		else {
		
			cout << "Cannot decrease more Attack points" << endl;
		}
		if (getHp() > 1) {

			GameEntity::setHp(getHp() - 1);
			cout << "Hp decreased" << endl;
		}
		else {
		
			cout << "Cannot decrease more health points";
		}
		

		break;


	default:
		break;
	}



}

void Monk::setRoomsVisited()
{
	this->roomsVisited++;
   
}

void Monk::setMonstersKilled()
{
	this->monstersKilled++;

}

void Monk::setDamageDone(int n)
{
	this->damageDone = this->damageDone + n;

}

void Monk::setDamageTaken(int n)
{
	this->damageTaken = this->damageTaken + n;

}



