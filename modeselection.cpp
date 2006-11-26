/////////////////////////////////////////////////////////////////
//
//					switch.cpp
//					switches interface
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "modeSelection.h"
#include "gl/glut.h"
#include "gameViewAndControl.h"
#include "inp_ingame.h"
#include "errors.h"
#include "options.h"
#include "gra_ingame.h"
#include "devil/include/IL/il.h"
#include "devil/include/IL/ilut.h"
#include "menue.h"
#include "mainmenu.h"
#include "worldModel.h"
/*
 *
 * switch to main menu
 *
 */
void ModeSelection::mainMenuMode() {
	glutIdleFunc(Graphic::renderScene);
	glutKeyboardFunc(MainMenu::input);
	glutSpecialFunc(MainMenu::inputSp);
}

/*
 *
 * switch to menu 'new'
 *
 */
void ModeSelection::newMenu() {
	glutIdleFunc(Graphic::renderScene);
}

/*
 *
 * gamemode initialisation
 * assign input and output functions (mouse, keyboard, display)
 */

void ModeSelection::gameMode() {
	worldModel::initGame();	
	
	char c[16];
	Graphic::resolution(c);
	glutGameModeString(c);
	if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) 
		glutEnterGameMode();
	else {
		Error::MesBoxOk("Fehler", "Falscher Grafikmodus");
		exit(1);
	}

	glClearColor(0.5, 0.5, 0.5, 1.0);
	
	
	
	GraIngame::init();

	glShadeModel(GL_SMOOTH);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(ViewAndControl::input);
	glutSpecialFunc(ViewAndControl::inputSp);
	glutMouseFunc(ViewAndControl::mouse);
	glutDisplayFunc(ViewAndControl::draw);
	glutIdleFunc(ViewAndControl::calc);
	glutReshapeFunc(Graphic::changeSize);
	glutPassiveMotionFunc(ViewAndControl::mouseMove);
	glutMotionFunc(ViewAndControl::mouseMove);
}