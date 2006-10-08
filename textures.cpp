#include "gl/glut.h"
#include "graphic.h"
#include <stdio.h>   
#include <gl\glaux.h> // Und das Gleiche nochmal für Glaux 
#include "devil/include/IL/il.h"
#include "devil/include/IL/ilut.h"


GLuint Graphic::texture[100];
int Graphic::nrTextures = 0;
//ILuint ImageName;
void Graphic::bindImage() {
	ILuint ImageName;
	ilGenImages(1, &ImageName);
	ilBindImage(ImageName);
}

void Graphic::loadImage(char* filename) {
	ilLoadImage(filename);
	Graphic::texture[Graphic::nrTextures++] = ilutGLBindTexImage();
}
//GLuint Graphic::texture[1];
/*AUX_RGBImageRec *LoadBMP(char *Filename) {
  FILE *File=NULL; 
  if (!Filename) {
    return NULL;
  }
  File=fopen(Filename,"r"); 
  if (File) {
    fclose(File); 
    return auxDIBImageLoad(Filename); 
  }
  return NULL; 
}
int Graphic::LoadGLTextures() {
  int Status=FALSE; 
  AUX_RGBImageRec *TextureImage[1]; 
  memset(TextureImage,0,sizeof(void *)*1); 
  if (TextureImage[0]=LoadBMP("codeworx.bmp")) {
    Status=TRUE;
	glGenTextures(1, &Graphic::texture[0]);
	glBindTexture(GL_TEXTURE_2D, Graphic::texture[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, 
                 TextureImage[0]->sizeY, 0, GL_RGB, 
                 GL_UNSIGNED_BYTE, TextureImage[0]->data);
	 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  }
  if (TextureImage[0]) {
    if (TextureImage[0]->data) {
      free(TextureImage[0]->data); 
    }
    free(TextureImage[0]); 
  }
  return Status;
}*/