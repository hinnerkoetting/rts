/////////////////////////////////////////////////////////////////
//
//					
//					gra_ingame.cpp
//					graphical functions ingame
//					
//
/////////////////////////////////////////////////////////////////

#include <math.h>
#include "gl/glut.h"
#include "gra_ingame.h"
#include "ingame.h"
#include "options.h"
#include "gl/glut.h"
#include "graphic.h"
#include "errors.h"
#include "field.h"
#include "unit.h"
#include "hero.h"
#include "mymath.h"
#include "party.h"


float GraIngame::xPos = 0.0f;
float GraIngame::yPos = 0.0f;
float GraIngame::fieldHeigth = 0.05f;
float GraIngame::fieldLength = 0.05f;
int GraIngame::mouseX = 0;
int GraIngame::mouseY = 0;
float GraIngame::menuX = 0.25f;
	
void GraIngame::init() {
	loadImages();
	createDL();
}

void GraIngame::drawFields() {



	int x = 0;
	bool vX = false; // visible x
	bool vY = false;
	bool leaveX = false;
	bool leaveY = false;
	while (x < Options::iNumberEdgesX != 0 && !leaveX) {
		int y = 0;
		glTranslatef(getLength(), 0,0);
		if (Graphic::visible(Point(x * getLength(), getY() ))) { // better performance
			vX = true;
			while (y < Options::iNumberEdgesY && !leaveY) {
				glTranslatef(0, getHeigth(), 0);
				leaveY = false;
				vY = false;
				if (Graphic::visible(Point(x * getLength(), y * getHeigth(), 0))) { // better performance
					vY = true;
					if (Ingame::fields[x][y].lt->getHeigth() == 0 || Ingame::fields[x][y].rt->getHeigth() == 0 ||
						Ingame::fields[x][y].rb->getHeigth() == 0 || Ingame::fields[x][y].lb->getHeigth() == 0) // if a part of water field
						glCallList(FIELD_WATER);
					else 
						glCallList(FIELD_BEHINDGRAD);						// draw green field behind gradient
					glCallList(Ingame::fields[x][y].type);				// draw field
				}
				else if (vY)		//  better performance
					leaveY = true;
				
				y++;
			}
		}
		else if (vX)  // there have been visible fields left from this, this is invisible so no need to check the rest: better performance
			leaveX = true; 
		glTranslatef(0, -getHeigth() *y, 0);
		x++;
	}
	glTranslatef(-getLength()*x,0,0);
	
}


/*
 *
 * sets cameraposiotion and view
 *
 */
void GraIngame::setCamera() {
	glLoadIdentity();
	gluLookAt(getX(), getY() , getZ(), 
			getX(),getY(),-1.0f, 
			0.0f,1.0f ,0.0f);
}


/*
 *
 * draws the mousecursor
 *
 */
void GraIngame::drawCursor() {
	float x = Graphic::rasterPos(true);
	float y = Graphic::rasterPos(false);
	Graphic::drawPixel(Point(x, y, 0.0f, 1.0f), 5.0f);
}

/* 
 *
 * draw partys
 *
 */
void GraIngame::drawPartys() {
	for (std::vector<Party>::iterator i = Ingame::partys.begin(); i != Ingame::partys.end(); i++) {
		std::vector<Party>::value_type tmp = *i;
		tmp.draw();
	}
}
/*
 *
 * moves map
 * *REWORK*: not move further then map
 */
void GraIngame::move(float x, float y) {
	if (xPos + x * GraIngame::getZ()/20  > 0)// && xPos + x * GraIngame::getZ()/20 < Options::iNumberEdgesX * GraIngame::getLength() )
		xPos += x * GraIngame::getZ() / 20;
	if (yPos + y* GraIngame::getZ()/20 > 0)// && yPos + x * GraIngame::getZ()/20 < Options::iNumberEdgesY * GraIngame::getHeigth() )
		yPos += y* GraIngame::getZ() / 20;
}


/*
 *
 * find out which edge is clicked
 * bX == tur  -> x edge
 */
int GraIngame::whichClicked(bool bX) {
	if (bX) {
		return MyMath::round(Graphic::rasterPos(true) / GraIngame::getLength());
	}
	return MyMath::round(Graphic::rasterPos(false) / GraIngame::getHeigth());
}

float GraIngame::menuWidth() {
	return GraIngame::getMenuWidth();
}