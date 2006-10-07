//represent a party in the game.
//Parties can be human or computer controlled
//Every unit on the board owns to a party
//Animals and other neutral units belong to the neutral party.



#ifndef PARTY
#define PARTY

#include <stdio.h>
#include "unit.h"
#include "refcnt_ptr.h"

#include <vector>

class party{

	
	bool computerplayer;
	std::string name;
	

	//first we have two ressources: Gold  and wood
	int amountOfGold;
	int amountOfWood;


		typedef  refcnt_ptr<Unit> sm_unit;	//smart pointer to Unit 
	//Smart Pointer care for destructing of elements. I hope this works
	std::vector <sm_unit> units;


};


#endif
