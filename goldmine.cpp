#include "gameressources.h"
#include "gl/glut.h"
#include "gra_ingame.h"
#include "pathfinding.h"
#include "Util.h"
#include "defines.h"


void Goldmine::draw() {
	glPushMatrix();
	static float len = GraIngame::getLength();
	static float hig = GraIngame::getHeigth();
	glTranslatef((float)this->getXPos() * len, (float)this->getYPos() * hig, 0);
	glScalef(len, hig, 1);
	glCallList(UNIT_WORKER_ID);
	glPopMatrix();
}
