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
	GraphicInterface::drawObjectGame(HEADQUARTER_ID, (float)this->getX(), (float)this->getY(), this->getLenX(), this->getLenY());
}
