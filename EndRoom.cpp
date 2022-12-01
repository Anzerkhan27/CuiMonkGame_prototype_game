#include "EndRoom.h"

EndRoom::EndRoom(string nme, int num1, int num2) : Room(nme,num1,num2)
{


}
// overding pure virtual function from the parent class Room
void EndRoom::printRoom(Monk& monk)
{
	string filename = "EndRoom.txt";
	printCurrentRoom(filename);
	monk.getAsString();  // display player stats on the screen 


}
