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

/*
 *
 * creates edges
 * *NOTE: need to create world before calling
 */
void Ingame::Init::createEdges() {
	Field* lpX = Ingame::firstField;
	Field* lpY;
	while (lpX != 0) {
		lpY = lpX;
		while (lpY != 0) {
			if (lpY == firstField) {		// first field
				lpY->lt = new Edge(0);
				lpY->rt = new Edge(1);
				lpY->rb = new Edge(0);
				lpY->lb = new Edge(0);				
			}
			else if (lpY == lpX) {     // most bottom line
				lpY->lt = lpY->left->rt;
				lpY->rt = new Edge(1);
				lpY->rb = new Edge(0);
				lpY->lb = lpY->left->rb;
			}
			else if (lpX == firstField) {	// most left line
				lpY->lt = new Edge(0);
				lpY->rt = new Edge(1);
				lpY->rb = lpY->bottom->rt;
				lpY->lb = lpY->bottom->lt;	
			}
			else {
				lpY->lt = lpY->left->rt;
				lpY->rt = new Edge(1);
				lpY->rb = lpY->bottom->rt;
				lpY->lb = lpY->left->rb;
			}
			lpY = lpY->top;
		}
		lpX = lpX->rigth;
	}
}
			
/*
 *
 * creates the fields
 *
 */
void Ingame::Init::createFields(int x, int y) {
	Field* f;
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
	}
}
/*
 *
 * calcs all fields
 *
 */
void Ingame::Init::calcFields() {
	Field* lpX = firstField;
	Field* lpY;
	while (lpX != 0) {
		lpY = lpX;
		while (lpY != 0) {
			lpY->calcType();
			lpY = lpY->top;
		}
		lpX = lpX->rigth;
	}
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
	Init::newUnits(30);
	Init::menu();	

	
}


	


/*
 *
 * creates new heroes
 *
 */
void Ingame::Init::newHeroes(const int iNumber) {
	Hero* lpHero;
	for (int i = 0; i < iNumber; i++) {	
		lpHero = new Hero(i*20, i*20);
		if (Heroes == 0) {
			Heroes = lpHero;
			Heroes->next = 0;
		}
		else {
			lpHero->next = Heroes->next;
			Heroes->next = lpHero;
		}
	}
}

/*
 *
 * create new workers
 *
 */
void Ingame::Init::newUnits(int number) {
	Worker* lpWorker;
	for (int i = 0; i < number; i++) {
			lpWorker = new Worker(10 + i , 10 + i);
		if (Workers == 0) {
			Workers = lpWorker;
			Workers->next = 0;
		}
		else {
			lpWorker->next = Workers->next;
			Workers->next = lpWorker;
		}
	}
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
	IngameMenu::buttonList = new MenuButton(0, resX * 0.05/wid, resY * 0.1, resY * 0.15, &IngameMenu::test);
	MenuButton* lp = IngameMenu::buttonList;
	IngameMenu::buttonList = new MenuButton(resX * 0.05/wid, resX * 0.1/wid, resY *0.1, resY*0.15, &IngameMenu::test);
	IngameMenu::buttonList->nextButton = lp;
}