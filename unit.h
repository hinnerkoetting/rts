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

class  Unit  {
	//friend class Hero;	//(warum brauchen wir hier friend?)
	protected:
		int hp;
		std::string name;
		
		int speed;
		int timeSinceLastMove;
		int belongTo;
		Node* getPath() { return pf->getPath(); }
		//Node* moveList;
		Pathfinding* pf;
		void setPos(int x, int y) { xPos = getPosConst() * x; yPos = y * getPosConst(); }
		void changePos(float x, float y) { xPos += (int)(x *getPosConst()); yPos += (int)(y *getPosConst()); }
		int getX() { return MyMath::round((float)xPos/getPosConst()); }
		int getY() { return MyMath::round((float)yPos/getPosConst()); }
		int getExactX() { return xPos; } //just for graphical use
		int getExactY() { return yPos; }
		void roundPos() { setPos(getX(), getY()); }// sets actual position to an "integer" (Pos%getPosConst=0)
	private:
		int xPos;
		int yPos;
	public:
		static int getPosConst() { return 10000; }
		static int posTolerance() { return 500; }
		Unit() { pf = new Pathfinding(xPos, yPos);}
		
		void setHp(int h) { hp = h; }
		void changeHp(int c) { hp += c; }
		void setName(char* n) { name = n; }
		int getHp() { return hp; }
		std::string getName() { return name; }
		virtual void draw() = 0;
		void goTo(int x, int y);
		void findPath();
		//Unit* next;
		void move();
		virtual void think()=0; //if a unit acts autonom, the decision proces is here
		virtual void setNewGoal(int goal)=0; //sets general goal for a unit like mining
};
#endif