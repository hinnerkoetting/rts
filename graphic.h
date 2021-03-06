/////////////////////////////////////////////////////////////////
//
//					
//					GraphicALT.h
//					GraphicALT functions
//					
//
/////////////////////////////////////////////////////////////////


#include <map>
#include <string>
#include "point.h"
#include "gl/glut.h"
#include "game_object.h"




#ifndef DEF_GRAPHIK_H
#define DEF_GRAPHIK_H
struct Tex {
	GLuint texture;
	int id;
};

class Graphic {
	friend class GraIngame;
	friend class IngameMenu;
	friend class GraphicInterface;
	public:
		static void renderScene();
		static void changeSize(int w, int h);	
		static float rasterPos(bool bX);
		static void Graphic::resolution(char c[16]);	
		
		static  std::map<GameObject::gameObject_ID,GLuint> gameObjectTextures;
		
		static Tex texture[100];
		static int nrTextures;
		static void drawLineStrip(Point P0, Point P1, Point P2, Point P3);
		static void drawQuad(Point P0, Point P1, Point P2, Point P3);
		//static void drawEmptyQuad(Point, Point, Point, Point);
	private:
		static void loadImage(char* fileName, int id);
		static void loadGameObjectImage(std::string fileName, GameObject::gameObject_ID);
		static void bindImage();
		static void drawLine3D(Point P0, Point P1);
		static void drawLine2D(Point P0, Point P1);

		static void resetColor(Point* p);
		static Point changeHeigth(Point, float z);
		static float pixelToGl(int pos, float z, bool bX);
		static int glToPixel(Point P0, bool bX);
		static void changeTo2D();
		static void changeTo3D();
		static void init(int argc, char **argv);
		
		static bool visible(Point);
		
		
		
		static void drawPixel(Point P0, float f);
		static void drawTriangle(Point P0, Point P1, Point P2);		
		
		static float zPos;
		
};
#endif