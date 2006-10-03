/////////////////////////////////////////////////////////////////
//
//					
//					gra_ingame.cpp
//					graphical functions ingame
//					
//
/////////////////////////////////////////////////////////////////

#include <math.h>
#include "gra_ingame.h"
#include "map.h"
#include "ingame.h"
#include "options.h"
#include "graphic.h"
#include "gra_string.h"
#include "map.h"
#include "errors.h"
#include "gl/glut.h"
#include "field.h"
#include "unit.h"
#include "hero.h"

float GraIngame::xPos = 0.0f;
float GraIngame::yPos = 0.0f;
float GraIngame::fieldHeigth = 0.05f;
float GraIngame::fieldLength = 0.05f;
int GraIngame::mouseX = 0;
int GraIngame::mouseY = 0;
float GraIngame::menuX = 0.25f;
	
void GraIngame::drawUnits() {
	Unit* unit = Ingame::Heroes;
	while (unit != 0) {
		unit->draw();
		unit = unit->next;
	}
	unit = Ingame::Workers;
	while (unit != 0) {
		unit->draw();
		unit = unit->next;
	}
}

void GraIngame::drawFields() {
	

	Field* lpX = Ingame::firstField;
	Field* lpY;
	int x = 0;
	bool vX = false; // visible x
	bool vY = false;
	bool leaveX = false;
	bool leaveY = false;
	while (lpX != 0 && !leaveX) {
		int y = 0;
		lpY = lpX;
		if (Graphic::visible(Point(x * getLength(), getY() ))) { // better performance
			vX = true;
			while (lpY != 0 && !leaveY) {
				leaveY = false;
				vY = false;
				if (Graphic::visible(Point(x * getLength(), y * getHeigth(), 0))) { // better performance
					vY = true;
					if (lpY->lt->getHeigth() == 0 || lpY->rt->getHeigth() == 0 ||
						lpY->rb->getHeigth() == 0 || lpY->lb->getHeigth() == 0) // if a part of water field
						glCallList(1);
					else 
						glCallList(17);						// draw green field behind gradient
					glCallList(lpY->type);				// draw field
				}
				else if (vY)		//  better performance
					leaveY = true;
				glTranslatef(0, getHeigth(), 0);
				y++;
				lpY = lpY->top;
			}
		}
		else if (vX)  // there have been visible fields left from this, this is invisible so no need to check the rest: better performance
			leaveX = true; 
		glTranslatef(getLength(), -getHeigth() *y, 0);
		x++;
		lpX = lpX->rigth;
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
 * moves map
 * *REWORK*: not move further then map
 */
void GraIngame::move(float x, float y) {
	if (xPos + x * GraIngame::getZ()/20  > 0)// && xPos + x * GraIngame::getZ()/20 < Options::iNumberEdgesX * GraIngame::getLength() )
		xPos += x * GraIngame::getZ() / 20;
	if (yPos + y* GraIngame::getZ()/20 > 0)// && yPos + x * GraIngame::getZ()/20 < Options::iNumberEdgesY * GraIngame::getHeigth() )
		yPos += y* GraIngame::getZ() / 20;
}



int round(float x)  {
	if (x - (int)x >= 0.5)
		x = (int)x + 1;
	else x = (int)x;
	return x;
}
/*
 *
 * find out which edge is clicked
 * bX == tur  -> x edge
 */
int GraIngame::whichClicked(bool bX) {
	if (bX) {
		return round(Graphic::rasterPos(true) / GraIngame::getLength());
	}
	return round(Graphic::rasterPos(false) / GraIngame::getHeigth());
}

