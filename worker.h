/////////////////////////////////////////////////////////////////
//
//					
//					worker.h
//					
//					
//
/////////////////////////////////////////////////////////////////

#ifndef WORKER_H_DEF
#define WORKER_H_DEF
#include "unit.h"
#include "defines.h"

class Worker : public Unit {
	private:

	public: 
		void draw();
		Worker(int x, int y) { setPos(x,y); timeSinceLastMove = 0; speed = 100; pf->initPath(x,y); setID(UNIT_WORKER_ID);}
		void think();
		void setNewGoal(int goal);

};
#endif