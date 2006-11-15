/////////////////////////////////////////////////////////////////
//
//					gameMode.cpp
//					draws GraphicALTs while playing
//					play functions
//					
//
/////////////////////////////////////////////////////////////////


//#include "gameMode.h"
#include "options.h"
#include "menue.h"
#include "spells.h"
#include "hero.h"
#include "worker.h"
#include "settings.h"
#include "fireball.h"
#include "errors.h"
#include "gra_ingame.h"
#include "gl/glut.h"
#include <math.h>
#include "inp_ingame.h"
#include "ingame_menu.h"
#include "init.h"
#include "worldModel.h"
#include "gameViewAndControl.h"


namespace worldModel{
	Field fields[MAX_FIELDS_X][MAX_FIELDS_Y];
	std::vector<Party> partys;
}

namespace Performance{
	int iFPSCounter = 0;
	int timeBaseFPS = 0;
	int timeBaseKeys = 0;
	int iFPS = 0;

}

namespace ViewAndControl {

	
//	int iCurXPos = 0;	//map position
//	int iCurYPos = 0;

}

Party* Party::getParty(int nr) {
	if ((unsigned)nr < worldModel::partys.size()) 
		return &worldModel::partys.at(nr); 
	return 0;
}
double sqr(const double d) {
	return d*d;
}
/*
 *
 * draws game
 *
 */
void ViewAndControl::draw() {	
	
	static int b = 0;
	if (b <= 1) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		GraIngame::setCamera();
		glEnable(GL_SCISSOR_TEST);		
		GraIngame::drawFields();
		GraIngame::drawCursor();
		GraIngame::drawPartys();
		glDisable(GL_SCISSOR_TEST);
		IngameMenu::drawMenu();
		glutSwapBuffers();
	}
	b= (b+1)%Options::iRenderOnlyEveryFrame;
	glutPostRedisplay();
}



/*
 *
 * computing positions etc.
 * 
 */
void ViewAndControl::calc() {
	int time=glutGet(GLUT_ELAPSED_TIME);			
	ViewAndControl::incTimeHold(time);
	IngameMenu::calcFPS(time);
	mouse(mouseHold, -1, GraIngame::getMX(), GraIngame::getMY());
	for (std::vector<Party>::iterator i = worldModel::partys.begin(); i != worldModel::partys.end(); i++) {
		std::vector<Party>::value_type tmp = *i;
		tmp.calc();
	}

}









/*
 *
 * destroys all classes, .., created while played
 *
 */

void worldModel::DestroyWorld() {

	
}

/*
 *
 * checking where clicked, executing that function
 *
 */
void ViewAndControl::mouseClick(int button, int state, int x, int y) {
	if(x <= Options::ResolutionX * GraIngame::getMenuWidth()) { // on menu
		if (y >= Options::ResolutionY - GraIngame::getMenuWidth() * Options::ResolutionX) //on minimap
			IngameMenu::miniMapClick(button, state, x, y);
		else {
			std::vector<MenuButton*> menueList=ActiveMenu::getMenuList();

			int mx = x / GraIngame::getMenuWidth();
			for (unsigned int i=0;i<menueList.size();i++){				
				MenuButton* btn=menueList.at(i);				
				if (  btn->getX1() <= mx && btn->getX2() >= mx && btn->getY1() <= y && btn->getY2() >= y) //TODO: add this function local to class Menubutton, e.g. if u use button_value at the moment u cant click on the number
					btn->click(button);
			}
		}
	}
}
/*
 *
 * initialises world
 *
 */
void worldModel::initGame() {
	Init::start();	
}