/////////////////////////////////////////////////////////////////
//
//					
//					menu_button.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "menu_button.h"
#include "point.h"
#include "ingame_menu.h"
#include "graphic_interface.h"
#include "gra_ingame.h"
#include <vector>
#include "options.h"
#include "defines.h"





int MenuButton::counter = 0 ;
MenuButton::MenuButton(float x1, float x2, float y1, float y2, void (*function)(int, MenuButton*)) {
	
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	this->function = function;
	this->id = counter++;
}

/*
 *
 * draws the button
 *
 */
void MenuButton::draw() {
	float wid = GraIngame::getMenuWidth();
	GraphicInterface::drawMenu(BUTTON_HOUSE_ID + id, x1 * Options::ResolutionX/wid, y1 *  Options::ResolutionY, (x2-x1)* Options::ResolutionX/wid, (y2-y1) * Options::ResolutionY);
	drawBorders();
}

void MenuButton::drawBorders() {
	GraphicInterface::drawLineStrip(x1, x2, 1, y2, 1.0f, 1.0f, 1.0f);
}
int MenuButton::getX1() {
	return x1 * Options::ResolutionX / GraIngame::getMenuWidth();
}
int MenuButton::getX2() {
	return x2 * Options::ResolutionX / GraIngame::getMenuWidth() ;
}
int MenuButton::getY1() {
	return y1 * Options::ResolutionY;
}
int MenuButton::getY2() {
	return y2 * Options::ResolutionY;
}