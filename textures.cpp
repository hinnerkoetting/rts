/////////////////////////////////////////////////////////////////
//
//					
//					textures.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "gl/glut.h"
#include "graphic.h"
#include <stdio.h>   
#include <gl\glaux.h>  
#include "devil/include/IL/il.h"
#include "devil/include/IL/ilut.h"
#include "util.h"
#include "defines.h"


Tex Graphic::texture[100];
int Graphic::nrTextures = 0;

void Graphic::bindImage() {
	ILuint ImageName;
	ilGenImages(1, &ImageName);
	ilBindImage(ImageName);
}

void Graphic::loadImage(char* filename, int id) {
	if (id <= FIELD_PLAIN)
		log::log("Fehler beim Laden eines Bildes. ID ist zu klein.");
	ilLoadImage(filename);
	Graphic::texture[nrTextures].texture = ilutGLBindTexImage();
	Graphic::texture[nrTextures++].id = id;
}
