/////////////////////////////////////////////////////////////////
//
//					
//					gra_ingame.h
//					graphical functions ViewAndControl
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

		//OpenGL manages a list of preprocessed graphic elements (performance reasons)
		//these are stored in a so called display list
		//this method loads all used graphic elements and preprocess elements
		static void createDisplayList();

		//Camera view point
		static void setCamera();

		
		//moves the view of the map
		static void mapMove(float x, float y);

		//COMMENT
		static void init();
		

		static void drawFields();
		static void drawPartys();
		static void drawCursor();
		static int whichClicked(bool bX);

		//getter Methods
		
		static float getX() { return xPos; }
		static float getY() { return yPos;  }
		static float getZ() { return Graphic::zPos; }
		static int getMX() { return mouseX; }
		static int getMY() { return mouseY; }
		
		static float getLength() { return fieldLength; }
		static float getHeigth() { return fieldHeigth; }
		static float getMenuWidth() { return menuX; }		

		//setter Methods
		static void setXPos(float x) { xPos = x; setCamera();}
		static void setYPos(float y) { yPos = y; setCamera();}


		static float menuWidth();
		
		
		static void setMouse(int x, int y) { mouseX = x; mouseY = y; }
		
		
		
		static void zoom(float z) {
			if (Graphic::zPos + z < 1) {
				Graphic::zPos = 1; 
			}
			else Graphic::zPos += 0.5*z; 
		}
		

		
		
		

	private:


		//loads Images from Files
		static void loadImages();

		static void createDisplayListFields();
		static void createDisplayListImages();
		
		static void setMenuWidth(float x ) { menuX = x; }
		static void drawBorders();
		

		//don't know...COMMENT
		static float xPos;	
		static float yPos;

		//current mouse position
		static int mouseX;
		static int mouseY;

		//field Size
		static float fieldLength;
		static float fieldHeigth;		

		//don't know...COMMENT
		static float menuX;
};

#endif