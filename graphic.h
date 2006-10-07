/////////////////////////////////////////////////////////////////
//
//					
//					GraphicALT.h
//					GraphicALT functions
//					
//
/////////////////////////////////////////////////////////////////



#include "point.h"
#include "gl/glut.h"



#ifndef DEF_GRAPHIK_H
#define DEF_GRAPHIK_H

class Graphic {
	
	friend class GraIngame;
	friend class IngameMenu;
	public:
		
		static void init(int argc, char **argv);
		static void renderScene();
		static void changeSize(int w, int h);
		static void changeTo2D();
		static void changeTo3D();
		
		static float pixelToGl(int pos, float z, bool bX);
		static int glToPixel(Point P0, bool bX);
		static Point changeHeigth(Point, float z);
		static float rasterPos(bool bX);
		static void Graphic::resolution(char c[16]);

		static void drastring3d(float x, float y, float z, void *font, char *string);
		static void drastring2d(float x, float y, void *font, char *string);
		static void resetColor(Point* p);
		static void loadImage(char* fileName);
		static GLuint texture[2];
		static void bindImage();
		static void drawLine3D(Point P0, Point P1);
		static void drawLine2D(Point P0, Point P1);
		static void drawEmptyQuad(Point, Point, Point, Point);
	private:
		
		
		static bool visible(Point);
		
		
		static void drawQuad(Point P0, Point P1, Point P2, Point P3);
		static void drawPixel(Point P0, float f);
		static void drawTriangle(Point P0, Point P1, Point P2);		
		
		static float zPos;
		
};
#endif