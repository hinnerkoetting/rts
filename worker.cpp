/////////////////////////////////////////////////////////////////
//
//					
//					worker.coo
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "worker.h"
#include "gl/glut.h"
#include "gra_ingame.h"
#include "pathfinding.h"
#include "Util.h"
#include "graphic_interface.h"

/*
 *
 * draw this worker
 *
 */

void Worker::draw() {
	GraphicInterface::drawObjectGame(getID(), (float)this->getExactX()/getPosConst(), (float)this->getExactY()/getPosConst(), lenX, lenY);
}

void Worker::think(){
	//TODO
	log::log("worker thinks");
	return;

}



void Worker::setNewGoal(int gola){
	//TODO
	log::log("worker should get new goal. TODO");
	return;

}

void RessourceCollector::think(){
	log::log("Ressource Collector thinks\n");

	switch(currentStatus){
		case START :	log::log("Start");

				break;

		default: log::log("Error...default status reached");

	};
};