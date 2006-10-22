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
	GraphicInterface::drawObjectGame(getID(), (float)this->getExactX()/getPosConst(), (float)this->getExactY()/getPosConst(), 1, 1);
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

