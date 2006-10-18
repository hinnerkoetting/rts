/////////////////////////////////////////////////////////////////
//
//					
//					gra_string.cpp	
//					draw a string
//					
//
////////////////////////////////////////////////////////////////

#include "graphic_interface.h"
#include "gl/glut.h"
#include "gra_ingame.h"
#include "options.h"


void GraphicInterface::drastring3d(float x, float y, float z, void* font, char* string) {  
  char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}
void GraphicInterface::drastring2d(float x, float y, void *font, char *string) {  
  char *c;
  glRasterPos2f(x * Options::ResolutionX/GraIngame::getMenuWidth(), y * Options::ResolutionY);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}