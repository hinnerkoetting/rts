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

class GameObject {
	private:
		int id;
		
	protected:
		int xPos;
		int yPos;
		int belongTo;
		void changePos(float x, float y) { xPos += (int)(x *getPosConst()); yPos += (int)(y *getPosConst()); }
		int getExactX() { return xPos; } //just for graphical use
		int getExactY() { return yPos; }
		
		void setID(int i) { id = i; }
		int lenX; 
		int lenY;
		void setPos(int x, int y);
	public:
		
		GameObject() { }
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