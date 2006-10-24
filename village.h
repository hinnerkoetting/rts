#ifndef VILLAGE_DEF_H
#define VILLAGE_DEF_H

#include <vector>
#include "headquarter.h"
#include "unit.h"
#include "gameressources.h"
class Village{ //vielleicht einiges in die cpp verschieben
	int belongTo;
	std::vector <Unit*> units;

	//Goldmine* mine;
	//weitere Ressourcen

	int amountOfMoney;
	int amountOfWood;

	int levelOfVillage;

	//buildings
	HeadQuarter* hq;
	//Research Goal, and state
	//Researched done

	int totalUnits;

	

	//current state
	int cur_goldminingUnits;
	int cur_idleWorkers;
	int cur_defenders;
	int cur_attackers;

	//players wish
	int wish_goldminingUnits;
	int wish_idleWorkers;
	int wish_defenders;
	int wish_attackers;

	void orderIdleToGoldMiner();
	void orderIdleToDefender();
	void orderIdleToAttacker();
	void orderGoldMinerToIdle();
	void orderDefenderToIdle();
	void orderAttackerToIdle();
	
	void moveAttackersToOtherVillage(Village goal);
	public:
		Village(int x, int y) { hq = new HeadQuarter(x, y, this->belongTo);}
		//~Village() {delete hq; }
		void setBelongTo(int id) { belongTo = id; }
		void draw();
	




};

#endif