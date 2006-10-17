/////////////////////////////////////////////////////////////////
//
//					
//					gra_images.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////

#include "gra_ingame.h"
#include "graphic.h"
#include "devil/include/IL/ilut.h"
#include "hero.h"
#include "worker.h"
void GraIngame::loadImages() {
	ilInit();
	Graphic::bindImage();
	ilutRenderer(ILUT_OPENGL);
	Graphic::loadImage("data/att.gif");
	Graphic::loadImage("data/house.gif");
	Graphic::loadImage("data/worker2.gif");
}