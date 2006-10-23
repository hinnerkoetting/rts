#include "gameressources.h"
#include "gl/glut.h"
#include "graphic_interface.h"
#include "pathfinding.h"
#include "Util.h"
#include "defines.h"


void Goldmine::draw() {
	GraphicInterface::drawObjectGame(GOLDMINE_ID, this->getX(), this->getY(), lenX, lenY);
}
