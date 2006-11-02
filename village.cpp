#include "village.h"
#include "worker.h"
#include "party.h"
#include "pathfinding.h"
#include "Windows.h"
#include "Util.h"
#include "button_display.h"
#include "button_change.h"
#include "exception.h"
#include <string>

using namespace std;
//Constructor
//initializes member variables to default values
Village::Village(int x, int y){

	//current state
	//cur_goldminingUnits=0;
	//cur_idleWorkers=0;
	//cur_defenders=0;
	//cur_attackers=0;
	lastTimeForThinking=0;
	grownups=0;
	addUnit(15, 13);
	addUnit(15, 9);
	//players wish
	wish_goldminingUnits=0;
	wish_idleWorkers=0;
	wish_defenders=0;
	wish_soldiers=0;			
	hq = new HeadQuarter(x, y, this->belongTo);
	initMenu();
		
}
void Village::draw() {
	this->hq->draw();
	for (std::vector<Unit*>::iterator i = this->allUnits.begin(); i != allUnits.end(); i++) {
		std::vector<Unit*>::value_type tmp = *i;
		tmp->draw();
	}
	gmine->draw();
}


/**
	executed every second
	growing of new persons
	decision about moving person to a new category
	*/

void Village::midTermThink(){
	grownups+=((float)getNrOfIdleUnits())*0.05; //should be in seperate thread
		log::log(".");
		if (grownups>=1){			
			log::log("Wachse");
			grownups-=1;
			createNewIdlePersonAtVillage();
		}

	//adopt current numbers of workers with wished numbers
		if (wish_goldminingUnits>getNrOfCurrentGoldMiner()){
			if (getNrOfIdleUnits()>0){
				Worker* changingWorker=static_cast<Worker*>(idleUnits.front());

				idleUnits.erase(idleUnits.begin());

				(*changingWorker).setType(GOLDMINER);
				goldMiner.push_back(changingWorker);
				//cur_goldminingUnits=goldMiner.size();
				
			}
		}
		//all units of the village may now think about the next step to do
for (std::vector<Unit*>::iterator i = this->allUnits.begin(); i != allUnits.end(); i++) {
		std::vector<Unit*>::value_type tmp = *i;
		tmp->think();
	}
}



void Village::calc() {
	for (std::vector<Unit*>::iterator i = this->allUnits.begin(); i != allUnits.end(); i++) {
		std::vector<Unit*>::value_type tmp = *i;
		tmp->move();
		
	}


	int time=glutGet(GLUT_ELAPSED_TIME);
	if ((time-lastTimeForThinking)>1000){
		lastTimeForThinking=time;
		//folgender Teil alle 1 Sekunden
		midTermThink();
		
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

int Village::getWishedSoldiersIn(int party, int village) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		return vil->getNrOfWishedSoldiers();
	return -1;
}

int Village::getCurrentSoldiersIn(int party, int village) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		return vil->getNrOfCurrentSoldiers();
	return -1;
}


int Village::getWishedGoldMinerIn(int party, int village) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		return vil->getNrOfWishedGoldMiner();
	return -1;
}


int Village::getCurrentGoldMinerIn(int party, int village) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		return vil->getNrOfCurrentGoldMiner();
	return -1;
}


int Village::getIdleUnitsIn(int party, int village) {
	Village* vil = getVillage(party, village);
	if (vil != 0)
		return vil->getNrOfIdleUnits();
	return -1;
}


/*void Village::incAllUnits(int number) {
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
*/
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


/*
 * each village has a individual menue
 * if the it's selected, on the left side the individual menue is presented
 * this method initialised the menue
 */
void Village::initMenu(){
	//temporary standard menue
	//maybe later individual menues

	MenuList menue;
	MenuButton* m1;
	m1 = new ButtonDisplay	(0		, 0.05	, 0.1, 0.15, 0.02, 0.08, BUTTON_UNIT_ID		, this, display::TOTAL_UNITS);
	
	menue.push_back(m1);

	m1 = new ButtonDisplay	(0		, 0.05	, 0.2, 0.25, 0.02, 0.08, BUTTON_HOUSE_ID	, this, display::IDLEWORKER);
 	menue.push_back(m1);

	m1 = new ButtonChangeValue (0.05	, 0.1	, 0.2, 0.25, 0.02, 0.08, BUTTON_ATTACK_ID	, this, display::SOLDIER);
	
	menue.push_back(m1);
	
	m1 = new ButtonChangeValue (0.1	, 0.15	, 0.2, 0.25, 0.02, 0.08, BUTTON_GOLDMINE_ID	, this, display::GOLDMINER);
	menue.push_back(m1);
	
	Menu::setMenuList(menue);
}


int Village::getNumberOfCurrentWorkers(string ressourcename){
	//noch Umstellung auf Map
	return goldMiner.size();
	
};


int Village::getNumberOfWishedWorkers(string ressourcename){
	//noch Umstellung auf Map
	return wish_goldminingUnits;
	
};


void Village::changeNrOfWorkers(string ressourcename, int change){
	//noch Umstellung auf Map
	if (ressourcename=="Gold"){
		wish_goldminingUnits+=change;
	}
	else {

		throw new GeneralGameException("Ressource derzeit nicht definiert");
	}

};


int Village::getDisplayButtonValue(display::display_ID display_Item){
	switch(display_Item)
	{
		case display::IDLEWORKER:
			return getNrOfIdleUnits();
		case display::TOTAL_UNITS:
			return getNrOfAllUnits();
		default: throw GeneralGameException("Display type not implemented yet");
	};
}


		

int Village::getCurrentValue(display::change_ID ch_id){ 
	switch (ch_id){
		case display::SOLDIER:
			return getNrOfCurrentSoldiers();
		case display::GOLDMINER:
			return getNrOfCurrentGoldMiner();
		default: 
			throw GeneralGameException("Display type not implemented yet");
	};
};

int Village::getWishedValue(display::change_ID ch_id){
switch (ch_id){
		case display::SOLDIER:
			return getNrOfWishedSoldiers();
		case display::GOLDMINER:
			return getNrOfWishedGoldMiner();
		default: 
			throw GeneralGameException("Display type not implemented yet");	
	};
};

void Village::changeValue(display::change_ID ch_id, int change){
	switch (ch_id){
		case display::SOLDIER:
			wish_soldiers+=change;
			return;			
		case display::GOLDMINER:
			wish_goldminingUnits+=change;
			return;
		default: 
			throw GeneralGameException("Display type not implemented yet");	

	};

};