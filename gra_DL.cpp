/////////////////////////////////////////////////////////////////
//
//					
//					creates display lists
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "gra_ingame.h"
#include "gl/glut.h"
#include "devil/include/IL/ilut.h"
#include "options.h"
#include "graphic.h"
/*
 *
 * drawborders
 *
 */
void GraIngame::drawBorders() {
	if (Options::bBorders) {
		Point PB0		 = Point(-getLength(), -getHeigth(), 0.0f, 0.1, 0.1, 0.1);
		Point PB1		 = Point(0, -getHeigth(), 0.0f, 0.1, 0.1, 0.1);
		Point PB2		 = Point(0, 0, 0.0f, 0.1, 0.1, 0.1);
		Point PB3		 = Point(-getLength(), 0, 0.0f, 0.1, 0.1, 0.1);
		Graphic::drawLineStrip(PB0, PB1, PB2, PB3);
	}
}

void GraIngame::createDLFields() {
	GLuint start = glGenLists(100);
	float r = 0.2f;										// create DL of a water field
	float g = 0.05f;
	float b = 1.0f;
	Point P0 = Point(0					, -getHeigth(), 0, r, g, b);
	Point P1 = Point(0					, 0				  , 0, r, g, b);
	Point P2 = Point(- getLength()		, 0				  , 0, r, g, b);
	Point P3 = Point(-getLength()		, -getHeigth(), 0, r, g, b);
	glNewList(start, GL_COMPILE);			
		Graphic::drawQuad(P0, P1, P2, P3);
		drawBorders();
	glEndList();

	r = 0.6f;											// create DL of a plane field above water
	g = 0.3f;
	b = 0.1f;

	P0 = Point(0				, -getHeigth(), 0, r, g, b);
	P1 = Point(0				, 0				  , 0, r, g, b);
	P2 = Point(-1 * getLength()	, 0				  , 0, r, g, b);
	P3 = Point(-1 * getLength()	, -getHeigth(), 0, r, g, b);
	glNewList(start + 1, GL_COMPILE);		
		
		Graphic::drawQuad(P0, P1, P2, P3);
		drawBorders();
	glEndList();


	r = 0.1f;
	g = 0.2f;
	b = 0.0f;
	P0 =						Point(-getLength(), 0, 0, r			, g			, b);
	P1 = Graphic::changeHeigth(	Point( 0		, 0 ,  0, r *2		, g *2		, b), 0.0f);
	P2 = 						Point( 0,-getHeigth(), 0, r			, g			, b);
	P3 =						Point(-getLength()	,-getHeigth(), 0, r, g, b);
	glNewList(start + 2, GL_COMPILE);
		Graphic::drawTriangle(P0, P1, P2);
		drawBorders();
	glEndList();
	P0 = Point(-getLength()	,0, 0, r, g, b);
	P1 = Graphic::changeHeigth(Point(0,0, 0, r * 2, g * 2, b), 0.0f),
	P2 = Graphic::changeHeigth(Point(0	,-getHeigth(), 0, r * 2, g * 2, b), 0.0f),
	P3 = Point(-getLength()	,-getHeigth(), 0, r, g, b);
	glNewList(start + 3, GL_COMPILE);
		Graphic::drawQuad(P0, P1, P2, P3);	
		drawBorders();
	glEndList();
	
	P0 =						Point(0, 0, 0, r			, g			, b);
	P1 = Graphic::changeHeigth(	Point( 0		, -getHeigth() ,  0, r *2		, g *2		, b), 0.0f);
	P2 = 						Point( -getLength(),-getHeigth(), 0, r			, g			, b);
	glNewList(start + 4, GL_COMPILE);
		Graphic::drawTriangle(P0, P1, P2);	
		drawBorders();
	glEndList();
	P0 = Point(-getLength()	,0, 0, r, g, b);
	P1 = Point(0,0, 0, r, g, b);
	P2 = Graphic::changeHeigth(Point(0	,-getHeigth(), 0, r * 2, g * 2, b), 0.0f);
	P3 = Graphic::changeHeigth(Point(-getLength()	,-getHeigth(), 0, r * 2, g * 2, b), 0.0f);
	glNewList(start + 5, GL_COMPILE);
		Graphic::drawQuad(P0, P1, P2, P3);	
		drawBorders();
	glEndList();
	
	P0 =						Point(-getLength(), 0, 0, r			, g			, b);
	P1 =					 	Point( 0		, -getHeigth() ,  0, r			, g			, b);
	P2 = Graphic::changeHeigth(	Point( -getLength(),-getHeigth(), 0, r *2		, g *2		, b), 0.0f);
	glNewList(start + 6, GL_COMPILE);
		Graphic::drawTriangle(P0, P1, P2);	
		drawBorders();
	glEndList();
	P0 = Graphic::changeHeigth(Point(-getLength()	,0, 0, r * 2, g * 2, b), 0.0f);
	P1 = Point(0,0, 0, r, g, b);
	P2 = Point(0	,-getHeigth(), 0, r, g , b);
	P3 = Graphic::changeHeigth(Point(-getLength()	,-getHeigth(), 0, r * 2, g * 2, b), 0.0f);
	glNewList(start + 7, GL_COMPILE);
		Graphic::drawQuad(P0, P1, P2, P3);	
		drawBorders();
	glEndList();

	P0 =  Graphic::changeHeigth(Point(-getLength(), 0, 0, r *2		, g *2		, b), 0.0f);
	P1 =					 	Point( 0		, 0 ,  0, r			, g			, b);
	P2 = 	Point( -getLength(),-getHeigth(), 0, r			, g			, b);
	glNewList(start + 8, GL_COMPILE);
		Graphic::drawTriangle(P0, P1, P2);
		drawBorders();
	glEndList();

	P0 = Graphic::changeHeigth(Point(-getLength()	,0, 0, r * 2, g * 2, b), 0.0f);
	P1 = Graphic::changeHeigth(Point(0,0, 0, r * 2, g * 2, b), 0.0f);
	P2 = Point(0	,-getHeigth(), 0, r, g , b);
	P3 = Point(-getLength()	,-getHeigth(), 0, r, g , b);
	glNewList(start + 9, GL_COMPILE);
		Graphic::drawQuad(P0, P1, P2, P3);
		drawBorders();
	glEndList();

	P0 =	Point(-getLength(), 0, 0, r 		, g 	, b);
	P1 =	Graphic::changeHeigth(Point( 0		, 0 ,  0, r *2		, g *2		, b), 0.0f);
	P2 =	Point( 0,-getHeigth(), 0, r			, g			, b);
	glNewList(start + 10, GL_COMPILE);
		Graphic::drawTriangle(P0, P1, P2);
		P0 =	Point(-getLength(), 0, 0, r 		, g 		, b);
		P1 =	Point( 0,-getHeigth(), 0, r			, g			, b);
		P2 =	Graphic::changeHeigth(Point( -getLength()		, -getHeigth() ,  0, r *2		, g *2		, b), 0.0f);
		Graphic::drawTriangle(P0, P1, P2);
		drawBorders();
	glEndList();

	P0 =	Point(0, 0, 0, r 		, g 	, b);
	P1 =	Graphic::changeHeigth(Point( 0	, -getHeigth() ,  0, r *2		, g *2		, b), 0.0f);
	P2 =	Point( -getLength(),-getHeigth(), 0, r			, g			, b);
	glNewList(start + 11, GL_COMPILE);
		Graphic::drawTriangle(P0, P1, P2);
		P0 =	Graphic::changeHeigth(Point(-getLength(), 0, 0, r *2		, g *2		, b),0.0f);
		P1 =	Point( 0,0, 0, r			, g			, b);
		P2 =	Point( -getLength()		, -getHeigth() ,  0, r			, g			, b);
		Graphic::drawTriangle(P0, P1, P2);
		drawBorders();
	glEndList();


	P0 = Point(-getLength()	,0, 0, r 		, g  , b);
	P1 = Graphic::changeHeigth(Point(0,0, 0, r *2		, g *2, b), 0.0f);
	P2 = Graphic::changeHeigth(Point(0	,-getHeigth(), 0, r *2		, g *2, b), 0.0f);
	P3 = Graphic::changeHeigth(Point(-getLength()	,-getHeigth(), 0, r *2		, g *2, b), 0.0f);
	glNewList(start + 12, GL_COMPILE);
		Graphic::drawTriangle(P0, P1, P3);
		Graphic::drawTriangle(P1, P2, P3);
		drawBorders();
	glEndList();

	P0 = Graphic::changeHeigth(Point(-getLength()	,0, 0, r *2		, g *2, b), 0.0f);
	P1 = Point(0,0, 0, r 	, g , b);
	P2 = Graphic::changeHeigth(Point(0	,-getHeigth(), 0, r *2		, g *2, b), 0.0f);
	P3 = Graphic::changeHeigth(Point(-getLength()	,-getHeigth(), 0, r *2		, g *2, b), 0.0f);
	glNewList(start + 13, GL_COMPILE);
		Graphic::drawTriangle(P0, P2, P3);
		Graphic::drawTriangle(P0, P1, P2);
		drawBorders();
	glEndList();

	P0 = Graphic::changeHeigth(Point(-getLength()	,0, 0, r *2		, g *2, b), 0.0f);
	P1 = Graphic::changeHeigth(Point(0,0, 0 ,r *2		, g *2, b), 0.0f);
	P2 = Point(0	,-getHeigth(), 0, r 	, g , b);
	P3 = Graphic::changeHeigth(Point(-getLength()	,-getHeigth(), 0, r *2		, g *2, b), 0.0f);
	glNewList(start + 14, GL_COMPILE);
		Graphic::drawTriangle(P0, P1, P3);
		Graphic::drawTriangle(P1, P2, P3);
		drawBorders();
	glEndList();

	P0 = Graphic::changeHeigth(Point(-getLength()	,0, 0, r *2		, g *2, b), 0.0f);
	P1 = Graphic::changeHeigth(Point(0,0, 0 ,r *2		, g *2, b), 0.0f);
	P2 = Graphic::changeHeigth(Point(0	,-getHeigth(), 0, r *2		, g *2, b), 0.0f);
	P3 = Point(-getLength()	,-getHeigth(), 0, r, g, b);
	glNewList(start + 15, GL_COMPILE);
		Graphic::drawTriangle(P0, P1, P3);
		Graphic::drawTriangle(P1, P2, P3);
		drawBorders();
	glEndList();

	P0 = Point(0					, -getHeigth(), 0, r * 2, g * 2, b);
	P1 = Point(0					, 0				  , 0, r * 2, g * 2, b);
	P2 = Point(- getLength()		, 0				  , 0, r * 2, g * 2, b);
	P3 = Point(-getLength()		, -getHeigth(), 0, r * 2, g * 2, b);
	glNewList(start + 16, GL_COMPILE);
		Graphic::drawQuad(P0, P1, P2, P3);
	glEndList();
}

