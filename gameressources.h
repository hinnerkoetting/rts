//includes headers of all ressources

#ifndef RESSOURCES
#define RESSOURCES


#include <stdio.h>
#include "unit.h"
#include "refcnt_ptr.h"
#include <vector>
#include "graphical_entity.h"






class Goldmine: public graph_entry { //erstmal unit, wegen koordinaten und draw, vielleicht nochmal ne gemeinsame oberklasse machen
	
	int amount; //amount of gold still inside
	
public:
	Goldmine(int x, int y){
		setNewPos(x,y);
	};

	int getAmount(){ return amount;};
	void setAmount(int value){ amount=value;};

	void draw();
	


};

class Village{ //vielleicht einiges in die cpp verschieben

		typedef  refcnt_ptr<Unit> sm_unit;	//smart pointer to Unit 
	//Smart Pointer care for destructing of elements. I hope this works
	std::vector <sm_unit> units;

	Goldmine mine;
	//weitere Ressourcen

	int amountOfMoney;
	int amountOfWood;

	int levelOfVillage;
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




};


#endif