/////////////////////////////////////////////////////////////////
//
//					
//					unit.cpp
//					class unit
//					
//
/////////////////////////////////////////////////////////////////

#include "pathfinding.h"
#include "unit.h"
#include "gl/glut.h"
#include "errors.h"
#include "math.h"
/*
 *
 * create a list of fields describing the path of that unit
 *
 */
void Unit::findPath() {
	//path = Pathfinding::deleteList(path);
	if (pf->getPath()->next == 0)
		pf->findPath(this->xPos, this->xPos);
}

/* 
 *
 * sets destination
 *
 */
void Unit::goTo(float x, float y) {
	pf->setDestination(x, y);
	pf->findPath(this->xPos, this->yPos);
}

/*
 *
 * move unit
 *
 */
float length(float x, float y) {
	return sqrt(x*x + y*y);
}

void Unit::move() {
	if (abs(this->xPos - pf->getPath()->x) < 0.05  && abs(this->yPos - pf->getPath()->y) < 0.05) { // if unit has reached its destination
		if (pf->getPath()->next == 0) {				// unit has no further way
			this->timeSinceLastMove = glutGet(GLUT_ELAPSED_TIME); // so the unit doesnt make a big jump the next time it gets move order
			return;
		}
		else {
			pf->nextField();
		}
	}
	
	int t = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = t - this->timeSinceLastMove;
	
	float len = length(getPath()->x - this->xPos,getPath()->y - this->yPos);
	if (len == 0)
		return;
	float normX = (getPath()->x - this->xPos)/len;
	float normY = (getPath()->y - this->yPos)/len;
	this->xPos += normX*this->speed*deltaTime/20000;
	this->yPos += normY*this->speed*deltaTime/20000;
	timeSinceLastMove = t;
}