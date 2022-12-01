#pragma once
#include "GameEntity.h"
class Monk : public GameEntity
{
public:
	//constructor
	Monk();
	//desstructor
	virtual ~Monk();

	//functions
	virtual void getAsString() const ; // pure virtual function from base parent class
	void gainFullHp();                // restore Hp to 15
	void gainOrLoosePts();            // radomly gain or loose points


	//Accessors
	inline const int& getRoomsVisited() const{ return this->roomsVisited; }
	inline const int& getMonstersKilled() const  { return this->monstersKilled; }
	inline int getDamageDone() const  { return this->damageDone; }
	inline int getDamageTaken() const  { return this->damageTaken; }
	//modifiers
	void setRoomsVisited();
	void setMonstersKilled();
	void setDamageDone(int);
	void setDamageTaken(int);



private:
	int roomsVisited;     
	int monstersKilled;
	int damageDone;  
	int damageTaken;

};