void GraIngame::createDLImages() {
	
	Point P0 = Point(0.0f, 0.0f, 0, 1.0f, 1.0f, 1.0f);
	Point P1 = Point(1.0f, 0.0f, 0, 1.0f, 1.0f, 1.0f);
	Point P2 = Point(1.0f, 1.0f, 0, 1.0f, 1.0f, 1.0f);
	Point P3 = Point(0, 1.0f, 0, 1.0f, 1.0f, 1.0f);
	glNewList(18, GL_COMPILE);
		Graphic::drawLineStrip(P0, P1, P2, P3);
	glEndList();
	for (int i = 0; i < Graphic::nrTextures; i++) {
		glNewList(Graphic::texture[i].id, GL_COMPILE);
		glBindTexture(GL_TEXTURE_2D, Graphic::texture[i].texture);
		glEnable(GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		Graphic::drawQuad(	P0, P1, P2, P3);
		glDisable(GL_BLEND);
		glBindTexture(GL_TEXTURE_2D, 0);
	glEndList();
	}
	
	std::map<GameObject::gameObject_ID,GLuint>::iterator i=Graphic::gameObjectTextures.begin();
	
	while (i!=Graphic::gameObjectTextures.end()){
		glNewList((*i).first, GL_COMPILE);
		glBindTexture(GL_TEXTURE_2D, (*i).second);
		glEnable(GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		Graphic::drawQuad(	P0, P1, P2, P3);
		glDisable(GL_BLEND);
		glBindTexture(GL_TEXTURE_2D, 0);		
		glEndList();
		i++;
	}


	
}

/*void GraIngame::createDLUnits(int start) {
	Point P0 = Point(0.0f, 1.0f, 0, 1.0f, 1.0f, 1.0f);
	Point P1 = Point(1.0f, 1.0f, 0, 1.0f, 1.0f, 1.0f);
	Point P2 = Point(1.0f, 0.0f, 0, 1.0f, 1.0f, 1.0f);
	Point P3 = Point(0.0f, 0.0f, 0, 1.0f, 1.0f, 1.0f);

	glNewList(start, GL_COMPILE);
		glBindTexture(GL_TEXTURE_2D, Graphic::texture[2]);
		glEnable(GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		Graphic::drawQuad(P0, P1, P2, P3);			
		glDisable(GL_BLEND);
		glBindTexture(GL_TEXTURE_2D, 0);
	glEndList();

	

}/*
/*
 *
 * create DLs
 *
 */
void GraIngame::createDL() {
	
	GraIngame::createDLFields();
	GraIngame::createDLImages();
	//GraIngame::createDLUnits(listNr + 19);
	

}