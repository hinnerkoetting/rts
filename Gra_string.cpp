/////////////////////////////////////////////////////////////////
//
//					
//					gra_string.cpp	
//					draw a string
//					
//
////////////////////////////////////////////////////////////////

#include "graphic.h"
#include "gra_string.h"
#include "gl/glut.h"

void Graphic::drastring3d(float x, float y, float z, void* font, char* string) {  
  char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}
void Graphic::drastring2d(float x, float y, void *font, char *string) {  
  char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}