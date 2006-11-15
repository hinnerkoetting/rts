/////////////////////////////////////////////////////////////////
//
//					
//					game_menu.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////
#include <windows.h>
#include "ingame_menu.h"
#include "gra_ingame.h"
#include "gl/glut.h"
#include "options.h"
#include "ingame.h"
#include "errors.h"
#include "menue.h"
#include "graphic_interface.h"
/*
 *
 * draws menu
 *
 */

using namespace std;
void IngameMenu::drawMenu() {
	Graphic::changeTo2D();
	
	glLoadIdentity();
	char buf[5];
	_itoa_s(Performance::iFPS, buf, 5, 10);
	GraphicInterface::drastring2d(0.01, 0.03, GLUT_BITMAP_TIMES_ROMAN_24, buf); //fps
	Graphic::drawLine2D(Point(Options::ResolutionX -1, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f), // rigth border
							Point(Options::ResolutionX -1, Options::ResolutionY, 0.0f, 1.0f, 1.0f, 1.0f));

	IngameMenu::drawMiniMap();
	drawButtons();
	Graphic::changeTo3D();
	
}

/*
 *
 * draws buttons
 *
 */
void IngameMenu::drawButtons() { 
	vector<MenuButton*> menue=ActiveMenu::getMenuList();
	for (unsigned i=0;i<menue.size();i++){		
		menue.at(i)->draw();
	}
}
/*
 * 
 * draw fps
 *
 */
void IngameMenu::calcFPS(int time) {
	using namespace Ingame;
	Performance::iFPSCounter++;
	if (time - Performance::timeBaseFPS > 1000) {
		Performance::timeBaseFPS = time;
		Performance::iFPS = Performance::iFPSCounter;
		Performance::iFPSCounter = 0;
	}
}

/*
 *
 *draw minimap
 *
 */
void IngameMenu::drawMiniMap() {
	int x1 = 0;
	int x2 = Options::ResolutionX - 1;
	int y1 = Options::ResolutionY - GraIngame::getMenuWidth() * Options::ResolutionX;
	int y2 = Options::ResolutionY;
	Graphic::drawLine2D(Point(x1, y1, 0, 0.8f, 0.1f, 0.1f), // outer border
						Point(x2, y1, 0, 0.8f, 0.1f, 0.1f)); 
	Graphic::drawLine2D(Point(x2, y1, 0, 0.8f, 0.1f, 0.1f),
						Point(x2, y2, 0, 0.8f, 0.1f, 0.1f)); 
	float visX = 0.75* 1.105f * GraIngame::getZ() / GraIngame::getLength(); //visible worldModel::fields in x direction
	float visY = 0.83f * GraIngame::getZ() / GraIngame::getHeigth();
	float lenghtX = (x2-x1) * (visX/Options::iNumberEdgesX); //pixel per field avaible on minimap
	float lenghtY = (y2-y1) * (visY/Options::iNumberEdgesY);
	float posX =((GraIngame::getX()+3*GraIngame::getZ()/20)/GraIngame::getLength())/Options::iNumberEdgesX * (x2-x1);   //HACK
	float posY =((GraIngame::getY())/GraIngame::getHeigth())/Options::iNumberEdgesY * (y2-y1);
	int py = (y2 - lenghtY/2 - posY > y1)?y2 - lenghtY/2 - posY:y1;
	Point P1 = Point(x1 - lenghtX/2 + posX,py, 0.0f, 1.0f);
	Point P2 = Point(x1 + lenghtX/2 + posX,py, 0.0f, 1.0f);
	Point P3 = Point(x1 + lenghtX/2 + posX, y2 + lenghtY/2 - posY, 0.0f, 1.0f);
	Point P4 = Point(x1 - lenghtX/2 + posX, y2 + lenghtY/2 - posY, 0.0f, 1.0f);
	Graphic::drawLine2D(P1, P2);			
	Graphic::drawLine2D(P2, P3);						
	Graphic::drawLine2D(P3, P4);
	Graphic::drawLine2D(P4, P1);
}


