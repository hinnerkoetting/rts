/////////////////////////////////////////////////////////////////
//
//					
//					button_display.h
//					button class with extra value
//					
//
/////////////////////////////////////////////////////////////////

#include "button_display.h"
#include "graphic_interface.h"
#include "gra_ingame.h"
#include "defines.h"
#include "options.h"
#include "point.h"
#include <string>
#include "defines.h"


/*ButtonDisplay::ButtonDisplay(float x1, float x2, float y1, float y2, float relX, float relY, int id, int (*get)(int, int),int party, int village) {
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	this->relativeX = relX;
	this->relativeY = relY;
	this->get = get;
	this->id = id;
	this->party = party;
	this->village = village;
}*/

ButtonDisplay::ButtonDisplay(float x1, float x2, float y1, float y2, float relX, float relY, int id, ButtonValueReader* handl, GameObject::gameObject_ID dID){
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	this->relativeX = relX;
	this->relativeY = relY;
	this->id = id;
	this->handler=handl;		
	this->displayID=dID;
	};	

ButtonDisplay::ButtonDisplay(float x1, float y1, int id, ButtonValueReader* handler, GameObject::gameObject_ID dID){
	this->x1 = x1;
	this->x2 = x1+0.1;
	this->y1 = y1;
	this->y2 = y1+0.1;
	this->relativeX = 0.2;
	this->relativeY = 0.2;
	this->id = id;
	this->handler=handler;		
	this->displayID=dID;
}


	void ButtonDisplay::draw() {
	float wid = GraIngame::getMenuWidth();
	GraphicInterface::drawObjectMenu(id, x1 * Options::ResolutionX/wid, y1 *  Options::ResolutionY, (x2-x1)* Options::ResolutionX/wid, (y2-y1) * Options::ResolutionY);
	char buf[6];
	_itoa_s(this->handler->getDisplayButtonValue(displayID), buf, 6, 10);
	GraphicInterface::drastring2d(x1+relativeX, y1+relativeY, BUTTON_VALUE_FONT, buf);
	drawBorders();
}


	
/*
 *
 * draw borders around image + value
 *
 */
void ButtonDisplay::drawBorders() {
	float lefX = (relativeX < x2-x1)?x1:x1+relativeX;
	float rigX = (relativeX >= x2-x1)?x1+relativeX:x2;
	float topY = (relativeY < y2-y1)?y1+relativeY:y1;
	float botY = (relativeY >= y2-y1)?y1+relativeY:y2;
	GraphicInterface::drawLineStrip(lefX, rigX, topY, botY, 1.0f, 1.0f, 1.0f);
}



/* 
 *
 * what to do if mouse clicked on this object
 *
 */
void ButtonDisplay::click(int button) {
	
}

