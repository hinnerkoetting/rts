/////////////////////////////////////////////////////////////////
//
//					
//					button_value.h
//					button class with extra value
//					
//
/////////////////////////////////////////////////////////////////

#include "button_change.h"
#include "graphic_interface.h"
#include "gra_ingame.h"
#include "defines.h"
#include "options.h"
#include "point.h"
#include <string>

/*

ButtonChangeValue::ButtonChangeValue(float x1, float x2, float y1, float y2, float relX, float relY, int id, int (*getWish)(int, int), int (*getCurrent)(int, int), void (*inc)(int, int, int ),int party, int village) {
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	this->relativeX = relX;
	this->relativeY = relY;
	this->get = getWish;
	this->getCurrent=getCurrent;
	this->inc = inc;
	this->party = party;
	this->id = id;
	this->party = party;
	this->village = village;
}*/

ButtonChangeValue::ButtonChangeValue(float x1, float x2, float y1, float y2, float relX, float relY, int id, ButtonValueChangerHandler* handl, display::change_ID ch_Id) {
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	this->relativeX = relX;
	this->relativeY = relY;
	this->id=id;
	this->handler=handl;
	this->changeID=ch_Id;
}

void ButtonChangeValue::draw() {
	
	float wid = GraIngame::getMenuWidth();
	GraphicInterface::drawObjectMenu(id, x1 * Options::ResolutionX/wid, y1 *  Options::ResolutionY, (x2-x1)* Options::ResolutionX/wid, (y2-y1) * Options::ResolutionY);
	char buf[6];
	_itoa_s(handler->getWishedValue(changeID), buf, 6, 10);
	GraphicInterface::drastring2d(x1+relativeX, y1+relativeY, GLUT_BITMAP_TIMES_ROMAN_24, buf);

	char bufCurrent[6];
	_itoa_s(handler->getCurrentValue(changeID), bufCurrent, 6, 10);
	
	GraphicInterface::drastring2d(x1+relativeX, y1+relativeY-0.03, GLUT_BITMAP_TIMES_ROMAN_24, bufCurrent);
	drawBorders();
}



/* 
 *
 * what to do if mouse clicked on this object
 *
 */
void ButtonChangeValue::click(int button) {
	if (button == GLUT_LEFT_BUTTON){
		handler->changeValue(changeID,1);
	}
	if (button == GLUT_RIGHT_BUTTON){
		handler->changeValue(changeID,-1);
	}
		
}

