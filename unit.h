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
class  Unit  {
	friend class Hero;	
	protected:
		int hp;
		std::string name;
		float xPos;
		float yPos;
		int speed;
		int timeSinceLastMove;
		int belongTo;
		Node* path;
		Node* moveList;
		void createPath(float desX, float desY);
		void initPath(); //needs to be called in every constructor by classes which are derived by this one
	private:
		
	public:
		float getX() { return xPos; }
		float getY() { return yPos; }
		void setHp(int h) { hp = h; }
		void changeHp(int c) { hp += c; }
		void setName(char* n) { name = n; }
		int getHp() { return hp; }
		std::string getName() { return name; }
		virtual void draw() = 0;
		void goTo(float x, float y);
		//Unit* next;
		void move();
};
#endif