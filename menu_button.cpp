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
#include <vector>





int MenuButton::counter = 0 ;
MenuButton::MenuButton(int x1, int x2, int y1, int y2, void (*function)(int)) {
	
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
	GraphicInterface::drawMenu(18 + id, x1, y1, x2-x1, y2-y1);
}