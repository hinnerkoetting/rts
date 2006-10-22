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
		void setPos(int x, int y) { xPos = getPosConst() * x; yPos = y * getPosConst(); }
		void setID(int i) { id = i; }
		float lenX;
		float lenY;
	public:
		void setLen(float x, float y) { lenX = x; lenY = y; }
		float getLenX() { return lenX; }
		float getLenY() { return lenY; }
		virtual void draw() = 0;
		int getID() { return id; }
		static int getPosConst() { return 10000; }
		int getX() { return MyMath::round((float)xPos/getPosConst()); }
		int getY() { return MyMath::round((float)yPos/getPosConst()); }
};
#endif