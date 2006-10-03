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
/*
 *
 * create a list of fields describing the path of that unit
 *
 */
void Unit::createPath(float desX, float desY) {
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
void Unit::move() {
	int t = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = t - this->timeSinceLastMove;
	this->xPos += (path->x - this->xPos)*this->speed*deltaTime;
	this->yPos += (path->y - this->yPos)*this->speed*deltaTime;
	timeSinceLastMove = t;
}