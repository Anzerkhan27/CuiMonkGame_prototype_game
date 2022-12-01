#pragma once
#include "GameEntity.h"
class Monster : public GameEntity
{
public:
	//constructor
	Monster();
	//destructor
	virtual ~Monster();

//function
	virtual void getAsString() const ; // pure virtual function from the base class



};

