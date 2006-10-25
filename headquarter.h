/////////////////////////////////////////////////////////////////
//
//					
//					headquarter.h	
//					
//					
//
////////////////////////////////////////////////////////////////

#ifndef HEADQUARTER_H_DEF
#define HEADQUARTER_H_DEF
#include "building.h"

class HeadQuarter : public Building {
	public:
		HeadQuarter(int x, int y, int belongTo) { this->setPos(x, y); this->setID(belongTo); this->setLen(3,3); setBlocked(); }
		void draw();
};
#endif