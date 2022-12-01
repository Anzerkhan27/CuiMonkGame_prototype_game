#include "RandGenerator.h"
#include <random>

RandGenerator::RandGenerator()
{
}

RandGenerator::~RandGenerator()
{
}

// generate a random number between 1 and number of rooms
int RandGenerator::generateRandRoom(int n)
{
	int i= 0;
	i = (rand() % n) + 1;
	return i;
}
// genreate a random number between 0 and 1
int RandGenerator::generateRandChoice()
{

	int i;
	i = (rand() % 2);
	return i;
}
