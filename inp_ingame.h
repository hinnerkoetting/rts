/////////////////////////////////////////////////////////////////
//
//					
//					inp_ingame.cpp
//					input ViewAndControl
//					
//
/////////////////////////////////////////////////////////////////

#include "input.h"
#include "gameViewAndControl.h"

namespace ViewAndControl {
	void input(unsigned char key, int x, int y);
	void inputSp(int key, int x, int y);
	extern int mouseHold;
	void mouse(int button, int state, int x, int y); 
	void mouseMove(int x, int y);
	void incTimeHold(int time);
	extern _Input keys[256];
	extern _Input mouseButton[5];
}