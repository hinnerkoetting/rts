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
	glPushMatrix();
	/*static float len = GraIngame::getLength();
	static float hig = GraIngame::getHeigth();
	glTranslatef((float)this->getExactX()/getPosConst() * len, (float)this->getExactY()/getPosConst() * hig, 0);
	glScalef(len, hig, 1);
	glCallList(UNIT_WORKER_ID);*/
	GraphicInterface::drawGame(UNIT_WORKER_ID, (float)this->getExactX()/getPosConst(), (float)this->getExactY()/getPosConst(), 1, 1);
	glPopMatrix();
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

