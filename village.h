#ifndef VILLAGE_DEF_H
#define VILLAGE_DEF_H

#include <vector>
#include "headquarter.h"
#include "unit.h"
#include "gameressources.h"
class Village{ //vielleicht einiges in die cpp verschieben
	private:	
		int belongTo;
		
		std::vector<Unit*> idleUnits;
		std::vector<Unit*> soldiers;
		std::vector<Unit*> goldMiner;

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

		// unit methods
		void incUnitsJob(std::vector<Unit*>*, int);
	public:
		std::vector<Unit*> allUnits;
		void addUnit(int x, int y);

		//get units
		int getAllUnits() { return allUnits.size(); }
		int getIdleUnits() { return idleUnits.size(); }
		int getSoldiers() { return soldiers.size(); }
		int getGoldMiner() { return goldMiner.size(); }

		//inc units
		void incAllUnits(int number);
		void incIdleUnits(int number);
		void incSoldiers(int number);
		void incGoldMiner(int number);

		//button functions
		static int getAllUnitsIn(int party, int village);
		static int getIdleUnitsIn(int party, int village);
		static int getSoldiersIn(int party, int village);
		static int getGoldMinerIn(int party, int village);
		static void incAllUnitsIn(int party, int village, int number);
		static void incIdleUnitsIn(int party, int village, int number);
		static void incSoldiersIn(int party, int village, int number);
		static void incGoldMinerIn(int party, int village, int number);



		Village(int x, int y);
		~Village() {delete hq; /* TODO: delete all units*/}
		void setBelongTo(int id) { belongTo = id; } //belong to party
		void draw(); // draw all units, buildings etc which belong to this village
		void calc(); // unit movement...
		static Village* getVillage(int party, int village);
	




};

#endif