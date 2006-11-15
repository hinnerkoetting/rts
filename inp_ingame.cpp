/////////////////////////////////////////////////////////////////
//
//					
//					inp_ingame.cpp
//					input ingame
//					
//
/////////////////////////////////////////////////////////////////
#include <vector>

#include <windows.h>
#include "inp_ingame.h"
#include "input.h"
#include "exit.h"
#include "gl/glut.h"
#include "gra_ingame.h"
#include "errors.h"
#include "options.h"
#include "ingame.h"
#include "ingame_menu.h"
#include "spells.h"
#include "settings.h"

namespace Ingame {
	int mouseHold = -1;
	_Input keys[256];
	_Input mouseButton[5];
}

/*
 *
 * if enough time elapsed inc time key is hold
 *
 */
void Ingame::incTimeHold(int time) {
	if (time - Performance::timeBaseKeys > 20) {
		Performance::timeBaseKeys = time;
		for (int j = 0; j < 256; j++)
			if (keys[j].locked)
				keys[j].iIntervallHold++;
		for (int j = 0; j < 5; j++)
			if (mouseButton[j].locked)
				mouseButton[j].iIntervallHold++;
	}
}
/*
 *
 * special keys
 *
 */
void Ingame::inputSp(int key, int x, int y) {
	if (keys[key].iIntervallHold > Settings::RepeatLock(key)) 
		keys[key].locked = false;
	if (!keys[key].locked) {   // usually if u hold a button that linked function would be executed every frame, this way you lock that key for a period when its not executed
		keys[key].iIntervallHold = 0;
		keys[key].locked = true;
		switch (key) {
			case GLUT_KEY_LEFT:
				GraIngame::move(-1.0f, 0.0f);
				break;
			case GLUT_KEY_RIGHT:
				GraIngame::move(+1.0f, 0.0f);
				break;
			case GLUT_KEY_UP:
				GraIngame::move(0.0f, 1.0f);
				break;
			case GLUT_KEY_DOWN:
				GraIngame::move(0.0f, -1.0f);
				break;			
		}
	}
}
void Ingame::input(unsigned char key, int x, int y) {
	if (keys[key].iIntervallHold > Settings::RepeatLock(key)) 
		keys[key].locked = false;
	if (!keys[key].locked) {
		keys[key].iIntervallHold = 0;
		keys[key].locked = true;
		switch (key) {
			case 27: //esc
				glutLeaveGameMode();
				Options::WriteCfg();
				_exit(0);
				//Exit::doIt();
				break;
			case '+':
				GraIngame::zoom(-1);
				break;
			case '-':
				GraIngame::zoom(1);
				break;
			case 'a':
					Village* vil = Village::getVillage(0,0);
					vil->allUnits.at(1)->goTo(1,9);
					vil->allUnits.at(0)->goTo(5,2);
				break;	//testing purpose
		}
	}
}


/*
 *
 * handles mouse input: BUG: mouse kann nicht geklickt gelassen werden
 *
 */
void Ingame::mouse(int button, int state, int x, int y) {	
	if (state == GLUT_DOWN)
		mouseHold = button;
	else if (state == GLUT_UP || button == -1)
		mouseHold = -1;
	else {
		if (mouseButton[button].iIntervallHold > Settings::RepeatLock(button + 260)) 
			mouseButton[button].locked = false;
		if (!mouseButton[button].locked) {
			mouseButton[button].iIntervallHold = 0;
			mouseButton[button].locked = true;
			if (x <= Options::ResolutionX * GraIngame::getMenuWidth()) 
						Ingame::mouseClick(button, state, x, y); //TODO
			else {
				switch (button) {
					case GLUT_LEFT_BUTTON:
							Spells::spIncrease();
						break;
					case GLUT_RIGHT_BUTTON:
						Spells::spDecrease();
						break;
				}
			}
		}
	}
}

/*
 *
 * called when mouse is moves
 *
 */
void Ingame::mouseMove(int x, int y) {
	GraIngame::setMouse(x, y);
}


