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
			setType(IDLEWORKER);
		}
		void draw();
		Worker(int x, int y) { setPos(x,y); timeSinceLastMove = 0; speed = 100; pf->initPath(x,y); setID(WORKER_ID); this->setLen(1, 1); setBlocked(); }
		virtual void think();
		virtual void setNewGoal(int goal);
		

};

class RessourceCollector : public Worker{
	enum workingStatus { START, GOING_TO_RESSOURCE, INSIDE_RESSOURCE, WAY_BACK};

	workingStatus currentStatus;	

	RessourceCollector(){
		currentStatus=START;
	}

	virtual void think();	
};

class GoldMiner : public RessourceCollector {};


class IdleWorker : public Worker {};




#endif