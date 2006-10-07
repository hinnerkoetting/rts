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
		Worker(float x, float y) { xPos = x; yPos = y; timeSinceLastMove = 0; speed = 100; pf->initPath(x,y); }
		void think();
		void setNewGoal(int goal);

};
#endif