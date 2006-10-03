/////////////////////////////////////////////////////////////////
//
//					
//					inp_ingame.cpp
//					input ingame
//					
//
/////////////////////////////////////////////////////////////////

#include "input.h"
#include "ingame.h"

namespace Ingame {
	void input(unsigned char key, int x, int y);
	void inputSp(int key, int x, int y);
	extern int mouseHold;
	void mouse(int button, int state, int x, int y); 
	void mouseMove(int x, int y);
	void incTimeHold(int time);
	extern _Input keys[256];
	extern _Input mouseButton[5];
}