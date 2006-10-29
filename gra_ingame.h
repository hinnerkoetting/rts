/////////////////////////////////////////////////////////////////
//
//					
//					gra_ingame.h
//					graphical functions ingame
//					
//
/////////////////////////////////////////////////////////////////


#ifndef GRA_INGAME_H_DEF
#define GRA_INGAME_H_DEF



#include "gl/glut.h"
#include "point.h"
#include "graphic.h"
class GraIngame {

	public:
		static float menuWidth();
		static int whichClicked(bool bX);
		static void drawFields();
		static void drawPartys();
		static float getLength() { return fieldLength; }
		static float getHeigth() { return fieldHeigth; }
		static float getX() { return xPos; }
		static float getY() { return yPos;  }
		static float getZ() { return Graphic::zPos; }
		static int getMX() { return mouseX; }
		static int getMY() { return mouseY; }
		static float getMenuWidth() { return menuX; }		

		static void setMouse(int x, int y) { mouseX = x; mouseY = y; }
		
		static void move(float x, float y);
		
		static void zoom(float z) { if (Graphic::zPos + z < 1) Graphic::zPos = 1; else Graphic::zPos += 0.5*z; }
		static void drawCursor();

		
		static void setXPos(float x) { xPos = x; setCamera();}
		static void setYPos(float y) { yPos = y; setCamera();}
		static void createDLFields();
		static void createDLImages();
		static void createDL();
		static void setCamera();
		static void init();

	private:
		static void loadImages();
		static void setMenuWidth(float x ) { menuX = x; }
		static void drawBorders();
		static float xPos;	
		static float yPos;
		static int mouseX;
		static int mouseY;
		static float fieldLength;
		static float fieldHeigth;		
		static float menuX;
};

#endif