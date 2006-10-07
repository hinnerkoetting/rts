/////////////////////////////////////////////////////////////////
//
//					
//					GraphicALT.cpp
//					GraphicALT functions
//					
//
/////////////////////////////////////////////////////////////////
#include "Graphic.h"
#include "options.h"
#include "gl/glut.h"
#include "ingame.h"
#include "gra_ingame.h"

float Graphic::zPos = 3.0f;

/*
 *inits Graphics
 *
 */
void Graphic::init(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(Options::ResolutionX, Options::ResolutionY);
	glutInitDisplayMode(GLUT_RGBA |GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Arkoid- Next Generation strategy gaming");
	glutDisplayFunc(Graphic::renderScene);			//MAYBE NEEDS TO BE ADDED TO SWITCH FUNCTION
	glutIdleFunc(Graphic::renderScene);
	glutReshapeFunc(Graphic::changeSize);
}

void Graphic::renderScene() {
}

/*
 *
 * when window is resized
 *
 */
void Graphic::changeSize(int w, int h) {
	if(h == 0)
		h = 1;
	float ratio = (float) w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0, 
			0.0,0.0,-3.0, 
			0.0f,1.0f,0.0f);
	
}



/*
 *
 * change to 2d and ortho view
 *
 */
void Graphic::changeTo2D() {
	glViewport(0, 0, ((float)Options::ResolutionX * GraIngame::getMenuWidth()), Options::ResolutionY);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, Options::ResolutionX, 0, Options::ResolutionY);
	glScalef(1, -1, 1);
	glTranslatef(0, -Options::ResolutionY, 0);
	glMatrixMode(GL_MODELVIEW);
}

/*
 *
 * change to 3d and normal view
 *
 */
void Graphic::changeTo3D() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, Options::ResolutionX , Options::ResolutionY);
	glScissor(Options::ResolutionX * GraIngame::getMenuWidth(), 0, Options::ResolutionX * 0.75, Options::ResolutionY);
}

void Graphic::resetColor(Point* P) {
	P->r = 0.0f;
	P->g = 0.0f;
	P->b = 0.0f;
}