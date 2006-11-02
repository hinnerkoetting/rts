#ifndef VILLAGE_DEF_H
#define VILLAGE_DEF_H

#include <vector>
#include "headquarter.h"
#include "unit.h"
#include "gameressources.h"
class Village{ //vielleicht einiges in die cpp verschieben
	private:	
		int belongTo;

		int lastTimeForThinking;
		
		std::vector<Unit*> idleUnits;
		std::vector<Unit*> soldiers;
		std::vector<Unit*> goldMiner;

		Goldmine* gmine;
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

		float grownups;  //new population

		//players wish  
		int wish_goldminingUnits;
		int wish_idleWorkers;
		int wish_defenders;
		int wish_soldiers;

		void midTermThink();

		void orderIdleToGoldMiner();
		void orderIdleToDefender();
		void orderIdleToAttacker();
		void orderGoldMinerToIdle();
		void orderDefenderToIdle();
		void orderAttackerToIdle();
		void createNewIdlePersonAtVillage();
		
		void moveAttackersToOtherVillage(Village goal);

		// unit methods
		void incUnitsJob(std::vector<Unit*>*, int);
	public:
		std::vector<Unit*> allUnits;
		void addUnit(int x, int y);

		//get units
		int getNrOfAllUnits() { return allUnits.size(); }
		int getNrOfIdleUnits() { return idleUnits.size(); }
		int getNrOfWishedSoldiers() { return wish_soldiers; }
		int getNrOfWishedGoldMiner() { return wish_goldminingUnits; }

		int getNrOfCurrentSoldiers() { return soldiers.size(); }
		int getNrOfCurrentGoldMiner() { return goldMiner.size(); }

		static void changeValueOfWishedGoldMiner(int party, int village, int number) { 
			Village* vil = getVillage(party, village);
			if (vil != 0){
				vil->incWishGoldMiner(number);
			};
		};

		static void changeValueOfWishedSoldiers (int party, int village, int number) { 
			Village* vil = getVillage(party, village);
			if (vil != 0){
				vil->incWishSoldiers(number);
			};
		};

		//inc units
		void incAllUnits(int number);
		void incIdleUnits(int number);
		void incSoldiers(int number);
		void incGoldMiner(int number);


		void incWishSoldiers(int number) {if (wish_soldiers+number >= 0)
			wish_soldiers+=number; }
		void incWishGoldMiner(int number) {if (wish_goldminingUnits+number >= 0 )
											wish_goldminingUnits+=number;}


		//button functions
		static int getAllUnitsIn(int party, int village);
		static int getIdleUnitsIn(int party, int village);
		static int getWishedSoldiersIn(int party, int village);
		static int getWishedGoldMinerIn(int party, int village);
		static void incAllUnitsIn(int party, int village, int number);
		static void incIdleUnitsIn(int party, int village, int number);
		static void incSoldiersIn(int party, int village, int number);
		static void incGoldMinerIn(int party, int village, int number);

		static int getCurrentSoldiersIn(int party, int village);
		static int getCurrentGoldMinerIn(int party, int village);
		


		Village(int x, int y);
		~Village() {delete hq; /* TODO: delete all units*/}
		void setBelongTo(int id) { belongTo = id; } //belong to party
		void draw(); // draw all units, buildings etc which belong to this village
		void calc(); // unit movement...
		static Village* getVillage(int party, int village);

		void setGoldMine(Goldmine* goldmine){
			this->gmine=goldmine;
		}
	




};

#endif