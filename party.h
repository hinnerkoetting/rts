//represent a Party in the game.
//Parties can be human or computer controlled
//Every unit on the board owns to a Party
//Animals and other neutral units belong to the neutral Party.



#ifndef PARTY
#define PARTY

#include <stdio.h>
#include <vector>
#include "unit.h"
#include "refcnt_ptr.h"
#include "gameressources.h"



class Party{

	
	bool computerplayer;
	std::string name;
	

	//first we have two ressources: Gold  and wood
	//int amountOfGold;
	//int amountOfWood; now in the village

	//a Party mainly consists of villages it controls
	std::vector<Village> villages;

	


		typedef  refcnt_ptr<Unit> sm_unit;	//smart pointer to Unit 
	//Smart Pointer care for destructing of elements. I hope this works
	std::vector <sm_unit> units;

};


#endif
