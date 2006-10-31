/////////////////////////////////////////////////////////////////
//
//					
//					button_value.h
//					button class with extra value
//					
//
/////////////////////////////////////////////////////////////////

#include "button_value.h"
#include "graphic_interface.h"
#include "gra_ingame.h"
#include "defines.h"
#include "options.h"
#include "point.h"
#include <string>
#include "defines.h"


ButtonValue::ButtonValue(float x1, float x2, float y1, float y2, float relX, float relY, int id, int (*get)(int, int),int party, int village) {
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
}

	void ButtonValue::draw() {
	float wid = GraIngame::getMenuWidth();
	GraphicInterface::drawObjectMenu(id, x1 * Options::ResolutionX/wid, y1 *  Options::ResolutionY, (x2-x1)* Options::ResolutionX/wid, (y2-y1) * Options::ResolutionY);
	char buf[6];
	_itoa_s(this->getValue(), buf, 6, 10);
	GraphicInterface::drastring2d(x1+relativeX, y1+relativeY, BUTTON_VALUE_FONT, buf);
	drawBorders();
}

/*
 *
 * draw borders around image + value
 *
 */
void ButtonValue::drawBorders() {
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
void ButtonValue::click(int button) {
	
}

