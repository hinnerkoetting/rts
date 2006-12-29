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



/**
 * responsible for displaying the game during play and for reaction to inputs (mouse, keyboard)
 */

namespace ViewAndControl
{ 
	// draws everything during gameplay (delegates to other functions of course
	void draw();

	//reaction on mouse 
    //@button nrOfButton, 
	//@state   kind of press (e.g. left or right button)
	//x,y coordinates
	void mouseClick(int button, int state, int x, int y);
	
	//void Input();
	
	

	//automatic calculations in the game (maybe moving)
	void mouse_calc();
	
	
	
}

//frame per second calculation
namespace Performance{
	extern int iFPSCounter;
	extern int timeBaseFPS;
	extern int timeBaseKeys;
	extern int iFPS;
}

#endif