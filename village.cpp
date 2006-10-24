#include "village.h"


//Constructor
//initializes member variables to default values
Village::Village(int x, int y){

	//current state
	cur_goldminingUnits=0;
	cur_idleWorkers=0;
	cur_defenders=0;
	cur_attackers=0;

	//players wish
	wish_goldminingUnits=0;
	wish_idleWorkers=0;
	wish_defenders=0;
	wish_attackers=0;			
	hq = new HeadQuarter(x, y, this->belongTo);
		
}
void Village::draw() {
	this->hq->draw();
}