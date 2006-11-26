/////////////////////////////////////////////////////////////////
//
//					init.cpp
//					inits game
//					
//					
//
/////////////////////////////////////////////////////////////////

//#include "gameMode.h"
#include "field.h"
#include "options.h"
#include "ingame_menu.h"
#include "gra_ingame.h"
#include <vector>
#include "menue.h"
#include "button_display.h"
#include "button_ressource.h"
#include "party.h"
#include "defines.h"
#include "init.h"
#include "gameViewAndControl.h"
#include "worldModel.h"
//test
/*
 *
 * creates edges
 * *NOTE: need to create world before calling
 */
using namespace std;
void Init::createEdges() {
	int x = 0;
	int y = 0;
	while (x < Options::iNumberEdgesX) {
		y = 0;
		while (y < Options::iNumberEdgesY) {
			if (y == 0 && x == 0) {		// first field
				worldModel::fields[x][y].lt = new Edge(0);
				worldModel::fields[x][y].rt = new Edge(1);
				worldModel::fields[x][y].rb = new Edge(0);
				worldModel::fields[x][y].lb = new Edge(0);				
			}
			else if (y == 0) {     // most bottom line
				worldModel::fields[x][y].lt = worldModel::fields[x-1][y].rt;
				worldModel::fields[x][y].rt = new Edge(1);
				worldModel::fields[x][y].rb = new Edge(0);
				worldModel::fields[x][y].lb = worldModel::fields[x-1][y].rb;
			}
			else if (x == 0) {	// most left line
				worldModel::fields[x][y].lt = new Edge(0);
				worldModel::fields[x][y].rt = new Edge(1);
				worldModel::fields[x][y].rb = worldModel::fields[x][y-1].rt;
				worldModel::fields[x][y].lb = worldModel::fields[x][y-1].lt;	
			}
			else {
				worldModel::fields[x][y].lt = worldModel::fields[x-1][y].rt;
				worldModel::fields[x][y].rt = new Edge(1);
				worldModel::fields[x][y].rb = worldModel::fields[x][y-1].rt;
				worldModel::fields[x][y].lb = worldModel::fields[x-1][y].rb;
			}
			if (y == Options::iNumberEdgesY - 1) { //decrease most top line to heigth 0
				worldModel::fields[x][y].lt->dec();
				worldModel::fields[x][y].rt->dec();
			}
			if ( x == Options::iNumberEdgesX -1 && y < Options::iNumberEdgesY - 1) { //most right line
				worldModel::fields[x][y].rt->dec();
				worldModel::fields[x][y].rb->dec();
			}
			y++;
		}
		x++;
	}
}
			


/*
 *
 * calcs all worldModel::fields
 *
 */
void Init::calcFields() {
	for (int i = 0; i< Options::iNumberEdgesX; i++)
		for (int j = 0; j < Options::iNumberEdgesY; j++) 
			worldModel::fields[i][j].calcType();
}
/*
 *
 * creates world with x * y worldModel::fields
 * returns field in bottom left edge
 */
void Init::createWorld(int x, int y) {
	createEdges();
	calcFields();
}

/* 
 *
 * creates partys
 *	should be much more individual...
 */
void Init::newPartys(int number) {
	std::vector<Party> p;
	for (int i = 0; i < number; i++) {
		p.push_back(Party());
		Goldmine* g=new Goldmine(15,15);
		Village* v=new Village(10,10);
		v->setName("WALLHOEFEN");
		v->setGoldMine(g);
		
		p.at(p.size() -1 ).addVillage(v);
		
	}
	worldModel::partys = p;
}

/* 
 *
 * creates villages
 *
 */

void Init::newVillages() {
}




void Init::start() {
	Init::createWorld(Options::iNumberEdgesX, Options::iNumberEdgesY);
	Init::newPartys(1);
	Init::newHeroes(2);
	Init::newUnits(1);
	Init::newGoldMines();
	Init::newVillages();
	//Init::menu();	
}

	


/*
 *
 * creates new heroes
 * TODO
 */
void Init::newHeroes(const int iNumber) {

}

/*
 *
 * create new workers
 *
 */
void Init::newUnits(int number) {


}
/*
 *
 * create some goldmines
 */
void Init::newGoldMines() {	

}



/*
 *
 * init menu button
 *
 */
void Init::menu() {
	int resX = Options::ResolutionX;
	int resY = Options::ResolutionY;
	float wid = GraIngame::getMenuWidth();
	vector <MenuButton*> menue;
	//now in the village
/*	MenuButton* m1;
	//m1 = new ButtonDisplay	(0		, 0.05	, 0.1, 0.15, 0.02, 0.08, BUTTON_UNIT_ID		, this);

	//m1 = new ButtonDisplay	(0		, 0.05	, 0.1, 0.15, 0.02, 0.08, BUTTON_UNIT_ID		, &Village::getAllUnitsIn	, 0, 0);
	//menue.push_back(m1);
	//m1 = new ButtonDisplay	(0		, 0.05	, 0.2, 0.25, 0.02, 0.08, BUTTON_HOUSE_ID	, &Village::getIdleUnitsIn	, 0 ,0);
 	menue.push_back(m1);
	m1 = new ButtonRessource (0.05	, 0.1	, 0.2, 0.25, 0.02, 0.08, BUTTON_ATTACK_ID	, this, display::SOLDIER);
	//m1 = new ButtonRessource (0.05	, 0.1	, 0.2, 0.25, 0.02, 0.08, BUTTON_ATTACK_ID	, &Village::getWishedSoldiersIn	, &Village::getCurrentSoldiersIn, &Village::changeValueOfWishedSoldiers,  0,0);
	//menue.push_back(m1);
	m1 = new ButtonRessource (0.1	, 0.15	, 0.2, 0.25, 0.02, 0.08, BUTTON_GOLDMINE_ID	, &Village::getWishedGoldMinerIn	, &Village::getCurrentGoldMinerIn, &Village::changeValueOfWishedGoldMiner,  0,0);
	m1 = new ButtonRessource (0.1	, 0.15	, 0.2, 0.25, 0.02, 0.08, BUTTON_GOLDMINE_ID	, this, display::GOLD);
	menue.push_back(m1);
	
	ActiveMenu::setMenuList(menue);
*/	
}