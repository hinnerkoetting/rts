/////////////////////////////////////////////////////////////////
//
//					ingame.h
//					draws GraphicALTs while playing
//					play functions
//					
//
/////////////////////////////////////////////////////////////////


#ifndef INGAME_H_DEF
#define INGAME_H_DEF
#include <vector>

#include "hero.h"
#include "worker.h"
#include "field.h"
#include "menu_button.h"
#include "gameressources.h"
#include "party.h"

namespace Ingame
{ 
	extern Field fields[MAX_FIELDS_X][MAX_FIELDS_Y];
	namespace Init {
		void createWorld(int x, int y);
		void createFields(int x, int y );
		void createEdges();
		void calcFields();
		void newHeroes(const int);
		void newUnits(int);
		void newGoldMines();
		void newVillages();
		void newPartys(int);
		void menu();
	}


	void draw();
	void calc();
	extern int iCurXPos;
	extern int iCurYPos;
	extern std::vector<Party> partys;
	extern std::vector<Hero> Heroes;
	extern std::vector<Worker> Workers;
	extern std::vector<Goldmine> goldmines;
	void moveAllWorker();
	
	void Input();
	
	void mouseClick(int button, int state, int x, int y);

	void initGame();
	void DestroyWorld();

	extern int iFPSCounter;
	extern int timeBaseFPS;
	extern int timeBaseKeys;
	extern int iFPS;
}
#endif