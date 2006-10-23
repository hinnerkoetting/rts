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
#include "ingame.h"
/*
 *
 * create a list of fields describing the path of that unit
 *
 */
void Unit::findPath() {
	//path = Pathfinding::deleteList(path);
	if (pf->getPath().size() == 1)
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
	
	pf->findPath(this->getX(), this->getY());
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
	if (abs(this->getExactX() - (int)(getPosConst() * pf->getNextField()->x)) < posTolerance()  && abs(this->getExactY() - (int)(getPosConst()*pf->getNextField()->y)) < posTolerance()) { // if unit has reached its destination
		if (pf->getPath().size() == 1) {				// unit has no further way
			this->timeSinceLastMove = glutGet(GLUT_ELAPSED_TIME); // so the unit doesnt make a big jump the next time it gets move order
			this->roundPos();
			Ingame::fields[pf->getNextField()->x, pf->getNextField()->y]->setBlocked(this);
			return;
		}
		else {
			std::list<Node*>::value_type actual = *pf->getPath().begin();			
			std::list<Node*>::value_type next= *(++pf->getPath().begin());
			if (!Ingame::fields[next->x][next->y].blocked()) {
				Ingame::fields[actual->x][actual->y].setBlocked(0);
				pf->nextField();
				Ingame::fields[next->x][next->y].setBlocked(this);
			}
			else {
				this->goTo(pf->desX, pf->desY);
				return;
			}
		}
	}
	
	int t = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = t - this->timeSinceLastMove;
	
	float len = length(pf->getNextField()->x*getPosConst() - this->getExactX(),pf->getNextField()->y*getPosConst() - this->getExactY());
	if (len == 0)
		return;
	float normX = (pf->getNextField()->x*getPosConst() - this->getExactX())/len; //normalized vector
	float normY = (pf->getNextField()->y*getPosConst() - this->getExactY())/len;
	this->changePos(normX*this->speed*deltaTime/20000, normY*this->speed*deltaTime/20000);
	timeSinceLastMove = t;
}