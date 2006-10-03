//represent a party in the game.
//Parties can be human or computer controlled
//Every unit on the board owns to a party
//Animals and other neutral units belong to the neutral party.



#ifndef PARTY
#define PARTY

#include <string>
class party{
	bool computerplayer;
	string name;
	Unit units[];

}


#endif
