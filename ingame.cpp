/////////////////////////////////////////////////////////////////
//
//					ingame.cpp
//					draws GraphicALTs while playing
//					play functions
//					
//
/////////////////////////////////////////////////////////////////


#include "ingame.h"
#include "graphic.h"
#include "options.h"
#include "menue.h"
#include "spells.h"
#include "hero.h"
#include "worker.h"
//#include "netcode.h"
#include "settings.h"
#include "fireball.h"
#include "errors.h"
#include "gra_ingame.h"
#include "gl/glut.h"
#include <math.h>
#include "gra_string.h"
#include "inp_ingame.h"
#include "ingame_menu.h"

namespace Ingame {
	Field fields[MAX_FIELDS_X][MAX_FIELDS_Y];
	
	int iCurXPos = 0;	//map position
	int iCurYPos = 0;
	std::vector<Hero> Heroes;
	std::vector<Worker> Workers;
	int iFPSCounter = 0;
	int timeBaseFPS = 0;
	int timeBaseKeys = 0;
	int iFPS = 0;
}

double sqr(const double d) {
	return d*d;
}
/*
 *
 * draws game
 *
 */
void Ingame::draw() {	
	int time=glutGet(GLUT_ELAPSED_TIME);			
	Ingame::incTimeHold(time);
	IngameMenu::calcFPS(time);

	mouse(mouseHold, -1, GraIngame::getMX(), GraIngame::getMY());
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GraIngame::setCamera();
	glEnable(GL_SCISSOR_TEST);
	glEnable(GL_LIGHTING);
	glDisable(GL_LIGHTING);
	//glDisable(GL_LIGHTING);
	GraIngame::drawFields();
	GraIngame::drawUnits();
	GraIngame::drawCursor();
	
	glDisable(GL_SCISSOR_TEST);
	IngameMenu::drawMenu();
	
	glutSwapBuffers();
	glutPostRedisplay();
}

void Ingame::moveAllWorker() {
	for (unsigned i= 0; i < Ingame::Workers.size(); i++)
		Ingame::Workers.at(i).move();
}

void Ingame::findPathForAllWorker() {
	for (unsigned i= 0; i < Ingame::Workers.size(); i++)
		Ingame::Workers.at(i).findPath();
}
/*
 *
 * computing positions etc.
 * 
 */
void Ingame::calc() {
	moveAllWorker();
	findPathForAllWorker();
}
/*
 *
 * calls GraphicALT funtions
 *TODO?: rework
 */
void Ingame::Draw::Game()
{
	/*Draw::Fields();
	if (Options::bCoords)
		Draw::Coords();
	//DrawMargin();
	Draw::MiniMap();
	if (Options::bBorders)
		Draw::Borders();
	Ingame::Draw::RedPoint();
	Hero* lpHero = Heroes;
	while (lpHero != 0)
	{
		if (lpHero->fHealth <= 0)
		{
			Error::MesBoxOk("Sie haben gewonnen", "Hooray");
			DestroyWorld();
			Game::grafikStream = &Menu::MainMenu::DrawMenu;
//			Game::Input = &Menu::MainMenu::Input;
			return;
		}
		lpHero->DrawHero();
		Fireball* lpFireball = lpHero->lpNextFireball;
		while (lpFireball != 0)
		{
			if ((Game::MSecs() > sElapsedMSecsSpells + 10) || ( Game::Secs() > lElapsedSecsSpells))
				Fireball::Move(lpFireball);						
			Fireball::Draw(lpFireball);
			lpFireball = lpFireball->lpNextFireball;
		}				
		lpHero = lpHero->next;
	}
	if ((Game::MSecs() > sElapsedMSecsSpells + 10) || ( Game::Secs() > lElapsedSecsSpells))
	{
		sElapsedMSecsSpells = Game::MSecs();
			lElapsedSecsSpells = Game::Secs();
	}*/
}


void Ingame::Draw::MiniMap()
{
	Draw::MiniMapMargin();
	//DrawMapOverview();  //raw overview on minimap
	Draw::ClipBorders(); 
}

/*
 *
 * borders on minimap to show where player is located
 * TODO: rework
 */
void Ingame::Draw::MiniMapMargin()
{
	/*Gra::g.DrawLine(Point(-1.0f, -0.65f, 2.0f, 1.0f, 1.0f, 1.0f), Point(-0.65f, -0.65f, 2.0f, 1.0f, 1.0f, 1.0f)); 
	Gra::g.DrawLine(Point(-1.0f, -0.65f, 2.0f, 1.0f, 1.0f, 1.0f), Point(-1.0f, -1.0f, 2.0f, 1.0f, 1.0f, 1.0f)); 
	Gra::g.DrawLine(Point(-1.0f, -1.0f, 2.0f, 1.0f, 1.0f, 1.0f), Point(-0.65f, -1.0f, 2.0f, 1.0f, 1.0f, 1.0f)); 
	Gra::g.DrawLine(Point(-0.65f, -0.65f, 2.0f, 1.0f, 1.0f, 1.0f), Point(-0.65f, -1.0f, 2.0f, 1.0f, 1.0f, 1.0f)); */
}

/*
 *
 * draw borders of the current world clip into the minimap
 * TODO: rework
 */
void Ingame::Draw::ClipBorders()
{
	/*float left   = -1.0f + (iCurXPos - 20) * 0.35f / Options::iNumberEdgesX;
	float top    = -1.0f + (iCurYPos + 20) * 0.35f / Options::iNumberEdgesY;
	float right  = -1.0f + (iCurXPos + 20) * 0.35f / Options::iNumberEdgesX;
	float bottom = -1.0f + (iCurYPos - 20) * 0.35f / Options::iNumberEdgesY;
	Gra::g.DrawLine(Point(left, top, 1.0f, 1.0f, 1.0f, 1.0f), Point(right, top, 1.0f, 1.0f, 1.0f, 1.0f)); 
	Gra::g.DrawLine(Point(right, top, 2.0f, 1.0f, 1.0f, 1.0f), Point(right, bottom, 2.0f, 1.0f, 1.0f, 1.0f)); 
	Gra::g.DrawLine(Point(right, bottom, 2.0f, 1.0f, 1.0f, 1.0f), Point(left, bottom, 2.0f, 1.0f, 1.0f, 1.0f)); 
	Gra::g.DrawLine(Point(left, bottom, 2.0f, 1.0f, 1.0f, 1.0f), Point(left, top, 2.0f, 1.0f, 1.0f, 1.0f)); */
}


/*
 *
 * destroys all classes, .., created while played
 *
 */

void Ingame::DestroyWorld() {

	
}

/*
 *
 * checking where clicked, executing that function
 *
 */
void Ingame::mouseClick(int button, int state, int x, int y) {
	
	if(x <= Options::ResolutionX * GraIngame::getMenuWidth()) { // on menu
		if (y >= Options::ResolutionY - GraIngame::getMenuWidth() * Options::ResolutionX) //on minimap
			IngameMenu::miniMapClick(button, state, x, y);
		else {
			std::vector<MenuButton> menueList=Menu::getMenuList();

			int mx = x / GraIngame::getMenuWidth();
			for (unsigned int i=0;i<menueList.size();i++){				
				MenuButton btn=menueList.at(i);				
				if (  btn.x1 <= mx && btn.x2 >= mx && btn.y1 <= y && btn.y2 >= y)
					btn.function(button);
				//lp = button->nextButton;
			}
		}
	}
}