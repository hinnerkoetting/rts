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


GLuint Graphic::texture[100];
int Graphic::nrTextures = 0;

void Graphic::bindImage() {
	ILuint ImageName;
	ilGenImages(1, &ImageName);
	ilBindImage(ImageName);
}

void Graphic::loadImage(char* filename) {
	ilLoadImage(filename);
	Graphic::texture[Graphic::nrTextures++] = ilutGLBindTexImage();
}
