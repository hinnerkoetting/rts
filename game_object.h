/////////////////////////////////////////////////////////////////
//
//					
//					game_object.h
//					
//					
//
/////////////////////////////////////////////////////////////////
#ifndef GAME_OBJECT_H_DEF
#define GAME_OBJECT_H_DEF
#include "mymath.h"
/* 
 *
 * every object in game which stands on gamefield is derived by this class
 *
 */



class GameObject {
	
//Goldminer wird rausgenommen
//statt dessen wird einfach Gold eingetragen

public: enum gameObject_ID {  SOLDIER=100, IDLEWORKER, TOTAL_UNITS, GOLD, WOOD, OIL};




	private:
		int id;				//every unit type has an unique id
		
	protected:
		void setBlocked();	// blocks all fields this object stands on
		int xPos;					// yPos is calculated by y-field * posconst
		int yPos;
		int belongTo;
		void changePos(float x, float y) { xPos += (int)(x *getPosConst()); yPos += (int)(y *getPosConst()); }
		int getExactX() { return xPos; } //usually you just want to know on which field a unit stands but for
		int getExactY() { return yPos; } // graphic display you need to be more exact
										 
		
		void setID(int i) { id = i; }	
		int lenX;	//length in x direction
		int lenY;  // y
		void setPos(int x, int y); // set position
		GameObject();
	public:
		
		
		void setLen(int x, int y) { lenX = x; lenY = y; }	
		int getLenX() { return lenX; }
		int getLenY() { return lenY; }
		virtual void draw() = 0;
		int getID() { return id; }
		static int getPosConst() { return 10000; }
		int getX() { return MyMath::round((float)xPos/getPosConst()); }
		int getY() { return MyMath::round((float)yPos/getPosConst()); }
};
#endif