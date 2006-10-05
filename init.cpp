/////////////////////////////////////////////////////////////////
//
//					init.cpp
//					inits game
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "ingame.h"
#include "field.h"
#include "options.h"
#include "ingame_menu.h"
#include "gra_ingame.h"
#include <vector>
#include "menue.h"
//test
/*
 *
 * creates edges
 * *NOTE: need to create world before calling
 */
using namespace std;
void Ingame::Init::createEdges() {
	int x = 0;
	int y = 0;
	while (x < Options::iNumberEdgesX) {
		y = 0;
		while (y < Options::iNumberEdgesY) {
			if (y == 0 && x == 0) {		// first field
				Ingame::fields[x][y].lt = new Edge(0);
				Ingame::fields[x][y].rt = new Edge(1);
				Ingame::fields[x][y].rb = new Edge(0);
				Ingame::fields[x][y].lb = new Edge(0);				
			}
			else if (y == 0) {     // most bottom line
				Ingame::fields[x][y].lt = Ingame::fields[x-1][y].rt;
				Ingame::fields[x][y].rt = new Edge(1);
				Ingame::fields[x][y].rb = new Edge(0);
				Ingame::fields[x][y].lb = Ingame::fields[x-1][y].rb;
			}
			else if (x == 0) {	// most left line
				Ingame::fields[x][y].lt = new Edge(0);
				Ingame::fields[x][y].rt = new Edge(1);
				Ingame::fields[x][y].rb = Ingame::fields[x][y-1].rt;
				Ingame::fields[x][y].lb = Ingame::fields[x][y-1].lt;	
			}
			else {
				Ingame::fields[x][y].lt = Ingame::fields[x-1][y].rt;
				Ingame::fields[x][y].rt = new Edge(1);
				Ingame::fields[x][y].rb = Ingame::fields[x][y-1].rt;
				Ingame::fields[x][y].lb = Ingame::fields[x-1][y].rb;
			}
			if (y == Options::iNumberEdgesY - 1) { //decrease most top line to heigth 0
				Ingame::fields[x][y].lt->dec();
				Ingame::fields[x][y].rt->dec();
			}
			if ( x == Options::iNumberEdgesX -1 && y < Options::iNumberEdgesY - 1) { //most right line
				Ingame::fields[x][y].rt->dec();
				Ingame::fields[x][y].rb->dec();
			}
			y++;
		}
		x++;
	}
}
			
/*
 *
 * creates the fields
 *
 */
void Ingame::Init::createFields(int x, int y) {
/*	Field* f;
	for (int i = 0; i < x; i++) {
		f = firstField;
		firstField = new Field();
		if (f != 0) {
			firstField->rigth = f;
			f->left = firstField;		
		}
		for (int j = 0; j < y; j++) {
			f = firstField;
			firstField = new Field();
			firstField->bottom = f;
			f->top = firstField;
			if (i != 0) {
				Field* lp = firstField->bottom->rigth->top;
				firstField->rigth = lp;
				lp->left = firstField;
			}
			

		}
		while (firstField->bottom != 0)
			firstField = firstField->bottom;
	}*/
}
/*
 *
 * calcs all fields
 *
 */
void Ingame::Init::calcFields() {
	for (int i = 0; i< Options::iNumberEdgesX; i++)
		for (int j = 0; j < Options::iNumberEdgesY; j++) 
			Ingame::fields[i][j].calcType();
}
/*
 *
 * creates world with x * y fields
 * returns field in bottom left edge
 */
void Ingame::Init::createWorld(int x, int y) {
	createFields(Options::iNumberEdgesX, Options::iNumberEdgesY);
	createEdges();
	calcFields();
}


/*
 *
 * initialises world
 *
 */
void Ingame::initGame() {
	Init::createWorld(Options::iNumberEdgesX, Options::iNumberEdgesY);
	Init::newHeroes(2);
	Init::newUnits(1);
	Init::menu();	

	
}


	


/*
 *
 * creates new heroes
 * TODO
 */
void Ingame::Init::newHeroes(const int iNumber) {

}

/*
 *
 * create new workers
 *
 */
void Ingame::Init::newUnits(int number) {
	for (int i = 0; i < number; i++) 
		Ingame::Workers.push_back(Worker(10 + i , 10 + i));

}

/*
 *
 * init menu button
 *
 */
void Ingame::Init::menu() {
	int resX = Options::ResolutionX;
	int resY = Options::ResolutionY;
	float wid = GraIngame::getMenuWidth();
	vector <MenuButton> menue;
	MenuButton* m1= new MenuButton(0, resX * 0.05/wid, resY * 0.1, resY * 0.15, &IngameMenu::test);

	MenuButton* m2 = new MenuButton(resX * 0.05/wid, resX * 0.1/wid, resY *0.1, resY*0.15, &IngameMenu::test);
	menue.push_back(*m1);
	menue.push_back(*m2);
	Menu::setMenuList(menue);
	
}