#pragma once
#include <iostream>
#include <string>

using namespace std;

class GameEntity
{
public:
	//constructor
	GameEntity();
	//destructor
	virtual ~GameEntity();


	//Functions
	void initialise(string name, string description);  // initialise the GameEntity object
	virtual void getAsString() const = 0;   // pure virtual function to be overiden in child classes

	//Accesors
	inline const string& getName() const {return this->name;};

	inline const string& getDescription() const {return this->description;};

	inline const int& getHp() const {return this->hP;};

	inline const int& getAp() const {return this->aP;};





	//Modifiers
	void setName(string);
	void setDescription(string);
	void setHp(int);
	void setAp(int);

	void damage(int); // reducing the hp with the given Ap
	void gainHp();   //  gain hp by 1









private:
	string name;
	string description;
	int hP;
	int aP;







};

