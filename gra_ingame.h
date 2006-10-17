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


#define FIELD_WATER		1
#define FIELD_PLAIN		2
#define FIELD_GRAD1		3
#define	FIELD_GRAD2		4
#define	FIELD_GRAD3		5
#define	FIELD_GRAD4		6
#define	FIELD_GRAD5		7
#define	FIELD_GRAD6		8
#define	FIELD_GRAD7		9
#define	FIELD_GRAD8		10
#define	FIELD_GRAD9		11
#define	FIELD_GRAD10	12
#define	FIELD_GRAD11	13
#define	FIELD_GRAD12	14
#define	FIELD_GRAD13	15
#define FIELD_GRAD14	16
#define FIELD_BEHINDGRAD 17
#define BUTTON_HOUSE_ID 18
#define BUTTON_ATTACK_ID 19
#define UNIT_WORKER_ID 20
#include "gl/glut.h"
#include "point.h"
#include "graphic.h"
class GraIngame {
	
	public:
		static float menuWidth();
		static int whichClicked(bool bX);
		static void drawFields();
		static void drawUnits();
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
		static void createDLFields(int start);
		static void createDLImages(int start);
		static GLuint createDL();
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