/////////////////////////////////////////////////////////////////
//
//					Graphic_prim.cpp
//					draws quads, pixel, triangles etc.
//					
//					
//
/////////////////////////////////////////////////////////////////
#include "gl/glut.h"

#include "graphic.h"

void Graphic::drawQuad(Point P0, Point P1, Point P2, Point P3) { 	
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);	
		glColor3f(P0.r, P0.g, P0.b);
		glVertex3f(P0.x, P0.y, P0.z);
		glTexCoord2f(1.0f, 0.0f);
		glColor3f(P1.r, P1.g, P1.b);
		glVertex3f(P1.x, P1.y, P1.z);
		glTexCoord2f(1.0f, 1.0f);
		glColor3f(P2.r, P2.g, P2.b);
		glVertex3f(P2.x, P2.y, P2.z);
		glTexCoord2f(0.0f, 1.0f);
		glColor3f(P3.r, P3.g, P3.b);
		glVertex3f(P3.x, P3.y, P3.z);
	glEnd();
}

/*void Graphic::drawEmptyQuad(Point P0, Point P1, Point P2, Point P3) {
	glBegin(GL_LINE_LOOP);
		glTexCoord2f(0.0f, 0.0f);	
		glColor3f(P0.r, P0.g, P0.b);
		glVertex3f(P0.x, P0.y, P0.z);
		glTexCoord2f(1.0f, 0.0f);
		glColor3f(P1.r, P1.g, P1.b);
		glVertex3f(P1.x, P1.y, P1.z);
		glTexCoord2f(1.0f, 1.0f);
		glColor3f(P2.r, P2.g, P2.b);
		glVertex3f(P2.x, P2.y, P2.z);
		glTexCoord2f(0.0f, 1.0f);
		glColor3f(P3.r, P3.g, P3.b);
		glVertex3f(P3.x, P3.y, P3.z);
	glEnd();
}*/

void Graphic::drawLineStrip(Point P0, Point P1,Point P2, Point P3) {
	glLineWidth(1.0f);
	glBegin(GL_LINE_LOOP);
		glColor3f(P0.r, P0.g, P0.b);
		glVertex3f(P0.x, P0.y, P0.z);
		glColor3f(P1.r, P1.g, P1.b);
		glVertex3f(P1.x, P1.y, P1.z);
		glColor3f(P2.r, P2.g, P2.b);
		glVertex3f(P2.x, P2.y, P2.z);
		glColor3f(P3.r, P3.g, P3.b);
		glVertex3f(P3.x, P3.y, P3.z);
	glEnd();
}
void Graphic::drawTriangle(Point P0, Point P1, Point P2) { 	
	glBegin(GL_TRIANGLES);
		glColor3f(P0.r, P0.g, P0.b);
		glVertex3f(P0.x, P0.y, P0.z);

		glColor3f(P1.r, P1.g, P1.b);
		glVertex3f(P1.x, P1.y, P1.z);

		glColor3f(P2.r, P2.g, P2.b);
		glVertex3f(P2.x, P2.y, P2.z);
	glEnd();
}

/*
 *
 * draws a line
 * NOTE: no check if visible
 */
void Graphic::drawLine2D(Point P0, Point P1) {
	glLineWidth(1.0f);
	glBegin(GL_LINES);
		glColor3f(P0.r, P0.g, P0.b);
		glVertex3f(P0.x, P0.y, P0.z);
		glColor3f(P1.r, P1.g, P1.b);
		glVertex3f(P1.x, P1.y, P1.z);
	glEnd();
}

void Graphic::drawLine3D(Point P0, Point P1) {
	glLineWidth(1.0f);
	glBegin(GL_LINES);
		glColor3f(P0.r, P0.g, P0.b);
		glVertex3f(P0.x, P0.y, P0.z);
		glColor3f(P1.r, P1.g, P1.b);
		glVertex3f(P1.x, P1.y, P1.z);
	glEnd();
}
/*
 *
 * draws a pixel in point P0 with radius fSize
 *
 */
void Graphic::drawPixel(Point P0, float fSize) {
	if (visible(P0)) {
		glPointSize (fSize);
		glBegin(GL_POINTS);
		
		glColor3f(P0.r, P0.g, P0.b);
		glVertex3f(P0.x, P0.y, P0.z);
		
		glEnd();
	}
}