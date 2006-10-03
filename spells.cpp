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
 * the spell "increase"
 *
 */
bool Spells::spIncrease()
{
	int x = GraIngame::whichClicked(true);
	if (x >= Options::iNumberEdgesX - 1)
		return false;
	int y = GraIngame::whichClicked(false);
	if (y >= Options::iNumberEdgesY)
		return false;
	Field* lp = Ingame::firstField;
	for (int i = 0; i <= x; i++)			// go to the edge which shall be increased
		lp = lp->rigth;
	for (int i = 0; i <= y; i++)
		lp = lp->top;
	if (incField(lp->lb, lp))
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
	if (x >= Options::iNumberEdgesX)
		return false;
	int y = GraIngame::whichClicked(false);
	if (y > Options::iNumberEdgesY)
		return false;
	Field* lp = Ingame::firstField;
	for (int i = 0; i <= x; i++)			// go to the edge which shall be increased
		lp = lp->rigth;
	for (int i = 0; i <= y; i++)
		lp = lp->top;
	if (decField(lp->lb, lp))
		return true;
	return false;
}

/*
 *
 * increases an edge and others if needed
 *
 */
bool Spells::incField(Edge* edge, Field* field) {	 //BUG: erhöht die höhe des drüberliegenden feldes auch wenn ein drunterliegendes feld nicht erhöht werden kann
	if (edge->getHeigth() == 10)
		return false;
	if (field != 0 && field->left != 0 && field->bottom != 0) {// if not at the border of map
		int heigth = edge->getHeigth();
		Field* other = field->left;
		if (other->lt->getHeigth() < heigth)	  // if size lower then increase
			if(!incField(other->lt, other->top))
				return false;

		other = other->rigth;
		if (other->lt->getHeigth() < heigth)	  // if size lower then increase
			if(!incField(other->lt, other->top))
				return false;

		if (other->rt->getHeigth() < heigth)	  // if size lower then increase
			if(!incField(other->rt, other->top->rigth))
				return false;

		other = other->bottom;
		if (other->rt->getHeigth() < heigth)	  // if size lower then increase
			if(!incField(other->rt, other->top->rigth))
				return false;

		if (other->rb->getHeigth() < heigth)	  // if size lower then increase
			if(!incField(other->rb, other->rigth))
				return false;

		if (other->lb->getHeigth() < heigth)	  // if size lower then increase
			if(!incField(other->lb, other))
				return false;

		other = other->left;
		if (other->lb->getHeigth() < heigth)	  // if size lower then increase
			if(!incField(other->lb, other))
				return false;
		other = other->top;
		if (other->lb->getHeigth() < heigth)	  // if size lower then increase
			if(!incField(other->lb, other))
				return false;
		edge->inc();
		field->calcType();
		field->left->calcType();
		field->bottom->calcType();
		field->left->bottom->calcType();
		return true;
	}
	return false;
}

/*
 *
 * same with decreasinng
 *
 */
bool Spells::decField(Edge* edge, Field* field)
{
	
	if (edge->getHeigth() == 0)
		return false;
	if (field != 0 && field->left != 0 && field->bottom != 0) {// if not at the border of map
		int heigth = edge->getHeigth();
		Field* other = field->left;
		if (other->lt->getHeigth() > heigth)	  // if size lower then increase
			if(!decField(other->lt, other->top))
				return false;

		other = other->rigth;
		if (other->lt->getHeigth() > heigth)	  // if size lower then increase
			if(!decField(other->lt, other->top))
				return false;

		if (other->rt->getHeigth() > heigth)	  // if size lower then increase
			if(!decField(other->rt, other->top->rigth))
				return false;

		other = other->bottom;
		if (other->rt->getHeigth() > heigth)	  // if size lower then increase
			if(!decField(other->rt, other->top->rigth))
				return false;

		if (other->rb->getHeigth() > heigth)	  // if size lower then increase
			if(!decField(other->rb, other->rigth))
				return false;

		if (other->lb->getHeigth() > heigth)	  // if size lower then increase
			if(!decField(other->lb, other))
				return false;

		other = other->left;
		if (other->lb->getHeigth() > heigth)	  // if size lower then increase
			if(!decField(other->lb, other))
				return false;
		other = other->top;
		if (other->lb->getHeigth() > heigth)	  // if size lower then increase
			if(!decField(other->lb, other))
				return false;
		edge->dec();
		field->calcType();
		field->left->calcType();
		field->bottom->calcType();
		field->left->bottom->calcType();
		return true;
	}
	return false;
}
