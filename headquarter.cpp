/////////////////////////////////////////////////////////////////
//
//					
//					headquarter.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////


#include "headquarter.h"
#include "graphic_interface.h"
#include "defines.h"
void HeadQuarter::draw() {
	GraphicInterface::drawObjectGame(HEADQUARTER_ID, this->getX(), this->getY(), this->getLenX(), this->getLenY());
}
