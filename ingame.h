/////////////////////////////////////////////////////////////////
//
//					gameMode.h
//					draws GraphicALTs while playing
//					play functions
//					
//
/////////////////////////////////////////////////////////////////


#ifndef INGAME_H_DEF
#define INGAME_H_DEF
#include <vector>

#include "hero.h"
#include "worker.h"
#include "field.h"
#include "menu_button.h"
#include "gameressources.h"
#include "party.h"


namespace worldModel{
	extern Field fields[MAX_FIELDS_X][MAX_FIELDS_Y];
	extern std::vector<Party> partys;
	void initGame();
	void DestroyWorld();

}

namespace Ingame
{ 
	void draw();
	void mouseClick(int button, int state, int x, int y);
	
	//void Input();
	
	


	void calc();
	
	
	
}

namespace Performance{
	extern int iFPSCounter;
	extern int timeBaseFPS;
	extern int timeBaseKeys;
	extern int iFPS;
}

#endif