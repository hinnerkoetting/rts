/////////////////////////////////////////////////////////////////
//
//					
//					hero.h
//					class hero
//					
//
/////////////////////////////////////////////////////////////////

#ifndef HERO_H_DEF
#define HERO_H_DEF
#include "unit.h"
#include "spells.h"

class Fireball;
class Hero : public Unit{
	public:
		void draw();
		float fMana;
		Fireball* lpNextFireball;
		void clearHero();
		Hero(float x, float y) { xPos = x; yPos = y; }

};

#endif