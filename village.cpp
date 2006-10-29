#include "village.h"
#include "worker.h"
#include "party.h"
#include "pathfinding.h"
#include "Windows.h"
#include "Util.h"

//Constructor
//initializes member variables to default values
Village::Village(int x, int y){

	//current state
	cur_goldminingUnits=0;
	cur_idleWorkers=0;
	cur_defenders=0;
	cur_attackers=0;
	grownups=0;
	addUnit(15, 13);
	addUnit(15, 9);
	//players wish
	wish_goldminingUnits=0;
	wish_idleWorkers=0;
	wish_defenders=0;
	wish_attackers=0;			
	hq = new HeadQuarter(x, y, this->belongTo);
		
}
void Village::draw() {
	this->hq->draw();
	for (std::vector<Unit*>::iterator i = this->allUnits.begin(); i != allUnits.end(); i++) {
		std::vector<Unit*>::value_type tmp = *i;
		tmp->draw();
	}
}

void Village::calc() {
	for (std::vector<Unit*>::iterator i = this->allUnits.begin(); i != allUnits.end(); i++) {
		std::vector<Unit*>::value_type tmp = *i;
		tmp->move();
		
	}

	//folgender Teil alle 1 Sekunden

	//grownups+=((float)getNrOfIdleUnits())*0.003; //should be in seperate thread
	log::log(".");
	if (grownups>=1){
		//semaphore necessary with thread
		log::log("Wachse");
		grownups-=1;
		createNewIdlePersonAtVillage();
	}

	//current and wish anpassen
}

void Village::addUnit(int x, int y) {
	Worker* w =new Worker(x, y);
	allUnits.push_back(w);
	idleUnits.push_back(w);
}



int Village::getAllUnitsIn(int party, int village) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		return vil->getNrOfAllUnits();
	return -1;
}

int Village::getSoldiersIn(int party, int village) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		return vil->getNrOfSoldiers();
	return -1;
}

int Village::getGoldMinerIn(int party, int village) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		return vil->getNrOfGoldMiner();
	return -1;
}
int Village::getIdleUnitsIn(int party, int village) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		return vil->getNrOfIdleUnits();
	return -1;
}


void Village::incAllUnits(int number) {
	//TODO
}



void Village::incSoldiersIn(int party, int village, int number) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		vil->incSoldiers(number);
}

void Village::incGoldMinerIn(int party, int village, int number) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		vil->incGoldMiner(number);
}

void Village::incUnitsJob(std::vector<Unit*>* u, int number) {
	if (number >= 0) {
		for (int i = 0; i < number; i++) {
			if (this->idleUnits.size() > 0) {
				u->push_back(this->idleUnits.back());
				this->idleUnits.pop_back();
			}
		}
	}
	else {
		for (int i= number; i < 0; i++) {
			if (u->size() > 0) {
				this->idleUnits.push_back(u->back());
				u->pop_back();
			}
		}
	}
}

void Village::incSoldiers(int number) {
	incUnitsJob(&this->soldiers, number);
}

void Village::incGoldMiner(int number) {
	incUnitsJob(&this->goldMiner, number);
}

void Village::incIdleUnits(int number) {
	//TODO
}


Village* Village::getVillage(int party, int village) {
	Party* p = Party::getParty(party);
	if (p != 0) {
		if (village < p->nrVillages()) 
			return p->getVillage(village);
	}
	return 0;
}


void Village::createNewIdlePersonAtVillage(){
	int x=this->hq->getX();
	int y=this->hq->getY();
	findFreePlace(x,y);
	addUnit(x,y);
	

}
