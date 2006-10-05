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
void Unit::createPath(float desX, float desY) {
	Pathfinding::deleteList(path);
	path = Pathfinding::findPath(this->getX(), this->getY(), desX, desY);
}

void Unit::goTo(float x, float y) {
	createPath(x, y);
}
/*
 *
 * set path that unit needs to go to current position
 *
 */
void Unit::initPath() {
	path = new Node(this->getX(),this->getY(), 0,0);
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
	if (abs(this->xPos - path->x) < 0.05  && abs(this->yPos - path->y) < 0.05) { // if unit has reached its destination and has further way
		if (path->next == 0) {
			return;
		}
		this->timeSinceLastMove = glutGet(GLUT_ELAPSED_TIME);	// pathfinding takes some time, else the unit would make a big jump after creating a path
		Node* tmp = path;
		path = path->next;
		delete(tmp);		
	}

	int t = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = t - this->timeSinceLastMove;
	double len = length(path->x - this->xPos,path->y - this->yPos);
	double normX = (path->x - this->xPos)/len;
	double normY = (path->y - this->yPos)/len;
	this->xPos += normX*this->speed*deltaTime/50000;
	this->yPos += normY*this->speed*deltaTime/50000;
	timeSinceLastMove = t;
}