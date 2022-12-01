#include <iostream>
#include "Game.h"
#include "Room.h"


int main()
{
	srand(time(NULL));

	Game game;  // instantiate game object


	// while ruuning is true 
	while (game.getRunning()) {



		


		game.mainMenu(); // start the game 

	}


	return 0;

}


