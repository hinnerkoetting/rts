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


float length(float x, float y) {
	return sqrt(x*x + y*y);
}

/*
 *
 * move unit
 *
 */
void Unit::move() {
	if (abs(this->getExactX() - (int)(getPosConst() * pf->getNextField()->x)) < posTolerance()  
		&& abs(this->getExactY() - (int)(getPosConst()*pf->getNextField()->y)) < posTolerance()) { // if unit has reached its destination
		if (pf->getPath().size() == 1) {				// unit has no further way
			this->timeSinceLastMove = glutGet(GLUT_ELAPSED_TIME); // so the unit doesnt make a big jump the next time it gets move order
			this->roundPos();  // unit coordinates are rounded so it stands exactly in the mid of the field
			//Ingame::fields[pf->getNextField()->x, pf->getNextField()->y]->setBlocked(this);
			return;
		}
		else { // unit has further way
			this->pf->checkPath(this->getX(), this->getY()); // check next two fields if barriers which existed at beginning of movement do still exist
			std::list<Node*>::value_type actual = *pf->getPath().begin();			
			std::list<Node*>::value_type next= *(++pf->getPath().begin());
			if (actual->x >0 && actual->x < Options::iNumberEdgesX && actual->y >0 && actual->y < Options::iNumberEdgesY) // field does really exist
				if (next->x >0 && next->x < Options::iNumberEdgesX && next->y >0 && next->y < Options::iNumberEdgesY)
					if (!Ingame::fields[next->x][next->y].blocked()) { // if next field is not blocked
						Ingame::fields[actual->x][actual->y].setBlocked(0);  //unblock field where unit just left
						pf->nextField();									// retrieve next field where this unit is supposed to go to
						Ingame::fields[next->x][next->y].setBlocked(this);	// block that field
					}
					else {											// next field is blocked
						if (this->getPath().size() == 2)			// that field is the destination
							this->getPath().pop_front();			// then unit can't move further
						else
							this->goTo(pf->getDesX(), pf->getDesY());			// else look for another path
						//this->move();
						return;
					}
			//i++;

		} }

	int t = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = t - this->timeSinceLastMove;					// time since last movement
	
	float len = length(pf->getNextField()->x*getPosConst() - this->getExactX(),pf->getNextField()->y*getPosConst() - this->getExactY());
	if (len == 0)
		return;
	float normX = (pf->getNextField()->x*getPosConst() - this->getExactX())/len; //normalized vector
	float normY = (pf->getNextField()->y*getPosConst() - this->getExactY())/len;
	this->changePos(normX*this->speed*deltaTime/20000, normY*this->speed*deltaTime/20000);
	timeSinceLastMove = t;
}

/*
 *
 * returns true if unit stands next to target building
 *
 */
bool Unit::nextToBuilding(int buildingID) {
	int x = this->getX();
	int y = this->getY();
	GameObject* g;
	if (y > 0) {
		g = Ingame::fields[x][y-1].blockedBy();
		if (g != 0)
			if (g->getID() == buildingID)
				return true;
		if (x > 0) {
			g = Ingame::fields[x-1][y-1].blockedBy();
			if (g != 0)
				if (g->getID() == buildingID)
					return true;
		}
		if (x < Options::iNumberEdgesX) {
			g = Ingame::fields[x+1][y-1].blockedBy();
			if (g != 0)
				if (g->getID() == buildingID)
					return true;
		}
	}
	if (y < Options::iNumberEdgesY) {
		if (x > 0) {
			g = Ingame::fields[x-1][y+1].blockedBy();
			if (g != 0)
				if (g->getID() == buildingID)
					return true;
		}
		g = Ingame::fields[x][y+1].blockedBy();
		if (g != 0)
			if (g->getID() == buildingID)
				return true;
		if (x > 0) {
			g = Ingame::fields[x+1][y+1].blockedBy();
			if (g != 0)
				if (g->getID() == buildingID)
					return true;
		}
	}
	if (x > 0) {
		GameObject* g = Ingame::fields[x-1][y].blockedBy();
		if (g != 0)
			if (g->getID() == buildingID)
				return true;
	}
	if (x < 0) {
		GameObject* g = Ingame::fields[x+1][y].blockedBy();
		if (g != 0)
			if (g->getID() == buildingID)
				return true;
	}
	return false;
}