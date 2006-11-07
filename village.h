//==========================================00
//represents a village in the game
//central element in the world
//all units belongs to a village
//all resources to
//=====================================

#ifndef VILLAGE_DEF_H
#define VILLAGE_DEF_H

#include <vector>
#include <string>
#include <map>

#include "headquarter.h"
#include "unit.h"
#include "gameressources.h"
#include "menue.h"

#include "button_display.h"
#include "button_change.h"
#include "game_object.h"



using namespace std;

class Village: public ButtonValueReader, public ButtonValueChangerHandler { 
	private:	

		//player
		int belongTo;
		//originally i used an individual enumeration for displayable object, for changeable object and
		//for ressources...
		//now i used unified list. Advantage is, that ressources are also displayable...so there is a lot of overlapping
		//the disadvantage is, that you could store wrong game_objects in this maps. 
		std::map<GameObject::gameObject_ID, int> worker_ForRessources;
		

		typedef std::vector<Unit*> Units;
		//Units
		Units midleUnits;
		Units msoldiers;
//		Units goldMiner;//raus

		//connects village to ressources
		typedef map<GameObject::gameObject_ID,Ressource*> VillageRessources;
		VillageRessources mVillageRessources;
		map<GameObject::gameObject_ID,int> mcollectedRessources;
		map<GameObject::gameObject_ID,int> mwishedNumberOfWorkersForJob;
		map<GameObject::gameObject_ID,Units> mcurrentworkersforJob;




		HeadQuarter* hq;
		//Research Goal, and state
		//Researched done

		//int totalUnits;

				

		
////////////////////////////////////////////


		float grownups;  //new population

		int wish_defenders;
		int wish_soldiers;

		//GUI
		Menu villageMenu;

		int levelOfVillage;
	

		void midTermThink();
	int lastTimeForThinking;
	

		void initMenu();

		//brauchen wir die alle noch?
		//void orderIdleToGoldMiner();
		//void orderIdleToDefender();
		//void orderIdleToAttacker();
		//void orderGoldMinerToIdle();
		//void orderDefenderToIdle();
		//void orderAttackerToIdle();
		void createNewIdlePersonAtVillage();
		
		void moveAttackersToOtherVillage(Village goal);

		// unit methods
		void incUnitsJob(std::vector<Unit*>*, int);



	public:
		Village();
		std::vector<Unit*> allUnits;//wieso public?
		void addUnit(int x, int y);

		//get units
		int getNrOfAllUnits() { return allUnits.size(); }
		int getNrOfIdleUnits() { return midleUnits.size(); }
		int getNrOfWishedSoldiers() { return wish_soldiers; }
		//int getNrOfWishedGoldMiner() { return wish_goldminingUnits; }

		int getNrOfCurrentWorker(GameObject::gameObject_ID ressource);

		int getNumberOfWishedWorker(GameObject::gameObject_ID ressource);

		int getNrOfCurrentSoldiers() { return msoldiers.size(); }
		//int getNrOfCurrentGoldMiner() { return goldMiner.size(); }


		//inc units
	//	void incAllUnits(int number);
		void incIdleUnits(int number);
		void incSoldiers(int number);
		//void incGoldMiner(int number);



		void incWishSoldiers(int number) {if (wish_soldiers+number >= 0)
			wish_soldiers+=number; }
		//void incWishGoldMiner(int number) {if (wish_goldminingUnits+number >= 0 )
		//									wish_goldminingUnits+=number;}


		//button functions
		//int getNumberOfCurrentWorkers(string ressourcename);
		//int getNumberOfWishedWorkers(string ressourcename);
		//void changeNrOfWorkers(GameObject::gameObject_ID worker_type, int change);
		int getDisplayButtonValue(GameObject::gameObject_ID);
	
		virtual int getCurrentValue(GameObject::gameObject_ID);
		virtual int getWishedValue(GameObject::gameObject_ID);
		virtual void changeValue(GameObject::gameObject_ID, int change);
		


		//static int getAllUnitsIn(int party, int village);
		//static int getIdleUnitsIn(int party, int village);
		//static int getWishedSoldiersIn(int party, int village);
		//static int getWishedGoldMinerIn(int party, int village);
		//static void incAllUnitsIn(int party, int village, int number);
		//static void incIdleUnitsIn(int party, int village, int number);
		//static void incSoldiersIn(int party, int village, int number);
		//static void incGoldMinerIn(int party, int village, int number);

		//static int getCurrentSoldiersIn(int party, int village);
		//static int getCurrentGoldMinerIn(int party, int village);
		


		Village(int x, int y);
		~Village() {delete hq; /* TODO: delete all units*/}
		void setBelongTo(int id) { belongTo = id; } //belong to party
		void draw(); // draw all units, buildings etc which belong to this village
		void calc(); // unit movement...
		static Village* getVillage(int party, int village);

		void setGoldMine(Goldmine* goldmine){
			this->mVillageRessources[GameObject::GOLDMINER]=goldmine;
		}
	




};

#endif