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
#include "mymath.h"
#include "game_object.h"

class  Unit : public GameObject {
	//friend class Hero;	//(warum brauchen wir hier friend?)
	protected:
		int hp;
		std::string name;
		
		int speed;
		int timeSinceLastMove;
		
		std::list<Node*> getPath() { return pf->getPath(); }
		Pathfinding* pf;
		void roundPos() { setPos(getX(), getY()); }// sets actual position to an "integer" (Pos%getPosConst=0)
	private:
		
		
	public:
		
		static int posTolerance() { return 500; }
		Unit() { pf = new Pathfinding(xPos, yPos); } 
		
		void setHp(int h) { hp = h; }
		void changeHp(int c) { hp += c; }
		void setName(char* n) { name = n; }
		int getHp() { return hp; }
		std::string getName() { return name; }
		virtual void draw() = 0;
		void goTo(int x, int y);
		void findPath();
		void move();
		virtual void think()=0; //if a unit acts autonom, the decision proces is here
		virtual void setNewGoal(int goal)=0; //sets general goal for a unit like mining
};
#endif