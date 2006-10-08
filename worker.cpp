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

/*
 *
 * draw this worker
 *
 */
void Worker::draw() {
	glPushMatrix();
	static float len = GraIngame::getLength();
	static float hig = GraIngame::getHeigth();
	glTranslatef(this->xPos * len, this->yPos * hig, 0);
	glScalef(len, hig, 1);
	glCallList(UNIT_WORKER_ID);
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

