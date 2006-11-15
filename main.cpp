/////////////////////////////////////////////////////////////////
//
//					
//					main.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////

#include <windows.h>

#include "errors.h"

#include "errors.h"
#include "options.h"
#include "Graphic_Interface.h"
#include "gl/glut.h"
#include "modeSelection.h"
#include "Util.h"

void main(int argc, char **argv) {
	log::initLog(); //not used at the moment

	//read configuration from registry
	if (!Options::ReadCfg()){
		if (Options::debug)
			Error::MesBoxOk("File not found.\nDefault config will be created.", "Config error");
		log::log("File not found.\nDefault config will be created.");
	}

	//GLUT Init
	GraphicInterface::initGraphics(argc, argv);

	//at the moment we always start in the gamemode
	ModeSelection::gameMode();
	glutMainLoop();
} 
