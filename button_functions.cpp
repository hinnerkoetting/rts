/////////////////////////////////////////////////////////////////
//
//					
//					button_functions.cpp
//					click on buttons
//					
//
/////////////////////////////////////////////////////////////////
#include "ingame_menu.h"
#include "errors.h"
#include "options.h"
#include "gra_ingame.h"
/*
 *
 *
 *
 */
void IngameMenu::test(int button) {
	Error::MesBoxOk("test", "ok");
}

/*
 *
 * check what to do if a mouse is clicked on menu
 *
 */
void IngameMenu::miniMapClick(int button, int state, int x, int y) {
	float x1 = 0;
	float x2 = (float)(Options::ResolutionX - 1);
	float y1 = Options::ResolutionY - GraIngame::getMenuWidth() * Options::ResolutionX;
	float y2 = Options::ResolutionY;
	if (y >= y1) { //mouse click on minimap
		float ratioX = x/GraIngame::getMenuWidth()/(x2-x1);
		float ratioY = (y2-y)/(y2-y1);
		GraIngame::setXPos(ratioX * Options::iNumberEdgesX *GraIngame::getLength() - GraIngame::getZ() * 2 * GraIngame::getLength());
		GraIngame::setYPos(ratioY * Options::iNumberEdgesY*GraIngame::getHeigth());
	}
}