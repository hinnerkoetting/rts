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
		Worker(){
			setType(IDLE_WORKER);
		}
		void draw();
		Worker(int x, int y) { setPos(x,y); timeSinceLastMove = 0; speed = 100; pf->initPath(x,y); setID(WORKER_ID); this->setLen(1, 1); setBlocked(); }
		void think();
		void setNewGoal(int goal);
		

};


class GoldMiner : public Worker {};


class IdleWorker : public Worker {};




#endif