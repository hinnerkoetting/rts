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
	private:
	public:
		void draw();
		float fMana;
		Fireball* lpNextFireball;
		void clearHero();
		Hero(int x, int y) { setPos(x,y); }
		void think(){};  //a hero doesn't need to think. The human behind does
		void setNewGoal(int goal){}; //not under computer control

};

#endif