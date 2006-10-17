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
#include "switch.h"
#include "Util.h"

void main(int argc, char **argv) {
	log::initLog();
	if (!Options::ReadCfg())
		if (Options::debug)
			Error::MesBoxOk("File not found.\nDefault config will be created.", "Config error");
	GraphicInterface::initGraphics(argc, argv);
	Switch::ingame();
	glutMainLoop();
} 
