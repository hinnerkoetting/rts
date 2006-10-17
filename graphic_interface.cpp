/////////////////////////////////////////////////////////////////
//
//					
//					graphic_interface.cpp
//					interface to graphic functions
//					
//
/////////////////////////////////////////////////////////////////

#include "gl/glut.h"
#include "graphic_interface.h"
#include "gra_ingame.h"
#include "graphic.h"

void GraphicInterface::drawGame(int dlIndex, float x, float y, float lenX, float lenY) {
	glPushMatrix();
		float len = GraIngame::getLength();
		float hig = GraIngame::getHeigth();
		glTranslatef(x * len, y * hig, 0);
		glScalef(lenX * len, lenY * hig, 0);
		glCallList(dlIndex);
	glPopMatrix();
}

void GraphicInterface::drawMenu(int dlIndex, float x, float y, float lenX, float lenY) {
	glPushMatrix();

		glTranslatef(x , y , 0);
		glScalef(lenX , lenY, 0);
		glCallList(dlIndex);
	glPopMatrix();
}


void GraphicInterface::initGame() {
	GraIngame::init();
}

void GraphicInterface::initGraphics(int argc, char **argv) {
	Graphic::init(argc, argv);
}

