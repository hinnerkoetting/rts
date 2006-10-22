/////////////////////////////////////////////////////////////////
//
//					switch.cpp
//					switches interface
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "switch.h"
#include "gl/glut.h"
#include "ingame.h"
#include "inp_ingame.h"
#include "errors.h"
#include "options.h"
#include "gra_ingame.h"
#include "devil/include/IL/il.h"
#include "devil/include/IL/ilut.h"
#include "menue.h"
#include "mainmenu.h"
/*
 *
 * switch to main menu
 *
 */
void Switch::mainMenu() {
	glutIdleFunc(Graphic::renderScene);
	glutKeyboardFunc(MainMenu::input);
	glutSpecialFunc(MainMenu::inputSp);
}

/*
 *
 * switch to menu 'new'
 *
 */
void Switch::newMenu() {
	glutIdleFunc(Graphic::renderScene);
}

/*
 *
 * switch to ingame
 *
 */

void Switch::ingame() {
	Ingame::initGame();	
	
	char c[16];
	Graphic::resolution(c);
	glutGameModeString(c);
	if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) 
		glutEnterGameMode();
	else Error::MesBoxOk("Fehler", "Falscher Grafikmodus");
	glClearColor(0.5, 0.5, 0.5, 1.0);
	
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	
	
	
	GraIngame::init();

	glShadeModel(GL_SMOOTH);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(Ingame::input);
	glutSpecialFunc(Ingame::inputSp);
	glutMouseFunc(Ingame::mouse);
	glutDisplayFunc(Ingame::draw);
	glutIdleFunc(Ingame::calc);
	glutReshapeFunc(Graphic::changeSize);
	glutPassiveMotionFunc(Ingame::mouseMove);
	glutMotionFunc(Ingame::mouseMove);
	//glEnable(GL_LIGHTING);
	//glDisable(GL_LIGHT1);
	
	
	
}