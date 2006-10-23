/////////////////////////////////////////////////////////////////
//
//					
//					game_object.cpp
//				
//					
//
/////////////////////////////////////////////////////////////////

#include "game_object.h"
#include "Ingame.h"
void GameObject::setPos(int x, int y) { 
	if (getX() > 0 && getY() > 0)  //hack(init problem)
		Ingame::fields[getX()][getY()].setBlocked(0);
	xPos = getPosConst() * x; 
	yPos = y * getPosConst(); 
	Ingame::fields[getX()][getY()].setBlocked(this);
}