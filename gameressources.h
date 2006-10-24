//includes headers of all ressources

#ifndef RESSOURCES
#define RESSOURCES


#include <stdio.h>
#include "unit.h"
#include "refcnt_ptr.h"
#include <vector>
//#include "graphical_entity.h"






class Goldmine: public GameObject { //erstmal unit, wegen koordinaten und draw, vielleicht nochmal ne gemeinsame oberklasse machen
	
	int amount; //amount of gold still inside
	
public:
	Goldmine(int x, int y){
		setPos(x,y);
		setLen(2, 2);
	};
	Goldmine() { setLen(2, 2);}

	int getAmount(){ return amount;};
	void setAmount(int value){ amount=value;};

	void draw();
	


};




#endif