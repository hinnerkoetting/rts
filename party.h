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
#include "village.h"


class Party{
	private:
		static int number;
		int id;
		bool computerplayer;
		std::string name;
		std::vector<Village*> villages;

	//first we have two ressources: Gold  and wood
	//int amountOfGold;
	//int amountOfWood; now in the village

	//a Party mainly consists of villages it controls
	public:
		void addVillage(Village*);
		Party() { id = ++number; }
		Village* getVillage(int nr) { if ((unsigned)nr < villages.size()) return villages.at(nr); return 0; }
		int nrVillages() { return villages.size(); }
		void draw();
		static Party* getParty(int nr);
		void calc(); //calculating ressources, units movement...
		void unitMovement();
		
	
	

};


#endif
