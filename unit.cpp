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
		pf->findPath(this->getX(), this->getY());
}

/* 
 *
 * sets destination
 *
 */
void Unit::goTo(int x, int y) {
	pf->initPath(this->getX(), this->getY());
	pf->setDestination(x, y);
	
	pf->findPath(this->getX(), this->getX());
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
	if (abs(this->getExactX() - (int)(getPosConst()*pf->getPath()->x)) < posTolerance()  && abs(this->getExactY() - (int)(getPosConst()*pf->getPath()->y)) < posTolerance()) { // if unit has reached its destination
		if (pf->getPath()->next == 0) {				// unit has no further way
			this->timeSinceLastMove = glutGet(GLUT_ELAPSED_TIME); // so the unit doesnt make a big jump the next time it gets move order
			this->roundPos();
			return;
		}
		else {
			pf->nextField();
		}
	}
	
	int t = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = t - this->timeSinceLastMove;
	
	float len = length(getPath()->x*getPosConst() - this->getExactX(),getPath()->y*getPosConst() - this->getExactY());
	if (len == 0)
		return;
	float normX = (getPath()->x*getPosConst() - this->getExactX())/len;
	float normY = (getPath()->y*getPosConst() - this->getExactY())/len;
	this->changePos(normX*this->speed*deltaTime/20000, normY*this->speed*deltaTime/20000);
	timeSinceLastMove = t;
}