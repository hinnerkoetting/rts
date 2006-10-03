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

void main(int argc, char **argv) {

	if (!Options::ReadCfg())
		if (Options::debug)
			Error::MesBoxOk("File not found.\nDefault config will be created.", "Config error");
	Graphic::init(argc, argv);
	Switch::ingame();
	glutMainLoop();
} 
