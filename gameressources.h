//includes headers of all ressources


#ifndef RESSOURCES
#define RESSOURCES


#include <stdio.h>
#include "unit.h"
#include "refcnt_ptr.h"
#include <vector>
//#include "graphical_entity.h"


//namespace ressources{
	
//};

//Ressource Zwischenklasse
 class Ressource abstract: public GameObject{

	
	
 protected:
		int amount; //amount of ressource still inside

		std::vector<Unit*> workersInsideRessource;

		void dismissUnit();
 public: 		


	 void thinkAboutDismiss(){
	
	 };
		int getAmount(){ return amount;};
		void setAmount(int value){
			amount=value;
		};


};



//diese hat think Methode
// in der Ressource werden Einheiten gespeichert, die momentan (unsichtbar) in dieser Ressource arbeiten
//Einheiten haben die Zeit gespeichert, wann sie reinkommen)
//Ressourcen prüfen alle 1/2 sekunde nach, ob Einheit schon 3 Sekunden drin waren
//Worker hat 3 Stati: Auf dem Weg zur Ressoure, In der Ressource, Auf dem Weg zum HQ


class Goldmine: public Ressource { //erstmal unit, wegen koordinaten und draw, vielleicht nochmal ne gemeinsame oberklasse machen
	

	
public:
	Goldmine(int x, int y){
		setPos(x,y);
		setLen(2, 2);
	};
	Goldmine() { setLen(2, 2);}

	
	void draw();
	


};




#endif