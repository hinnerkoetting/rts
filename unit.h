/////////////////////////////////////////////////////////////////
//
//					
//					unit.h
//					abstract class of all units in game
//					
//
/////////////////////////////////////////////////////////////////
#ifndef UNIT_H_DEF
#define UNIT_H_DEF

#include <string> 
#include "pathfinding.h"
#include "pathfinding.h"
class  Unit  {
	friend class Hero;	//(warum brauchen wir hier friend?)
	protected:
		int hp;
		std::string name;
		float xPos;
		float yPos;
		int speed;
		int timeSinceLastMove;
		int belongTo;
		Node* getPath() { return pf->getPath(); }
		//Node* moveList;
		Pathfinding* pf;
	private:
		
	public:
		Unit() { pf = new Pathfinding(xPos, yPos);}
		float getX() { return xPos; }
		float getY() { return yPos; }
		void setHp(int h) { hp = h; }
		void changeHp(int c) { hp += c; }
		void setName(char* n) { name = n; }
		int getHp() { return hp; }
		std::string getName() { return name; }
		virtual void draw() = 0;
		void goTo(float x, float y);
		void findPath();
		//Unit* next;
		void move();
		//virtual void think()=0; //if a unit acts autonom, the decision proces is here
};
#endif