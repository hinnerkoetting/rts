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
#include "Graphic.h"
#include "gl/glut.h"
#include "switch.h"
#include "Util.h"

void main(int argc, char **argv) {
	log::initLog();
	if (!Options::ReadCfg())
		if (Options::debug)
			Error::MesBoxOk("File not found.\nDefault config will be created.", "Config error");
	Graphic::init(argc, argv);
	Switch::ingame();
	glutMainLoop();
} 
