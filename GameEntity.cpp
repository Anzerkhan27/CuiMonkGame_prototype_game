#include "GameEntity.h"
#include <windows.h>


//constructor
GameEntity::GameEntity()
{
}
//destructor
GameEntity::~GameEntity()
{
}

// set the name and descirption of the GameEntity object
void GameEntity::initialise(string name, string description)
{
	this->name = name;
	this->description = description;
}



void GameEntity::setName(string name)
{
	this->name = name;
}

void GameEntity::setDescription(string name)
{
	this->description = name;
}

void GameEntity::setHp(int hP)
{
	this->hP = hP;
}

void GameEntity::setAp(int aP)
{
	this->aP = aP;

}



// reduce the hP by n 

void GameEntity::damage(int n)
{
	this->hP = this->hP - n;
}

// gain hP by 1

void GameEntity::gainHp()
{
	if (this->hP < 15) { 
		this->hP++;
	}
	else {
		cout << "Hp already Full";
		Sleep(600);
	}
	}
