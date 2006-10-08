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

class Worker : public Unit {
	public: 
		void draw();
		Worker(int x, int y) { setPos(x,y); timeSinceLastMove = 0; speed = 100; pf->initPath(x,y); }
		void think();
		void setNewGoal(int goal);

};
#endif