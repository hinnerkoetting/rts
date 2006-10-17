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
#include "graphic_interface.h"
#include "gra_ingame.h"
#include "gl/glut.h"
/*
 *
 *
 *
 */
void IngameMenu::test(int button) {
	if (button == GLUT_LEFT_BUTTON)
	Error::MesBoxOk("test", "ok");
	if (button == GLUT_RIGHT_BUTTON)
		Error::MesBoxOk("rechete taste", "a");
}

/*
 *
 * check what to do if a mouse is clicked on menu
 *
 */
void IngameMenu::miniMapClick(int button, int state, int x, int y) {
	float x1 = 0;
	float x2 = (float)(Options::ResolutionX - 1);
	float y1 = Options::ResolutionY - GraIngame::menuWidth() * Options::ResolutionX;
	float y2 = Options::ResolutionY;
	if (y >= y1) { //mouse click on minimap
		float ratioX = x/GraIngame::menuWidth()/(x2-x1);
		float ratioY = (y2-y)/(y2-y1);
		GraIngame::setXPos(ratioX * Options::iNumberEdgesX *GraIngame::getLength() - GraIngame::getZ() * 2 * GraIngame::getLength());
		GraIngame::setYPos(ratioY * Options::iNumberEdgesY*GraIngame::getHeigth());
	}
}//BIN DABEI alle öffentlichen graphic funktionen in die graphic interface zu packen