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
#include "options.h"
#include "point.h"

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

void GraphicInterface::drawLineStrip(float x1, float x2, float y1, float y2, float r, float g, float b) {
	Graphic::drawLineStrip( Point(x1 *Options::ResolutionX/GraIngame::getMenuWidth(), y1*Options::ResolutionY, 0.0f, r, g,b),
							Point(x2 *Options::ResolutionX/GraIngame::getMenuWidth(), y1*Options::ResolutionY, 0.0f, r, g,b),
							Point(x2 *Options::ResolutionX/GraIngame::getMenuWidth(), y2*Options::ResolutionY, 0.0f, r, g,b), 
							Point(x1 *Options::ResolutionX/GraIngame::getMenuWidth(), y2*Options::ResolutionY, 0.0f, r, g,b));
}
void GraphicInterface::initGraphics(int argc, char **argv) {
	Graphic::init(argc, argv);
}

