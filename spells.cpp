/////////////////////////////////////////////////////////////////
//
//					spells.cpp
//					
//					spells a god can cast
//					
//
/////////////////////////////////////////////////////////////////

#include "spells.h"
#include "ingame.h"


#include "options.h"
#include "errors.h"
#include "gra_ingame.h"
#include "field.h"

/*
 *
 * returns smaller value
 *
 */
int min(int a, int b) {
	return a<b?a:b;
}

/*
 *
 * return bigger value
 *
 */
int max(int a, int b) {
	return a<b?b:a;
}
/*
 *
 * the spell "increase"
 *
 */
bool Spells::spIncrease() {
	int x = GraIngame::whichClicked(true);
	if (x >= Options::iNumberEdgesX - 1 || x <= 0)
		return false;
	int y = GraIngame::whichClicked(false);
	if (y >= Options::iNumberEdgesY || y <= 0)
		return false;
	if (incEdge(x,y))
		return true;
	return false;
}

/*
 *
 * the spell "decrease
 *
 */
bool Spells::spDecrease() {
	int x = GraIngame::whichClicked(true);
	if (x >= Options::iNumberEdgesX - 1 || x <= 0)
		return false;
	int y = GraIngame::whichClicked(false);
	if (y >= Options::iNumberEdgesY || y <= 0)
		return false;
	if (decEdge(x,y))
		return true;
	return false;
}

/*
 *
 * increases an edge and others if needed
 *
 */
bool Spells::incEdge(int x, int y) {	 //BUG: if at one position there is an error so higth can't be increased, all fields increased earlier will stay increased
	using namespace Ingame;
	if (x > 0 && y > 0 && x < Options::iNumberEdgesX && y < Options::iNumberEdgesY) {// if not at the border of map
		int heigth = min(fields[x][y].lb->getHeigth(),9);
		if (fields[x+1][y].lb->getHeigth() < heigth)
			if (!incEdge(x+1, y))
				return false;
		if (fields[x][y+1].lb->getHeigth() < heigth)
			if (!incEdge(x, y+1))
				return false;
		if (fields[x][y-1].lb->getHeigth() < heigth)
			if (!incEdge(x, y-1))
				return false;
		if (fields[x-1][y].lb->getHeigth() < heigth)
			if (!incEdge(x-1, y))
				return false;
		if (fields[x-1][y-1].lb->getHeigth() < heigth)
			if (!incEdge(x-1, y-1))
				return false;
		if (fields[x+1][y+1].lb->getHeigth() < heigth)
			if (!incEdge(x+1, y+1))
				return false;
		if (fields[x-1][y+1].lb->getHeigth() < heigth)
			if (!incEdge(x-1, y+1))
				return false;
		if (fields[x+1][y-1].lb->getHeigth() < heigth)
			if (!incEdge(x+1, y-1))
				return false;
		fields[x][y].lb->inc();
		fields[x][y].calcType();
		fields[x-1][y].calcType();
		fields[x][y-1].calcType();
		fields[x-1][y-1].calcType();
		return true;
	}
	return false;
}


bool Spells::decEdge(int x, int y) {
	using namespace Ingame;
	if (x > 0 && y > 0 && x < Options::iNumberEdgesX && y < Options::iNumberEdgesY) {// if not at the border of map
		int heigth = max(fields[x][y].lb->getHeigth(),0);
		if (fields[x+1][y].lb->getHeigth() > heigth)
			if (!decEdge(x+1, y))
				return false;
		if (fields[x][y+1].lb->getHeigth() > heigth)
			if (!decEdge(x, y+1))
				return false;
		if (fields[x][y-1].lb->getHeigth() > heigth)
			if (!decEdge(x, y-1))
				return false;
		if (fields[x-1][y].lb->getHeigth() > heigth)
			if (!decEdge(x-1, y))
				return false;
		if (fields[x-1][y-1].lb->getHeigth() > heigth)
			if (!decEdge(x-1, y-1))
				return false;
		if (fields[x+1][y+1].lb->getHeigth() > heigth)
			if (!decEdge(x+1, y+1))
				return false;
		if (fields[x-1][y+1].lb->getHeigth() > heigth)
			if (!decEdge(x-1, y+1))
				return false;
		if (fields[x+1][y-1].lb->getHeigth() > heigth)
			if (!decEdge(x+1, y-1))
				return false;
		fields[x][y].lb->dec();
		fields[x][y].calcType();
		fields[x-1][y].calcType();
		fields[x][y-1].calcType();
		fields[x-1][y-1].calcType();
		return true;
	}
	return false;
}